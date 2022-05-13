# SysY_Compiler_Tnameplz_CX

## 目前的工作

目前我的代码是在cminus-f实验的基础上编写的(**指把每一部分都缝合到一起**)。下面介绍一下里面的一些内容

### 目录树

```
.
├── CMakeLists.txt //在 项目架构 一栏中会提到Cmake的使用方法
├── CMakePresets.json //CMake自动生成的
├── README.md // 本文件
├── include //include头文件地址 我们尽量保证.h文件用以声明 .c/.cpp文件用以实现/定义
│   ├── createTree.h
│   └── includeLex.h
├── out //out是输出文件的目录，下面的内容中会提到out目录具体怎么使用，这个目录不放到git里
│   ├── Test //二进制可执行文件
│   ├── build //构建目录 也就是CMake文件和make文件输出的地址，编译信息存在这里
│   └── lib //库文件输出的目录
│       ├── libSysY_Lex.a
│       └── libSysY_Yacc.a 
├── src //源文件目录
│   ├── CMakeLists.txt 
│   ├── SysY_Lex //词法分析模块目录 在 Bison和Lex 一栏中会提到词法分析和语法分析怎样拼接到一起
│   │   ├── CMakeLists.txt
│   │   ├── SysY_Lex.h
│   │   ├── SysY_Lex.l
│   │   └── lex.yy.c
│   ├── SysY_Yacc //语法分析所在模块
│   │   ├── CMakeLists.txt
│   │   ├── CreateTree.c
│   │   ├── SysY_Yacc.h
│   │   ├── SysY_Yacc.tab.c
│   │   ├── SysY_Yacc.tab.h
│   │   └── SysY_Yacc.y
│   └── main_test.c //main函数 现阶段main函数主要用来测试
└── test //测试文件和输出结果所在目录
    ├── test1.sy
    ├── test1_out1
    └── test1_out2
   

40 directories, 123 files
```

目录下面还有一个文件是 .editconfig是文本输入控制脚本 大家可以下个editconfig插件。注意请一定一定在Linux下面开发，**使用WSL的同志一定要注意换行是LF** 要不然编译会不通过，合并分支也会很麻烦(上学期惨痛的教训啊)

### 编译/执行方法

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
make  #这里是编译指令 使用这条指令之后就会在lib文件夹下面生成库文件(这里是静态链接库，原因会在后面 项目架构 一栏中提一嘴)

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

https://blog.csdn.net/z_ryan/article/details/80979432



## 一些注意事项

### gitlab多人开发方法

因为我也是第一次用git真正开发多人项目(之前分组作业都是个人输出)，这里有一篇博客我觉得写得还行，大家可以看一下

https://blog.csdn.net/while10/article/details/108746417

然后大家可以创建自己的分支 后面就可以进行提交之类的了

**记得把out目录下的文件加入到.gitignore**: https://blog.csdn.net/toopoo/article/details/88660806

## 现在进度

已经可以生成语法分析树了！但是目前我们的CFG还存在很大问题，包括了语法覆盖不全和移进规约冲突。这可能是我们的第一个议题，有时间我们可以一起商量一下。
