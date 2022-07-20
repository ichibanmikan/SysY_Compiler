# IR的设计

IR就是从抽象语法树到便于优化的代码

**我们的IR采用SSA的形式，参考LLVM IR，但是有很多地方做了删减。**

## 写在前面

关于IR一定要搞明白的

1. 什么是SSA 参考编译原理龙书P233 6.2三地址代码

2. LLVM IR。这个我们编译原理实验都看过也写过，就是用命令

   ```shell
   clang -S -emit-llvm main.c
   ```

   生成main.c的llvm IR

   可以参考中科大的那个实验

   <https://llvm.org/docs/LangRef.html#instruction-reference>

   这里有详细的IR资料

3. 龙书P237到最后，除了6.8 switch语句那里，尤其是**6.6控制流和6.7回填**，去年样例里考了不少代码短路的内容。这里虽然章节分的多然实际上就二十来页。6.5类型检查选看，因为我们给定的代码都是正确的，没必要类型检查。

4. Linux elf可执行文件的格式

需要查看我们的抽象语法树的结构就调用out/Test打印出来看

## 类型和局部变量

对应局部变量和全局变量的声明语句、初始化语句

### 类型

我们的IR可能遇到的有以下几种类型

```c++
enum valType{
  i1=0,
  i8=1,
  i16=2,
  i32=3,
  i1_ptr=4,
  i8_ptr=5,
  i16_ptr=6,
  i32_ptr=7,
  float=8,
  float_ptr=9
};
```

大家看llvm生成的代码中会有align 4之类的，这好像是对齐的意思，不过我们的int和float都是4字节的，我们不用管他，我们的IR中也不会有这个

### 局部常变量

不管常量还是变量，每一个都会分配空间，因此赋值都是用 alloca 类型 开辟空间，使用和赋值都是用指针类型，对应load和store指令(常量传播优化我们日后再考虑)

局部常量和变量操作一样，下面只给局部变量的方法

**AST的根结点是declarations，他下面的每一个子结点对应一个全局变量.**

全局变量的名字用@变量名表示，就比如main函数的IR名就是@main

另外函数分下面两类

- `dso_preemptable`

  运行时链接的函数，就是我们那些getint putint库函数啥的

- `dso_local`

  本地函数，就是我们自己写的函数

对于每一个局部变量

它的名字是%1 %2 ……

注意函数的参数也是局部变量

下面是部分 AST中

```shell
|  >--+ func_declaration  #func_declaration代表这是一个函数语句
|  |  >--* void           #第一个子结点是返回值类型
|  |  >--* mem_move       #第二个子结点是函数名，它在IR中的名字就应该是@mem_move
|  |  >--+ param          #第三个子结点是变量
|  |  |  >--+ param_array #第一个子结点是数组变量
|  |  |  |  >--* int      #i32* 类型的
|  |  |  |  >--* a        #%1
|  |  |  |  >--+ array_size #数组大小
|  |  |  |  |  >--* void  #未规定大小，这里不管是否规定大小都应该被剪掉，所以array_size这个地方在这里是没必要保留的
|  |  |  >--+ param       #下一个变量 i32 类型的%2
|  |  |  |  >--* int
|  |  |  |  >--* n
|  |  |  >--+ param       #下一个变量 i32 类型的%3
|  |  |  |  >--* int
|  |  |  |  >--* i
|  |  |  >--+ param       #下一个变量 i32 类型的%4
|  |  |  |  >--* float
|  |  |  |  >--* j
```

这一部分代码应该为

```shell
define dso_local void @mem_move(i32* %1, i32 %2, i32 %3, float %4)
#这里函数参数可以当作常量直接用，因此不是指针类型
```

我在生成抽象语法树的时候对常数符号有一定优化，如果读到'+'就不生成子结点。生成完所有子结点之后查看'-'的个数，如果是偶数，就直接删掉符号结点，如果是奇数也删掉符号结点，但是新增一个'-'结点

如果数值常量有正负号，它的抽象语法树是这样的

```shell
|  |  |  >--+ =
|  |  |  |  >--* ttt
|  |  |  |  >--* 5.3

ttt=--5.3 ttt=+5.3...

|  |  |  >--+ =
|  |  |  |  >--* ppp
|  |  |  |  >--+ getvalue
|  |  |  |  |  >--+ args
|  |  |  |  |  |  >--* 5

ppp=+getvlaue(5)  或者 ppp=--getvalue(5) 或者 ppp=--+--getvlaue(5)... 总之'-'的个数必须是偶数，'+'随便

|  |  |  >--+ =
|  |  |  |  >--* p
|  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  >--* -
|  |  |  |  |  >--* 6

p=-6 或者 p=--+-6... '-'的个数必须是奇数，'+'随意
```

### 数组

#### 声明

抽象语法树为

```shell
int a[2][3][4][5][6], b[7][8][9][10], c;

|  >--+ var_declaration
|  |  >--* int
|  |  >--+ idenfiers
|  |  |  >--+ a
|  |  |  |  >--+ array_size
|  |  |  |  |  >--* 2
|  |  |  |  |  >--* 3
|  |  |  |  |  >--* 4
|  |  |  |  |  >--* 5
|  |  |  |  |  >--* 6
|  |  |  >--+ b
|  |  |  |  >--+ array_size
|  |  |  |  |  >--* 7
|  |  |  |  |  >--* 8
|  |  |  |  |  >--* 9
|  |  |  |  |  >--* 10
|  |  |  >--* c

#变量声明根结点下面第一个子结点是类型，之后是声明的所有变量idenfiers结点
#idenfiers结点下面每一个子结点代表变量名，如果是普通变量，则它本身就是叶结点
#如果是数组，那他下面有一个array_size结点，该结点的子结点数目代表数组维度，每个值代表当前维度大小
```

因为我们所有变量都是放在内存中的，所以声明一个数组就会变得很容易，如

int b[5];

IR为

```ass
%1 = alloca [5 x i32]
```

就是分配一个5*i32的空间

int b\[2][3];

IR为

```assembly
%1 = alloca [2 x [3 x i32]]
```

之后都有这个公式：

type val_name [i] [j] [k] ……[n]

IR为

```assembly
%1 = alloca [i x [j x [k x […… x [n x type]]]]]
```

#### 按索引访问

我们先想一个模型，int a[2]; 那么a[1]是 int 型的，也就是i32

int a\[2][3]; 那么a可以看作int\[2][3]型的一个地址(就是说这个int型地址包含2*3个4字节的块)，a[1]可以看作int[3]型的一个地址(就是说这个int型地址包含3个4字节的块)，a\[1][1]才是指向一个int块的地址

**按照行优先的规则**，我们需要一步一步算出这个地址

> 计算得出的地址 = getelementptr 基地址是什么类型的地址, 基地址, 偏移量

中间两个类型好像重复了，我们删掉一个

举个例子，首先是

int a[2]; a[1]=3;

```assembly
%1 = alloca [2 x i32]
%2 = getelementptr [2 x i32]* %1, i32 1

;%1是[2 x i32]*类型的，所以要指定操作类型是[2 x i23]，[2 x i32]*类型的变量%1是基地址，i32类型的数1是偏移量。
;这步是计算地址的，不实际访存，只算偏移地址

store i32 3, i32* %2 ;%2可以看作i32*类型的a[1]，然后把3放进去
```

int a\[2][2]; a\[1][0]=3;

```assembly
%1 = alloca [2 x [2 x i32]]
%2 = getelementptr [2 x [2 x i32]]* %1, i32 1 ;%2是[2 x i32]类型的
%3 = getelementptr [2 x i32]* %2, i32 0 ;%3是i32* 类型的

store i32 3, i32* %3
```

### 隐式类型转换

#### 以常量形式赋值时

浮点型转整型——向下取整

int b=3.5;

IR为

```assembly
%1 = alloca i32
store i32 3, i32* %1
```

整型转浮点型——扩展为浮点

float p = 5;

IR为

```assembly
%1 = alloca float
store float 5.000000e+00, float* %1
```

#### 以变量形式赋值时

需要用到sitofp和fptosi两个指令

```c
 int b=3;
 float t=3.3;
 int k=b+t;
```

IR为

```assembly
%1 = alloca i32
%2 = alloca float
%3 = alloca i32

store i32 3, i32* %1
store float 0x400A666660000000, float* %2

%4 = load i32, i32* %1
%5 = sitofp i32 %4 to float
%6 = load float, float* %2
%7 = fadd float %5, %6
%8 = fptosi float %7 to i32
store i32 %8, i32* %3
```

### 赋值

赋值的AST是以'='为根结点的

例如下面

```shell
|  >--+ =
|  |  >--* k
|  |  >--* 1
```

注意静态单赋值形式的定义：

比如说：a=2; b=a; a=4; c=a; 这四句话，IR应该为

```assembly
store i32 2, i32* %1

%3 = load i32, i32* %1
store i32 %3, i32* %2

store i32 4, i32* %4

%6 = load i32, i32* %4
store i32 %6, i32* %5
```

有函数的时候

int a; a=func(0, 1);

```assembly
%1 = alloca i32

%2 = call i32 @func(i32 0, i32 1)
store i32 %2, i32* %1
```

### 初始化

#### 普通变量初始化

一个例子

```c
int main(){
    int a;
    int b=0;
    const int c=1;
    const int d=2;
    int p=c+d;
}
```

它的IR是这样的

```assembly
define dso_local i32 @main() #0 {
  %1 = alloca i32
  %2 = alloca i32
  %3 = alloca i32
  %4 = alloca i32
  %5 = alloca i32
  store i32 0, i32* %2
  store i32 1, i32* %3
  store i32 2, i32* %4
  store i32 3, i32* %5 #常量折叠
  ret i32 0  #如果main函数没给返回值，需要增加一条语句默认返回0
}
```

和赋值一样的

#### 数组的初始化

先看一个C程序与LLVM的IR

```c
int main(){
  int a[5]={3, 4, 5, 6, 7};
}
```

LLVM IR(去除了不必要的信息)

```assembly
@__const.main.a = private unnamed_addr constant [5 x i32] [i32 3, i32 4, i32 5, i32 6, i32 7]
; 声明了一个全局的地址，它包括初始化数组时的五个元素

define dso_local i32 @main() #0 {
  %1 = alloca [5 x i32]
  %2 = bitcast [5 x i32]* %1 to i8* ; i8*是指向一个字节的指针
  call void
    @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* bitcast ([5 x i32]* @__const.main.a to i8*), i64 20, i1 false)
  ret i32 0
}
```

llvm.memcpy函数有四个参数，依次为目的指针，源指针，长度len，易失性(我们的机器基本都是false)

就是把从源指针开始的长度为len个字节的地址拷贝给目的地址

bitcast a to b 就是把a类型，在不改变bit的情况下转换为b类型

比如 %1 = bitcast i8 5 to i16;  那么%1的值仍为5，但是从8位变到了16位

上面的操作就是开辟一块连续的内存，这部分对应elf中的静态数据节，执行的时候直接把他放到数据段，**就跟全局常量一样**，包括数组初始化时的所有元素，然后把这块内存的每个字节拷贝给数组开始的地址。

gcc操作是生成对应的指令，把每个数据一个一个move到对应的地址。可以试试用gcc编译成汇编来查看

老师说**主要考虑性能**，那么我们就按照clang的处理方式，memcpy到时候在运行时调用C库。

int c[5]={3, 4, 5, 6, 7}; IR为

```assembly
@__const.main.c = private unnamed_addr constant [5 x i32] [i32 3, i32 4, i32 5, i32 6, i32 7]

; @__const.函数名.数组名 = private unnamed_addr constant 类型 每个数据

%1 = alloca [5 x i32]
%2 = bitcast [5 x i32]* %1 to i8*
call void @memcpy(i8* %2, i8* bitcast ([5 x i32]* @__const.main.c to i8*), i32 20)

; 我们的@memcpy只保留了前三个参数
```

int c\[2][3]={{1, 2, 3}, {4, 5, 6}};

IR为

```assembly
@__const.main.c = private unnamed_addr constant [2 x [3 x i32]] [[3 x i32] [i32 1, i32 2, i32 3], [3 x i32] [i32 4, i32 5, i32 6]]

%1 = alloca [2 x [3 x i32]]
%2 = bitcast [2 x [3 x i32]]* %1 to i8*
call void @memcpy(i8* %2, i8* bitcast ([2 x [3 x i32]]* @__const.main.c to i8*), i32 24)
```

对于下面这种维度或每个维度的长度和初始元素个数匹配不起来的，**它需要把所有未知元素都赋值为0**

clang数组初始元素都是0

int c\[3][2]={{1, 2}, {}, 1}

```assembly
@__const.main.c = private unnamed_addr constant [3 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 0, i32 0], [2 x i32] [i32 1, i32 0]]

%1 = alloca [3 x [2 x i32]]
%2 = bitcast [3 x [2 x i32]]* %1 to i8*
call void @memcpy(i8* %2, i8* bitcast ([3 x [2 x i32]]* @__const.main.c to i8*), i32 24)
```

## 运算部分

### 算术运算

算数运算只能出现在{}中，他在AST中只出现在 stmts 结点下面

算术运算包括加减乘除余，按照运算先后顺序从底层到上层

加减乘除余的AST都是以对应符号为根结点的，如

```shell
|  >--+ +
|  |  >--+ getvalue
|  |  |  >--+ args
|  |  |  |  >--+ k
|  |  |  |  >--+ i
|  |  |  |  >--+ n
|  |  |  |  >--* temp
|  |  >--+ getvalue
|  |  |  >--+ args
|  |  |  |  >--+ j
|  |  |  |  >--+ k
|  |  |  |  >--+ n
|  |  |  |  >--* temp
```

这个是getvalue(temp, n, i, k)+getvalue(temp, n, k, j)

插句题外话，这下知道计算机系统课里为什么说C语言函数调用的参数是从右往左开始分配地址的了吧。

其他运算都是一样的，都是如下的格式

```shell
      运算符
      /   \
第一个数   第二个数
```

看个复杂的

```shell
|  |  |  >--+ =
|  |  |  |  >--* p
|  |  |  |  >--+ -
|  |  |  |  |  >--+ +
|  |  |  |  |  |  >--+ *
|  |  |  |  |  |  |  >--+ *
|  |  |  |  |  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  |  |  |  |  >--* -
|  |  |  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  |  |  |  |  >--* -
|  |  |  |  |  |  |  |  |  >--* 5
|  |  |  |  |  |  |  >--* 5
|  |  |  |  |  |  >--* 9
|  |  |  |  |  >--+ *
|  |  |  |  |  |  >--+ *
|  |  |  |  |  |  |  >--* 5
|  |  |  |  |  |  |  >--+ +
|  |  |  |  |  |  |  |  >--* 3
|  |  |  |  |  |  |  |  >--* 6
|  |  |  |  |  |  >--+ +
|  |  |  |  |  |  |  >--* 8
|  |  |  |  |  |  |  >--* 9


#p=-a*----++-5*5+9-5*(3+6)*(8+9);
```

IR设计

```c
int main(){
  int p;
  int q=6;
  int o=6;
  p=q+o*5; #####
  return 0;
}
```

它的IR就是

```assembly
define dso_local i32 @main(){
  %1 = alloca i32
  %2 = alloca i32
  %3 = alloca i32
  %4 = alloca i32
  store i32 0, i32* %1
  store i32 6, i32* %3
  store i32 6, i32* %4
  %5 = load i32, i32* %3
  %6 = load i32, i32* %4
  %7 = mul i32 %6, 5 #####注意这里的常量不需要类型。因为C只支持同类型运算
  %8 = add i32 %5, %7 #####
  store i32 %8, i32* %2
  ret i32 0
}
```

注意算数运算涉及到的指令有

**add fadd sub fsub div fdiv mul fmul mod fmod(div对应llvm sdiv; mod对应llvm rem)分别代表整数运算和浮点运算.**

还有大家如果查看llvm IR 会看到`nuw nsw`

**nuw和nsw分别代表No Unsigned Wrap和No Signed Wrap也就是无符号溢出和有符号溢出,我们先统一按照nsw算.**

### 逻辑运算

逻辑运算只出现在条件表达式里

```shell
|  |  >--+ &&
|  |  |  >--+ <
|  |  |  |  >--* a
|  |  |  |  >--* x
|  |  |  >--+ <
|  |  |  |  >--* a
|  |  |  |  >--* y
```

同算术运算差不多，非运算也和负号一样做了合并处理

```shell
|  |  |  |  >--+ ||
|  |  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  |  >--* !
|  |  |  |  |  |  >--* a
|  |  |  |  |  >--* b

# !!!--a||b

|  |  |  |  >--+ ||
|  |  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  |  >--* -
|  |  |  |  |  |  >--* a
|  |  |  |  |  >--* b

# !!---a||b

|  |  |  |  >--+ ||
|  |  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  |  >--* !-
|  |  |  |  |  |  >--* a
|  |  |  |  |  >--* b

# !!!---a||b

|  |  |  |  >--+ ||
|  |  |  |  |  >--* a
|  |  |  |  |  >--* b

# !!--a||b
```

下面是IR的设计

整数的比较状态

<img src="https://img-blog.csdnimg.cn/20200726145440175.png">

浮点数的比较状态，**一定要和整数区分开来**

<img src="https://img-blog.csdnimg.cn/20200726145450342.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQyNTcwNjAx,size_16,color_FFFFFF,t_70">

其中，NAN表示如果阶码全部为1，尾数非0，则表示这个值不是一个真正的值（Not A Number，NAN）。NAN又分成两类：QNAN（Quiet  NAN）和SNAN（Singaling  NAN）。QNAN与SNAN的不同之处在于，QNAN的尾数部分最高位定义为1，SNAN最高位定义为0；QNAN一般表示未定义的算术运算结果，最常见的莫过于除0运算；SNAN一般被用于标记未初始化的值，以此来捕获异常。

由于我们只考虑有符号数，所以我们的状态**只有eq ne sgt sge slt sle true false oeq ogt oge olt ole une**这几个

对于整数

!a的IR

```assembly
%3 = load i32, i32* %2
%4 = icmp ne i32 %3, 0

# %4是i1类型，表示它只有一个bit
```

a<b

```assembly
%4 = load i32, i32* %2
%5 = load i32, i32* %3
%6 = icmp slt i32 %4, %5
```

对于浮点数

f>0.3

```assembly
%4 = load float, float* %3
%5 = fcmp ogt float %4, 3.000000e-01
```

f

```assembly
%3 = load float, float* %2
%4 = fcmp une float %3, 0.000000e+00
```

f==3.0

```assembly
%3 = load float, float* %2
%4 = fcmp oeq float %3, 3.000000e+00
```

与或非运算体现在下面的短路计算中

## 控制流

我们的IR和LLVM的基本框架是一样的，对于全局量，如果不是函数，就放置到汇编的每个节，如果是函数，就把他当一个IR中的函数

函数包着基本块BasicBlock，基本块里是上面所有的以及下面一部分的基础语句。

### 全局常变量和函数

我们所要处理的所有语言包括三种全局量，全局常量，全局变量和函数。所有全局量都用@+变量名表示

#### 全局常量

全局常量是要放入汇编代码的数据区(.data)的

全局常量如

```c
const int a=1;

int main(){
...
}
```

对于a，有IR

```assembly
@a = dso_local constant i32 1

; 使用constant，指定类型和值，名称用@+变量名表示
```

对于数组

```c
const int lla[5]={3, 4, 5, 6, 7};
```

就是直接

```assembly
@lla = dso_local constant [5 x i32] [i32 3, i32 4, i32 5, i32 6, i32 7]
```

#### 全局变量

```C
int ll1;
int ll2=0;
float llf=3.5;

//假设都是全局变量
```

LLVM IR

```assembly
@ll2 = dso_local global i32 0
@llf = dso_local global float 3.500000e+00
@ll1 = common dso_local global i32 0

# 声明时都要进行初始化，如果未进行初始化就默认初始化0并加一个common
# 区别就是计算机系统课上学到的，如果被初始化就放置到数据段，否则放到BSS段
```

因为不会有错误样例，我们不管是否初始化，直接全部放到data段就可以

我们的IR

```assembly
@ll2 = dso_local global i32 0
@llf = dso_local global float 3.500000e+00
@ll1 = dso_local global i32 0
```

使用就和局部变量差不多，是

```c
ll2=3;

store i32 2, i32* @ll2
```

对于数组

```assembly
int lla[5]={3, 4, 5, 6, 7};

@lla = dso_local global [5 x i32] [i32 3, i32 4, i32 5, i32 6, i32 7]
```

#### 函数

函数包着基本块。

我们的语法中没有函数的声明，只保留函数的定义

```c
float funcf(){
  return 1.0;
}
```

AST是这样的

```shell
>--+ declarations
|  >--+ func_declaration
|  |  >--* float
|  |  >--* funcf
|  |  >--* void
|  |  >--+ stmts
|  |  |  >--+ return_stmt
|  |  |  |  >--* 1.0

# func_declaration结点下面有四个子结点，包括返回值类型，函数名，参数值(没有参数就是void)，语句
```

IR结果就是这样的

```assembly
define dso_local float @funcf(){
  ret float 1.000000e+00
}

# define dso_local 返回值类型 @函数名(参数) {}
# ret 类型 返回值
```

带参数的AST是长这样的

```c
float funcf(int a, int b){
  return 1.0;
}
```

```shell
>--+ declarations
|  >--+ func_declaration
|  |  >--* float
|  |  >--* funcf
|  |  >--+ params
|  |  |  >--+ param
|  |  |  |  >--* int
|  |  |  |  >--* a
|  |  |  >--+ param
|  |  |  |  >--* int
|  |  |  |  >--* b
|  |  >--+ stmts
|  |  |  >--+ return_stmt
|  |  |  |  >--* 1.0
```

如果有参数，那么就是params结点，下面每一个param结点作为子结点，分别包含了类型和变量名(数组和上面的变量处理方式一样)

IR为

```assembly
define dso_local float @funcf(i32 %0, i32 %1){
  %3 = alloca i32
  %4 = alloca i32
  store i32 %0, i32* %3
  store i32 %1, i32* %4
  ret float 1.000000e+00
}

# 注意函数的参数作为局部变量，然后在函数体内先对这几个局部变量分配空间
```

数组作为参数时不要把他看作数组，看作指针就好了

```c
int func(int a[2]){
    return a[0];
}

int func(int a[]){
    return a[0];
}
...
```

IR为

```assembly
define dso_local i32 @func(i32* %1){
  %2 = alloca i32*
  store i32* %1, i32** %2 ;注意要分配空间给参数
  %3 = load i32*, i32** %2
  %4 = getelementptr i32* %3, i32 0
  %5 = load i32, i32* %4
  ret i32 %5
}
```

### While

while的语法树如下

```shell
while(a==0||b==a&&b!=d){
    a=a-1;
    b=b+1;
    continue;
}



|  |  |  >--+ while_stmt
|  |  |  |  >--+ ||
|  |  |  |  |  >--+ ==
|  |  |  |  |  |  >--* a
|  |  |  |  |  |  >--* 0
|  |  |  |  |  >--+ &&
|  |  |  |  |  |  >--+ ==
|  |  |  |  |  |  |  >--* b
|  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  >--+ !=
|  |  |  |  |  |  |  >--* b
|  |  |  |  |  |  |  >--* d
|  |  |  |  >--+ stmts
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* a
|  |  |  |  |  |  >--+ -
|  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  |  >--* 1
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* b
|  |  |  |  |  |  >--+ +
|  |  |  |  |  |  |  >--* b
|  |  |  |  |  |  |  >--* 1
|  |  |  |  |  >--* continue

# while_stmt有两个子结点，一个是判断条件，参见上面的逻辑运算，另一个结点为stmts，代表循环体的内容
```

while和if都是产生基本块的。一个单条件的while语句会产生两个基本块(条件和循环体)：

<img src="https://s2.loli.net/2022/06/05/tTbpQrSmC6Kz4Xj.png">

- 一个函数由许多基本块(Basic block)组成

- 每个基本块包含：

  - 开头的标签（可省略）
  - 一系列指令（可省略）
  - **结尾是终结指令(br ret)（不能省略）**

- 一个基本块没有标签时，会自动赋给它一个标签

一个简单的例子

```c
int main(){
  int a=1;
  int b=2;
  while(a<b){
    a=a+1;
  }
  float f=5;
  return 0;
}
```

对应的IR为

```assembly
define dso_local i32 @main(){
  %1 = alloca i32
  %2 = alloca i32
  %3 = alloca i32
  %4 = alloca float
  store i32 0, i32* %1
  store i32 1, i32* %2
  store i32 2, i32* %3
  br label %5
  ; while前的基本块，这个基本块标签省略掉了
5:                                                ; preds = %9, %0
  %6 = load i32, i32* %2
  %7 = load i32, i32* %3
  %8 = icmp slt i32 %6, %7
  br i1 %8, label %9, label %12
  ; 这个基本块是while的判断条件，标签是5，用变量%5表示，终结指令是br
9:                                                ; preds = %5
  %10 = load i32, i32* %2
  %11 = add nsw i32 %10, 1
  store i32 %11, i32* %2
  br label %5
  ; 这个基本块是while的循环体，标签是9，用变量%9表示，终结指令是br
12:                                               ; preds = %5
  store float 5.000000e+00, float* %4, align 4
  ret i32 0
  ; 这个基本块是while结束后的语句，标签是12，用变量%12表示，终结指令是ret
}
```

br语句分为无条件跳转和条件跳转

C中的break和continue语句，以及循环体执行完毕后重新判断的过程包含在无条件跳转中。

条件跳转一般就是while和if的条件判断语句

例如

```assembly
%8 = icmp slt i32 %6, %7
br i1 %8, label %9, label %12

; %8为icmp比较得出的结果，逻辑运算结果都是i1类似bool类型
; br开始条件跳转，如果i1为真那么就跳转到第一个对应的标签，这里是标签9，为假就跳转到标签12
```

ret语句就是 变量 返回值

### if

if和if-else的语法树如下

```shell
if(a==b&&c==d&&!a&&e==f){
    a=a+1;
    b=c-e;
    f=f*5;
}


|  |  |  >--+ if_stmt
|  |  |  |  >--+ &&
|  |  |  |  |  >--+ &&
|  |  |  |  |  |  >--+ &&
|  |  |  |  |  |  |  >--+ ==
|  |  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  |  |  >--* b
|  |  |  |  |  |  |  >--+ ==
|  |  |  |  |  |  |  |  >--* c
|  |  |  |  |  |  |  |  >--* d
|  |  |  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  |  |  >--* !
|  |  |  |  |  |  |  >--* a
|  |  |  |  |  >--+ ==
|  |  |  |  |  |  >--* e
|  |  |  |  |  |  >--* f
|  |  |  |  >--+ stmts
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* a
|  |  |  |  |  |  >--+ +
|  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  |  >--* 1
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* b
|  |  |  |  |  |  >--+ -
|  |  |  |  |  |  |  >--* c
|  |  |  |  |  |  |  >--* e
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* f
|  |  |  |  |  |  >--+ *
|  |  |  |  |  |  |  >--* f
|  |  |  |  |  |  |  >--* 5
```

if_stmt有两个子结点，一个是条件一个是stmts操作

if-else的语法树如下

```shell
if(a==b&&c==d&&!a&&e==f){
  a=a+1;
  b=c-e;
  f=f*5;
} else {
  c=0;
}


|  |  |  >--+ if_else_stmt
|  |  |  |  >--+ &&
|  |  |  |  |  >--+ &&
|  |  |  |  |  |  >--+ &&
|  |  |  |  |  |  |  >--+ ==
|  |  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  |  |  >--* b
|  |  |  |  |  |  |  >--+ ==
|  |  |  |  |  |  |  |  >--* c
|  |  |  |  |  |  |  |  >--* d
|  |  |  |  |  |  >--+ unary_ops_factor
|  |  |  |  |  |  |  >--* !
|  |  |  |  |  |  |  >--* a
|  |  |  |  |  >--+ ==
|  |  |  |  |  |  >--* e
|  |  |  |  |  |  >--* f
|  |  |  |  >--+ stmts
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* a
|  |  |  |  |  |  >--+ +
|  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  |  >--* 1
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* b
|  |  |  |  |  |  >--+ -
|  |  |  |  |  |  |  >--* c
|  |  |  |  |  |  |  >--* e
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* f
|  |  |  |  |  |  >--+ *
|  |  |  |  |  |  |  >--* f
|  |  |  |  |  |  |  >--* 5
|  |  |  |  >--+ stmts
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* c
|  |  |  |  |  |  >--* 0
```

if_else_stmts语法树有三个子结点，分别是判断条件，if体内内容，else体内内容

单条件的if语句会产生一个基本块

<img src="https://s2.loli.net/2022/06/05/OJ7ZM49dpinVvyG.png">

```c
int main(){
  int a=5;
  if(a==4){
    a=a-1;
  }
}
```

IR为

```assembly
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 5, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = icmp eq i32 %3, 4
  br i1 %4, label %5, label %8

5:                                                ; preds = %0
  %6 = load i32, i32* %2, align 4
  %7 = add nsw i32 %6, -1
  store i32 %7, i32* %2, align 4
  br label %8

8:                                                ; preds = %5, %0
  %9 = load i32, i32* %1, align 4
  ret i32 %9
}
```

同理，单条件的if-else语句产生两个基本块

<img src="https://s2.loli.net/2022/06/05/3Llvt4Zoqc2YDsh.png">

```c
int main(){
  int a=5;
  if(a==4){
    a=a-1;
  } else {
    a=1;
  }
}
```

IR为

```assembly
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 5, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = icmp eq i32 %3, 4
  br i1 %4, label %5, label %8

5:                                                ; preds = %0
  %6 = load i32, i32* %2, align 4
  %7 = sub nsw i32 %6, 1
  store i32 %7, i32* %2, align 4
  br label %9

8:                                                ; preds = %0
  store i32 1, i32* %2, align 4
  br label %9

9:                                                ; preds = %8, %5
  %10 = load i32, i32* %1, align 4
  ret i32 %10
}

```

### 短路计算

短路计算体现在多基本块上

设Ca Cb Cc Cd都是条件语句

当if(Ca&&Cb&&Cc&&Cd)时，拆成

```c
if(Ca){
  if(Cb){
    if(Cc){
      if(Cd){
        ...
      }
    }
  }
}
```

如果时if(Ca||Cb||Cc||Cd)，就拆成如下的感觉

```c
if(Ca){
  goto aaa;
}
if(Cb){
  goto aaa;
}
if(Cc){
  goto aaa;
}
if(Cd){
  goto aaa;
}
aaa
```

举个例子

```C
int main(){
  int a=5;
  int b=3;
  float f=5.6;
  float d=6.3;
  if(a==4&&b==a||f==3.3&&d==0){
    a=a-1;
  } else {
    a=1;
  }
}
```

由于||优先级小于&&，因此条件可以写作 (a==4&&b==a) || (f==3.3&&d==0)

可以拆分为

```c
if(a==4){
  if(b==a){
    goto 1;
  }
}
if(f==3.3){
  if(d==0){
    goto 1;
  }
}
goto 2;
1:  a=a-1;
  goto 3;
2:  a=1;
  goto 3;
3: ...
```

IR为

```assembly
define dso_local i32 @main(){
  %1 = alloca i32
  %2 = alloca i32
  %3 = alloca i32
  %4 = alloca float
  %5 = alloca float
  store i32 0, i32* %1
  store i32 5, i32* %2
  store i32 3, i32* %3
  store float 0x4016666660000000, float* %4
  store float 0x4019333340000000, float* %5
  %6 = load i32, i32* %2
  %7 = icmp eq i32 %6, 4
  br i1 %7, label %8, label %12 ;满足a==4就去8；否则就去12，不再判断b==a

8:                                                ; preds = %0
  %9 = load i32, i32* %3
  %10 = load i32, i32* %2
  %11 = icmp eq i32 %9, %10
  br i1 %11, label %19, label %12 ;如果也满足b==a就去19，不再判断(f==3.3&&d==0)；否则去12

12:                                               ; preds = %8, %0
  %13 = load float, float* %4
  %15 = fcmp oeq float %13, 3.300000e+00
  br i1 %15, label %16, label %22 ;如果满足f==3.3就跳到16；否则就去22，不再判断d==0

16:                                               ; preds = %12
  %17 = load float, float* %5
  %18 = fcmp oeq float %17, 0.000000e+00
  br i1 %18, label %19, label %22 ;如果满足d==0就跳到19，不然跳到22

19:                                               ; preds = %16, %8
  %20 = load i32, i32* %2
  %21 = sub nsw i32 %20, 1
  store i32 %21, i32* %2
  br label %23 ;a=a-1

22:                                               ; preds = %16, %12
  store i32 1, i32* %2
  br label %23 ;a=1

23:                                               ; preds = %22, %19
  %24 = load i32, i32* %1
  ret i32 %24
}
```

## 实现

目前处于构想阶段

每个指令对应一个结构体类型

然后用一个通用的结构体类型，里面有两个变量，分别为void\*的地址，以及一个标识符。void\*的地址表示对应指令的结构体地址，标识符是表示这个结构体对应哪种指令

基本块用类实现

函数也用类实现，里面包着基本块

### 生成函数

第一类函数

params_gen
call_func_gen
array_offset_gen
algo_expressions_gen

第二类函数——基本块相关

if_stmt_gen
while_stmt_gen
break_stmt_gen
continue_stmt_gen
logic_expressions_gen
rtmt_stmt_gen

第三类函数——常变量相关

global_val_gen
const_val_gen
assignment_stmt_gen
var_declaration_gen
const_declartion_assignment_gen

### 索引变量号

在class Function里

local_var_index和local_var_table的联系
大约是 变量名-变量号-变量值 的关系
l_v_i是根据变量名索引得到变量号
l_v_t是根据变量号索引得到变量值
l_v_i在现阶段用不太着，但是也要填

local_var_index的详情在下一个部分

类中两个函数负责根据变量名索引变量号

```c++
int getVarNumStore(string str){
    return local_var_index[str].store_index.top();
} //根据变量名获取当前变量的内存变量的变量号

int getVarNumLoad(string str){
    return local_var_index[str].find_reg_index();
} //根据变量名获取当前变量的寄存器变量的变量号
```

对于phi我们日后再考虑吧

后续可能会进行相关优化

## 关于SSA

```cpp
//根据变量名索引出来的变量号结构如下所示

struct __local_var_index{
  int
  //栈顶元素代表当前的内存变量号
  //局部变量可以没有内存表示
  /*
    比如
      %8 = icmp ne i32 %7, 0
      br i1 %8, label %9, label %12
    %8就没有
  */
 //没有就用-1表示
 //每新store一次就要压入新的store_index
 //压入内容为local_var_table.size()
 map<int, int> reg_index;
 //key代指内存形式的变量号
 //value代指被load出来的寄存器形式的变量号

 int find_reg_index(int key){
  if(reg_index.find(key)==reg_index.end()){
    return -1;
  } else {
    return reg_index[key];
  }
 }
 //根据当前变量对应的内存值返回寄存器值，防止多次load。
 //如果得到了-1的结果，说明当前变量还未被用过，就需要新load一次
};

//所有变量的u-d链就很明确了，store_index存的是所有的d，reg_index存的是u对应的d

//根据SSA格式，每次定义一个变量，都需要重新引入一个内存格式的变量号

//比如
int b;
//在这里固定将0存入b，算作第一次定义
int a=1;
a=2;
b=a;
c=a;

//SSA IR为
%1 = alloca i32
store i32 0, i32* %1
%2 = alloca i32
store i32 1, i32* %2
    //我们分别把变量号1和2压入a和b对应的栈store_index中
    //此时，Function里的local_var_index["a"]->store_index.top()应该返回1
    //local_var_index["b"]->store_index.top()应该返回2
    //而因为还未被使用，所以find_reg_index(1)和find_reg_index(2)返回值都为-1
    //把值0赋给%1
    //把值1赋给%2
%3 = alloca i32
store i32 2, i32* %3
    //新建变量%3，将2赋值给%3
%4 = load i32, i32* %3
    //将%3加载出来到%4
%5 = alloca i32
store i32 %4, i32* %5
    //把%4赋值给b，也就是%5
```

从上面可以看出，我们把alloca和store绑定起来了。这必然会导致很多没意义的store，这好办。之后优化的时候遍历命令，发现alloca了，用is_used_var判断alloca的变量是否被使用过就行了

Function类里有这两个函数，前者增加一个内存中的变量，后者增加一个寄存器变量，返回变量号，可以直接调用。**我们选择加载为寄存器变量的那个内存变量总是栈顶变量号**，这里会不会有错误呢

```c++
    int add_new_var_store(local_var* lv, string var_name){
      local_var_table->insert(pair<int, local_var*>(local_var_table->size(), lv));
        //在变量表中增加一个变量，假如说是int a;

      if(local_var_index->find(var_name)==local_var_index->end()){
        __local_var_index lvi;
        lvi.store_index.push(local_var_table->size());
        local_var_index->insert(pair<string, __local_var_index>(var_name, lvi));
      } else {
        (*local_var_index)[var_name].store_index.push(local_var_table->size());
      }//如果说这个a被定义过了(仅声明的时候也赋值为0, 所以也算)，那就将新的变量号压栈

      (*is_used_var)[local_var_table->size()]=false;
      return local_var_table->size();
    }

    int add_new_var_load(local_var* lv, string var_name){
      int temp=(*local_var_index)[var_name].find_reg_index((*local_var_index)[var_name].store_index.top());
      if(temp!=-1){
        return temp;
      } else {
        (*is_used_var)[(*local_var_index)[var_name].store_index.top()]=true;
        local_var_table->insert(pair<int, local_var*>(local_var_table->size(), lv));
        (*local_var_index)[var_name].reg_index.insert(pair<int, int>((*local_var_index)[var_name].store_index.top(), local_var_table->size()));
        return local_var_table->size();
      }
    }
```

未能解决的问题：

<img src="https://s2.loli.net/2022/07/05/gZk5iHPr6hjqcOm.png">

if基本块对a做了重新定义，else对a也做了定义，而在b中需要考虑与区分给他赋值的a究竟是哪个a(是1还是2)。

这里在SSA中用phi函数进行区分。

问题在于我们每次定义只是重建一个内存形式的变量然后压入栈store_index，怎么表示这个b需要使用phi函数了呢？

换句话说，另一种情况：同一个基本块中

a=1;

a=2;

b=a;

这很明显b是不需要用phi的，只需要取栈顶变量号load就行，怎样修改设计使IR能区分这两种情况呢
