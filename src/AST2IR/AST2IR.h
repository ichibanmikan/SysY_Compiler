#ifndef __AST_TO_IR_
#define __AST_TO_IR_

extern "C"{
  #include "../../include/createTree.h"
}

#include "../../include/IR.h"
#include <iostream>
#include <string.h>

using std::cerr;
using std::endl;

extern syntax_tree* tree;

int types_get(char* name);
//types_get函数读入抽象树中的类型字符串比如"int"，返回enum valTypes中的值

void functions_gen(syntax_tree_node* node);
//functions_gen读取的是AST中的每个func_declaration结点
//意为生成一个函数
void params_gen(vector<valTypes>* vp, __local_var_table* lvt, syntax_tree_node* node);
//params_gen可被functions_gen调用，读入params结点
//因为函数形参也要作为局部变量
//记录参数的类型；并修改lvt表的值，更新局部变量
void basic_blocks_gen(int basic_label, vector<BasicBlock*>* vbb, __local_var_table* lvt, __local_const_var_table* lcvt, syntax_tree_node* node);
//基本块生成。他用以生成if、while、函数体中的内容
//它读入的是stmts节点，但是他本身不对stmts生成一条一条的指令，而是交由basic_cmds_gen进行处理

void basic_cmds_gen(vector<BasicBlock*>* vbb, BasicBlock* bb, __local_var_table* lvt, __local_const_var_table* lcvt, syntax_tree_node* node);
//basic_cmds_gen函数是用来分发的 就是判断每个结点该用哪个函数来生成对应的命令
//他读取的也是AST中的stmts节点，但是vbb和bb都是动态变化的，因为stmts里面会有if和while语句
//这两个语句可以生成基本块，所以每当碰到if和while语句，都要修改参数vbb和bb
//因为他们代指当前的基本块表和当前正在给哪个基本块生成IR

/*******************************************************/

void global_val_gen(syntax_tree_node* node);
//全局变量表生成，读取的是每个全局变量声明节点

void const_val_gen(syntax_tree_node* node);
//全局常量生成

void assignment_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
//赋值语句，读入的是'='结点

void var_declaration_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
//变量声明语句
//注意一个var_declaration节点下可以有多个变量 数组变量
//也要注意声明的时候顺便定义，但是可以丢给assignment_stmt_gen函数
//上面的比如int a[50]; int a, b, c=3;

void const_declartion_assignment_gen(BasicBlock* bb, __local_var_table* lvt, __local_const_var_table* lcvt, syntax_tree_node* node);
//常量生成语句
//和变量声明语句同样的注意

/*****************************************/

void if_stmt_gen(vector<BasicBlock*>* vbb, BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
void while_stmt_gen(vector<BasicBlock*>* vbb, BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
//if和while类似，下面给出if的操作，while同理
//if传入了一个基本块(bb) if首先需要往bb里增加终止语句 就是条件跳转语句(注意if和if-else有区别)
//需要注意短路运算
//增加好终止语句之后，需要再调用一次basic_block_gen函数在生成一个newBB
//如果是if-else就要调用两次basic_block_gen生成两个基本块

void break_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
//跳转，代表基本块的结束

void continue_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
//continue和return大概一样，实现的时候多考虑考虑吧

void rtmt_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
//return 语句的生成
//注意它可以作为基本块的结束语句

/*********************************************/

void call_func_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node);
//函数调用语句

void array_offset_gen(syntax_tree_node* node);
//数组偏移函数，也就是getelementptr指令的生成

void logic_expressions_gen(vector<command*>* vcmd, __local_var_table* lvt, syntax_tree_node* node);
//逻辑运算函数 读入的是逻辑运算符

void algo_expressions_gen(vector<command*>* vcmd, __local_var_table* lvt, syntax_tree_node* node);
//算数运算函数 读入的是几个运算符
//两个运算函数要考虑

void AST2IR(syntax_tree* tree);

#endif
