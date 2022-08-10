#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/includeLex.h"
#include "./AST2IR/AST2IR.h"
#include "../Backend/IR2ASM.h"

#ifndef __cplusplus

extern "C"{

#endif

  #include "../include/createTree.h"

#ifndef __cplusplus

}

#endif

// struct Token_Node;

// extern是全局的意思 以extern int a为例，就是说这个变量a是全局变量并且在其他地方被声明过了
extern FILE* yyin; //声明yyin yyin就是yacc的输入方式 它默认是从文件读入的所以我们声明为*FILE类型
extern FILE* yyout; //同上

#ifndef __cplusplus

extern "C"{

#endif

  extern syntax_tree *parse(); //这个函数就是执行语法分析的函数 它不仅调用了yyparse() 还完成了一些提前声明 具体细节后面会提到

#ifndef __cplusplus

}

#endif
map<string, global_var*> global_var_table;//全局变量表
map<string, const_var*> const_var_table;//全局常量表
map<string, Function*> functions_table; //函数表，这里实在想不出来表示方法了

syntax_tree *tree = NULL; //语法分析树的根节点 抽象的代指这棵树

// void testPrint(){
//   Function* f1=new Function;
//   Function* f2=new Function;
//   BasicBlock* b1=new BasicBlock;
//   BasicBlock* b2=new BasicBlock(1);
//   BasicBlock* b3=new BasicBlock(2);
//   BasicBlock* b4=new BasicBlock(3);
//   f1->basic_blocks->push_back(b1);
//   f1->basic_blocks->push_back(b2);
//   f1->basic_blocks->push_back(b3);
//   f2->basic_blocks->push_back(b4);

//   alloca_cmd* ac1=new alloca_cmd;
//   ac1->dst_val=1;
//   ac1->align_len=4;
//   type* t1=new type(i32);
//   ac1->alloca_type=*t1;
//   command* cac1=new command;

//   cac1->cmd_ptr=(void*)ac1;
//   cac1->cmd_type=alloca_c;

//   store_cmd* sc1=new store_cmd;
//   sc1->dst_type=float_type;
//   sc1->src_type=float_ptr;
//   sc1->is_glo_val=false;
//   sc1->is_val=false;
//   sc1->dst_val=1;
//   sc1->src_val=(float)2.3;
//   command* csc2=new command;

//   csc2->cmd_ptr=(void*) sc1;
//   csc2->cmd_type=store;

//   load_cmd* lc1=new load_cmd;
//   lc1->dst_type=i32;
//   lc1->dst_val=2;
//   lc1->is_glo_val=true;
//   lc1->src_type=i32_ptr;
//   lc1->src_val="int_a";

//   command* clc3=new command;
//   clc3->cmd_ptr=(void*)lc1;
//   clc3->cmd_type=load;

//   b1->cmds->push_back(cac1);
//   b1->cmds->push_back(csc2);
//   b3->cmds->push_back(clc3);
//   functions_table.insert(pair<string, Function*>("func1", f1));
//   functions_table.insert(pair<string, Function*>("func2", f2));
//   printHelp();
// }

std::ofstream outfile;

int main(int argc, char *argv[]){
    const char *input_path = NULL; //输入路径
    string output_path;
    if (argc >= 7) {
      printf("%s\n", "errorororor");
    } //如果输入对象数目大于3就报错errorororor(报错内容没有含义……)
    if (argc == 6) {
        input_path = argv[4];
        output_path = argv[3];
    }//把input_path赋值为命令行传入的参数
    if (input_path != NULL) {
        if (!(yyin = fopen(input_path, "r"))) {
            fprintf(stderr, "[ERR] Open input file %s failed.\n", input_path);
            exit(1);
        } //这里有BUG 大家在执行的时候可以注意点这里
    } else {
        yyin = stdin;
    } //就是说如果没有传入参数的时候，也就是未指定测试文件路径，我们把 yyin 也就是yacc的输入方式改变为命令行
    outfile.open(output_path);
    tree = parse(); //建树的函数
    AST2IR(tree);
    // print_syntax_tree(stdout, tree); //把这棵树打印出来 主要是用来测试的
    del_syntax_tree(tree);
    IR2ASM();
    // printHelp();
    // AST2IR(tree);
    // testPrint();
    // del_syntax_tree(tree); //删除这棵树 主要操作就是new之后delete了(不过我倒是觉得没啥必要了因为下一步就return 0了)
    return 0;
}
//关于main函数的参数传入在Readme.md里有进一步说明
