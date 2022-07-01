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

  params_gen(func_ptr, node->children[2]);

  basic_blocks_gen(func_ptr, node->children[3]);

  functions_table.insert(pair<string, Function*>(node->children[1]->name, func_ptr));
}

void basic_blocks_gen
(Function* func, syntax_tree_node* node){
  BasicBlock* thisBB=new BasicBlock;
  func->basic_blocks->push_back(thisBB);
  thisBB->block_label=func->local_var_table->size();
  basic_cmds_gen(func, thisBB, node); //读入的是{...}，node就是AST中的stmts
} //basic_block_gen和basic_cmds_gen读取到的都是stmts结点

void basic_cmds_gen
(Function* func, BasicBlock* bb, syntax_tree_node* node){
  for(int i=0; i<node->children_num; i++){
    if(!strcmp(node->children[i]->name, "if_stmt")){
      if_stmt_gen(func, bb, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "while_stmt")){
      while_stmt_gen(func, bb, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "return_stmt")) {
      rtmt_stmt_gen(func, bb, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "=")){
      assignment_stmt_gen(func, bb, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "var_declaration")){
      var_declaration_gen(func, bb, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "const_declartion_assignment")){
      const_declartion_assignment_gen(func, bb, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "break")){
      break_stmt_gen(func, bb, node->children[i]);
    } else if(!strcmp(node->children[i]->name, "continue")){
      continue_stmt_gen(func, bb, node->children[i]);
    } else {
      call_func_gen(func, bb, node->children[i]);
    }
  }
}

string getTypeStr(int val_type){
  switch (val_type){
    case 0:
      return "void";
    case 1:
      return "i1";
    case 2:
      return "i8";
    case 3:
      return "i16";
    case 4:
      return "i32";
    case 5:
      return "i1*";
    case 6:
      return "i8*";
    case 7:
      return "i16*";
    case 8:
      return "i32*";
    case 9:
      return "float";
    case 10:
      return "float*";
    default:
      cerr << "type print error !!!" << endl;
      return "error";
  }
}

string getCompStateStr(int compState){
  switch(compState){
    case 0:
      return "eq";
    case 1:
      return "ne";
    case 2:
      return "sgt";
    case 3:
      return "sge";
    case 4:
      return "slt";
    case 5:
      return "sle";
    case 6:
      return "true";
    case 7:
      return "false";
    case 8:
      return "oeq";
    case 9:
      return "ogt";
    case 10:
      return "oge";
    case 11:
      return "olt";
    case 12:
      return "ole";
    case 13:
      return "une";
    default:
      cerr << "compare state print error !!!" << endl;
      return "error";
  }
}

void value_printHelp(value v){
  if(get_if<0>(&v)){
    cout << get<0>(v);
  }
  if(get_if<1>(&v)){
    cout << get<1>(v);
  }
  if(get_if<2>(&v)){
    cout << get<2>(v);
  }
}

void params_gen(Function* func, syntax_tree_node* node){
  return ;
}

void global_val_gen(syntax_tree_node* node){
  return ;
};

void const_val_gen(syntax_tree_node* node){
  return ;
};

void if_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};
void while_stmt_gen
(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};

void rtmt_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};
void call_func_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};
void break_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};
void assignment_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};
void var_declaration_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};
void const_declartion_assignment_gen
(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};

void continue_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};

void array_offset_gen(syntax_tree_node* node){
  return ;
};
void logic_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node){
  return ;
};
void algo_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node){
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
