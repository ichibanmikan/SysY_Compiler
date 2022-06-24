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

  basic_blocks_gen(func_ptr->local_var_table->size(), func_ptr->basic_blocks, func_ptr->local_var_table, func_ptr->local_const_var_table, node->children[3]);

  functions_table.insert(pair<string, Function*>(node->children[1]->name, func_ptr));
}

void basic_blocks_gen
(int basic_label, vector<BasicBlock*>* vbb, __local_var_table* lvt, __local_const_var_table* lcvt, syntax_tree_node* node){
  BasicBlock* thisBB=new BasicBlock;
  vbb->push_back(thisBB);
  thisBB->block_label=basic_label;
  basic_cmds_gen(vbb, thisBB, lvt, lcvt, node); //读入的是{...}，node就是AST中的stmts
} //basic_block_gen和basic_cmds_gen读取到的都是stmts结点

void basic_cmds_gen
(vector<BasicBlock*>* vbb, BasicBlock* bb, __local_var_table* lvt, __local_const_var_table* lcvt, syntax_tree_node* node){
  for(int i=0; i<node->children_num; i++){
    if(!strcmp(node->children[i]->name, "if_stmt")){
      if_stmt_gen(vbb, bb, lvt, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "while_stmt")){
      while_stmt_gen(vbb, bb, lvt, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "return_stmt")) {
      rtmt_stmt_gen(bb, lvt, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "=")){
      assignment_stmt_gen(bb, lvt, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "var_declaration")){
      var_declaration_gen(bb, lvt, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "const_declartion_assignment")){
      const_declartion_assignment_gen(bb, lvt, lcvt, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "break")){
      break_stmt_gen(bb, lvt, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "continue")){
      continue_stmt_gen(bb, lvt, node->children[i]);
    } else {
      call_func_gen(bb, lvt, node->children[i]);
    }
  }
}

void params_gen(vector<valTypes>* vp, __local_var_table* lvt, syntax_tree_node* node){
  return ;
}

void global_val_gen(syntax_tree_node* node){
  return ;
};

void const_val_gen(syntax_tree_node* node){
  return ;
};

void if_stmt_gen(vector<BasicBlock*>* vbb, BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};
void while_stmt_gen
(vector<BasicBlock*>* vbb, BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};

void rtmt_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};
void call_func_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};
void break_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};
void assignment_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};
void var_declaration_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};
void const_declartion_assignment_gen
(BasicBlock* bb, __local_var_table* lvt, __local_const_var_table* lcvt, syntax_tree_node* node){
  return ;
};

void continue_stmt_gen(BasicBlock* bb, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};

void array_offset_gen(syntax_tree_node* node){
  return ;
};
void logic_expressions_gen(vector<command*>* vcmd, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};
void algo_expressions_gen(vector<command*>* vcmd, __local_var_table* lvt, syntax_tree_node* node){
  return ;
};

void AST2IR(syntax_tree* tree){
  for(int i=0; i<tree->root->children_num; i++){
    if(!strcmp(tree->root->children[i]->name, "const_declartion_assignment")){
      const_val_gen(tree->root->children[i]);
    } else if (!strcmp(tree->root->children[i]->name, "var_declaration")){
      global_val_gen(tree->root->children[i]);
    } else if (!strcmp(tree->root->children[i]->name, "func_declaration")){
      functions_gen(tree->root->children[i]);
    } else {
      cerr << "command error !!!" << endl;
    }
  }
  return;
}
