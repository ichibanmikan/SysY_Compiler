#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/includeLex.h"

extern "C"{
  #include "../include/createTree.h"
}

// struct Token_Node;

// extern是全局的意思 以extern int a为例，就是说这个变量a是全局变量并且在其他地方被声明过了
extern FILE* yyin; //声明yyin yyin就是yacc的输入方式 它默认是从文件读入的所以我们声明为*FILE类型
extern FILE* yyout; //同上

extern "C"{
  extern syntax_tree *parse(); //这个函数就是执行语法分析的函数 它不仅调用了yyparse() 还完成了一些提前声明 具体细节后面会提到
}

syntax_tree *tree = NULL; //语法分析树的根节点 抽象的代指这棵树

int main(int argc, char *argv[]){
    const char *input_path = NULL; //输入路径
    if (argc >= 3) {
      printf("%s\n", "errorororor");
    } //如果输入对象数目大于3就报错errorororor(报错内容没有含义……)
    if (argc == 2) {
        input_path = argv[1];
    }//把input_path赋值为命令行传入的参数
    if (input_path != NULL) {
        if (!(yyin = fopen(input_path, "r"))) {
            fprintf(stderr, "[ERR] Open input file %s failed.\n", input_path);
            exit(1);
        } //这里有BUG 大家在执行的时候可以注意点这里
    } else {
        yyin = stdin;
    } //就是说如果没有传入参数的时候，也就是未指定测试文件路径，我们把 yyin 也就是yacc的输入方式改变为命令行
    tree = parse(); //建树的函数
    print_syntax_tree(stdout, tree); //把这棵树打印出来 主要是用来测试的
    del_syntax_tree(tree); //删除这棵树 主要操作就是new之后delete了(不过我倒是觉得没啥必要了因为下一步就return 0了)
    return 0;
}
//关于main函数的参数传入在Readme.md里有进一步说明
