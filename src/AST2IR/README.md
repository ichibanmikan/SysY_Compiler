# IR的设计

IR就是从抽象语法树到便于优化的代码

**我们的IR采用SSA的形式，参考LLVM IR**

## 写在前面

关于IR一定要搞明白的

1. 什么是SSA 参考编译原理龙书P233 6.2三地址代码

2. LLVM IR。这个我们编译原理实验都看过也写过，就是用命令

   ```shell
   clang -S -emit-llvm main.c
   ```

   生成main.c的llvm IR

   可以参考中科大的那个实验

   https://llvm.org/docs/LangRef.html#instruction-reference

   这里有详细的IR资料

3. 龙书P237到最后，除了6.8 switch语句那里，尤其是**6.6控制流和6.7回填**，去年样例里考了不少代码短路的内容。这里虽然章节分的多然实际上就二十来页。6.5类型检查选看，因为我们给定的代码都是正确的，没必要类型检查。

我们的抽象语法树的结构用到了就调用out/Test打印出来看

## 类型 常变量 赋值 初始化

对应局部变量和全局变量的声明语句、初始化语句

### 类型

我们的IR有5种类型，分别是void i32 float i32* float*

这四个就是对应空 int float int指针 float指针

大家看llvm生成的代码中会有align 4之类的，这好像是对齐的意思，不过我们的int和float都是4字节的，我们不用管他，我们的IR中也不会有这个

### 常变量

不管常量还是变量，每一个都会分配空间，因此赋值都是用 alloca 类型 开辟空间，使用和赋值都是用指针类型，对应load和store指令(常量传播优化我们日后再考虑)

常量和变量操作一样，下面只给变量的方法

**AST的根结点是declarations，他下面的每一个子结点对应一个全局变量**

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

```
|  >--+ func_declaration  #func_declaration代表这是一个函数语句
|  |  >--* void           #第一个子结点是返回值类型
|  |  >--* mem_move	      #第二个子结点是函数名，它在IR中的名字就应该是@mem_move
|  |  >--+ params		  #第三个子结点是变量
|  |  |  >--+ param_array #第一个子结点是数组变量
|  |  |  |  >--* int      #i32* 类型的
|  |  |  |  >--* a        #%1
|  |  |  |  >--+ array_size #数组大小
|  |  |  |  |  >--* void  #未规定大小，这里不管是否规定大小都应该被剪掉，所以array_size这个地方在这里是没必要保留的
|  |  |  >--+ param       #下一个变量 i32 类型的%2
|  |  |  |  >--* int      
|  |  |  |  >--* n
|  |  |  >--+ param		  #下一个变量 i32 类型的%3
|  |  |  |  >--* int
|  |  |  |  >--* i
|  |  |  >--+ param		  #下一个变量 i32 类型的%4
|  |  |  |  >--* float
|  |  |  |  >--* j
```

这一部分代码应该为

```
define dso_local void @mem_move(i32* %1, i32 %2, i32 %3, float %4)
#这里函数参数可以当作常量直接用，因此不是指针类型
```

### 赋值

注意静态单赋值形式的定义：

比如说：a=2; b=a; a=4; c=a; 这四句话，IR应该为

```
store i32 2, i32* %1

%3 = load i32, i32* %1
store i32 %3, i32* %2

store i32 4, i32* %4

%6 = load i32, i32* %4
store i32 %6, i32* %5
```

int a; a=func(0, 1);

```
%1 = alloca i32

%2 = call i32 @func(i32 0, i32 1)
store i32 %2, i32* %1
```

### 初始化

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
  store i32 3, i32* %5
  ret i32 0
}
```

和赋值一样的