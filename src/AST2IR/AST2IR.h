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

int types_get(char* name); //这个函数读入抽象树中的类型字符串比如"int"，返回enum valTypes中的值

void functions_gen(syntax_tree_node* node);
void params_gen(vector<valTypes>* vp, __local_var_table* lvt, syntax_tree_node* node);

void global_val_gen(syntax_tree_node* node);

void basic_blocks_gen(vector<BasicBlock>* vbb, __local_var_table* lvt, syntax_tree_node* node);

void if_bb_gen(syntax_tree_node* node);
void while_bb_gen(syntax_tree_node* node);

void array_offset_gen(syntax_tree_node* node);

void logic_expressions_gen(syntax_tree_node* node);

void equal_expressions_gen(syntax_tree_node* node);

void call_func_gen(syntax_tree_node* node);
#endif
