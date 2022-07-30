# SysY_Compiler_Tnameplz_CX
## 目前的工作

目前我的代码是在cminus-f实验的基础上编写的(**指把每一部分都缝合到一起**)。下面介绍一下里面的一些内容

### 目录树

```shell
.
├── CMakeLists.txt //在 项目架构 链接方式一栏中会提到Cmake的使用方法
├── CMakePresets.json //CMake自动生成的
├── README.md // 本文件
├── include //include头文件地址 我们尽量保证.h文件用以声明/定义 .c/.cpp文件用以实现
│   ├── createTree.h
│   └── includeLex.h
├── out //out是输出文件的目录，下面的内容中会提到out目录具体怎么使用，这个目录不放到git里
│   ├── Test //二进制可执行文件
│   ├── build //构建目录 也就是CMake文件和make文件输出的地址，编译信息存在这里
│   └── lib //库文件输出的目录
│       ├── libSysY_Lex.a
│       └── libSysY_Yacc.a
├── src //源文件目录
│   ├── CMakeLists.txt
│   ├── SysY_Lex //词法分析模块目录 在 Bison和Lex 一栏中会提到词法分析和语法分析怎样拼接到一起
│   │   ├── CMakeLists.txt
│   │   ├── SysY_Lex.h
│   │   ├── SysY_Lex.l
│   │   └── lex.yy.c
│   ├── SysY_Yacc //语法分析所在模块
│   │   ├── CMakeLists.txt
│   │   ├── CreateTree.c
│   │   ├── SysY_Yacc.h
│   │   ├── SysY_Yacc.tab.c
│   │   ├── SysY_Yacc.tab.h
│   │   └── SysY_Yacc.y
│   └── main_test.c //main函数 现阶段main函数主要用来测试
└── test //测试文件和输出结果所在目录
    ├── test1.sy
    ├── test1_out1
    └── test1_out2


40 directories, 123 files
```

目录下面还有一个文件是 .editconfig是文本输入控制脚本 大家可以下个editconfig插件。注意请一定一定在Linux下面开发，**使用WSL的同志一定要注意换行是LF** 要不然编译会不通过，合并分支也会很麻烦(上学期惨痛的教训啊)

### 编译/执行方法

#### 编译器版本

这是大赛官网给的C/C++编译器版本要求，大赛还明确要求不能使用gcc LLVM等第三方工具。也就是说我们必须跟gcc g++说拜拜了

<img src="https://s2.loli.net/2022/05/16/zKoQ8piPRhjfXM5.png">

不过clang clang++和gcc/g++区别不很大，可以放心用

我的Linux发行版本是Ubuntu20.04 64位

使用以下命令

```shell
sudo apt-get install clang
```

下载得到的版本是

```shell
clang version 10.0.0-4ubuntu1
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

所以我们要编译本项目要先下好clang-10

#### 编译方法

使用下面的命令编译本文件

不要直接复制粘贴(**因为有注释在里面**)

```shell
cd SysY_Compiler
mkdir out

cd out
mkdir lib
mkdir build

cd build
cmake ../../  #这里是用cmake构建make文件
make  #这里是编译指令 使用这条指令之后就会在lib文件夹下面生成库文件(这里是静态链接库，原因会在后面 链接方式 一栏中提一嘴)

#这个时候就会在../../目录下面生成一个可执行文件 再去执行它就好了
```

#### 执行方法

main函数我写好了注释了，大家可以去看看

执行命令是

```shell
cd SysY_Compiler
cd out

./Test ../test/test1.sy
```

项目的main函数是这样的

```c
int main(int argc, char *argv[])
```

argc是自动计数的，我们不用管

我们的命令是./Test 这个没啥好说的 就是执行Test

后面的内容是输入的路径 如果我们输入了一个路径比如../test/test1.sy，就指得是我们的main函数要处理的文件是../test目录下的test1.sy。这时候argc=2 argv[0]=./out, argv[1]="../test/test1.sy"

详细的main函数传参说明在下面

参数说明：

第一个参数argc表示的是传入参数的个数
第二个参数char* argv[]，是字符串数组，用来存放指向的字符串参数的指针数组，每一个元素指向一个参数。各成员含义如下：

argv[0]：指向程序运行的全路径名

argv[1]：指向执行程序名后的第一个字符串 ，表示真正传入的第一个参数

argv[2]：指向执行程序名后的第二个字符串 ，表示传入的第二个参数

　　……

argv[n]：指向执行程序名后的第n个字符串 ，表示传入的第n个参数
　　
规定：argv[argc]为NULL ，表示参数的结尾。

这篇博客有更详细的解释 感兴趣的可以参考这个

<https://blog.csdn.net/z_ryan/article/details/80979432>

#### 测试脚本

请在主目录或`out`,`test`下运行脚本。
使用方法：

```SHELL
python3 test.py
```

默认执行`./out/`下的唯一可执行文件，测试`test`下以`.sy`结尾的所有测试文件。
脚本参数如下：

```SHELL
usage: test.py [-h] [-e OUTFILE] [-s SYFILES] [-y] [-p]

optional arguments:
  -h, --help            show this help message and exit
  -e OUTFILE, --outfile OUTFILE
                        The Executable for testing (default: ./out/)
  -s SYFILES, --syfiles SYFILES
                        Test cases for testing (default: ./test/)
  -y, --onlysy          Consider only test files ending in sy (default：True)
  -p, --print_stdout    Print standard output (default：False)
  -l, --error_log       Print error log (default：False)
```

脚本会自动判断参数是文件名还是路径名，使用相对`./`的路径。
e.g.

```bash
#./out/
python3 ../test/test.py
#./test/
python3 test.py -s ./test/functional/ -l
#./
python3 ./test/test.py -s ./test/performance -l
```

目前是**强制-l**，目的是将有错误的文件打印到error.log中

## 一些注意事项

### gitlab多人开发方法

因为我也是第一次用git真正开发多人项目(之前分组作业都是个人输出)，这里有一篇博客我觉得写得还行，大家可以看一下

<https://blog.csdn.net/while10/article/details/108746417>

然后大家可以创建自己的分支 后面就可以进行提交之类的了

**记得把out目录下的文件加入到.gitignore**: <https://blog.csdn.net/toopoo/article/details/88660806>

### 链接方式(make/CMake)

反正测评机的编译方式就是遍历根目录下的所有.c .cc .cpp文件，然后编译每一个文件再全部静态链接起来, 之后遍历寻找.h .hpp等文件，全部作为头文件引入

类似于指令

```shell
gcc -i a.h b.h c.h…… -L 1.c 2.c 3.c
```

所以这给我们架构项目省了不少事

**这里可以去看看CSAPP第七章 链接那个部分，我觉得这里写的挺好的.**

我们的Cmake就是这么做的

每一个模块(拿词法分析的SysY_Lex模块举例子)

它的CMakeLists.txt只有四行

```makefile
cmake_minimum_required (VERSION 3.8) #指定最小的CMake版本 大家版本对不上的自行修改

aux_source_directory(. DIR_LIB_SRCS) #将指定目录下的所有源文件(.c .cpp)全都记录下来，记录到变量 DIR_LIB_SRCS 中

add_library(SysY_Lex ${DIR_LIB_SRCS}) #编译变量DIR_LIB_SRCS中所有源文件,增加到模块SysY_Lex中使SysY_Lex可以作为一个库
                                      #如果上面不用aux_source_directory，这里也可以改成
                                      #add_library(SysY_Lex lex.yy.c}

target_include_directories(SysY_Lex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#CMAKE_CURRENT_SOURCE_DIR 是保留字(就可以把它看成关键字) 他表示当前项目的根地址。因为我们编译的时候cmake指令处理的是最外层的cmake文件，所以这个文件就是最外层的目录
#这个指令指的是将当前模块作为一个库链接起来，外层的cmake就会把所有模块(SysY_Lex SysY_Yacc之类的)全都链接起来
```

有了CMake管理工具，我们分模块进行协同开发的时候就方便多了

大家开发自己的模块的时候就可以把上面的四句话复制过去，**需要改第三行 第四行中的模块名。**

CMake是很常见的工具，网上相关教程特别多，我一般都是用到啥就去搜啥。**另外，我觉得CMake太好用辣！！！**

### 有关整数的处理部分

要求实现识别和处理八进制 十进制 十六进制

我的处理方法是：在词法分析部分把八进制 十六进制数全部转为十进制整数

**因此我们中后端的处理中，所有数据都是十进制的.**

C的整数处理部分在这里 <http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf> 54页

本项目只考虑前缀，因此对应的正则表达式就是

```sh
(\-|\+)?0[0-7]*              #八进制
(\-|\+)?[1-9][0-9]*          #十进制
(\-|\+)?0(x|X)[0-9a-fA-F]+   #十六进制
```

然后下面这几个函数完成了从对应进制转到十进制 (0放到了8进制里面，反正不管怎么转它都是0)

```c
int HextoDec(char *str)    //16进制字符串转为10进制数
int OcttoDec(char* text)   //16进制字符串转为10进制数
const char* InttoString(int num)  //把10进制数转为字符串常量
void setNewChar(char* ch, char* p) //深拷贝字符
```

对于整数的符号问题

<img src="https://s2.loli.net/2022/05/20/lUFdyE367Te1Pit.png">

负数保留了符号，正数直接把加号去了当正数

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*下面是一个有趣的情况\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

setNewChar函数的由来挺曲折的, 本来我的写法是这样的

```c
char * b = yytext;
HextoDec(b);
```

但是这样的结果就是b和yytext指向同一个地址,HextoDec函数运行时处理b的时候对同样的地址中的值进行了改变, 就相当于yytext改变了,Lex在处理完这个16进制数的时候又把改变过的的yytext处理了一遍

代码简单的时候这个错误很容易发现,但是项目大起来这种不会报错甚至警告的小问题就是致命的...所以大家写代码的时候一定要小心点.

## 现在进度

我们有抽象语法树了！！！

**中端部分.**

IR设计在../src/AST2IR中有说明

Copyright © 湖南大学 请问可以帮忙想个队名吗 SysY语言编译器项目
>>>>>>> 5c42fb890465f0b177c04237a3ce7fcd491e9dda
