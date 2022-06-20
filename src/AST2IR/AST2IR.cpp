#include "AST2IR.h"

int types_get(char* name){
  if(!strcmp(name, "void")){
    return 0;
  }
  if(!strcmp(name, "int")){
    return 4;
  }
  if(!strcmp(name, "float")){
    return 9;
  }
  // system("pause");
  cerr << "type error !!!" << endl;
  return -1;
}

void functions_gen(syntax_tree_node* node){
  Function* func_ptr=new Function;
  func_ptr->ret_type=types_get(node->children[0]->name);

  params_gen(func_ptr->func_params, func_ptr->local_var_table, node->children[2]);

  basic_blocks_gen(func_ptr->basic_blocks, func_ptr->local_var_table, node->children[3]);

  functions_table.insert(pair<string, Function*>(node->children[1]->name, func_ptr));
}
