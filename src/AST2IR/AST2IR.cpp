#include "AST2IR.h"

void Function::printHelp(){
  for(int i=0; i<basic_blocks->size(); i++){
    cout << (*basic_blocks)[i]->block_label << ':' << endl;
    (*basic_blocks)[i]->printHelp();
  }
}

void printHelp(){
  for(map<string, global_var*>::iterator iter=global_var_table.begin(); iter!=global_var_table.end(); iter++){
    cout << '@' << iter->first << " = " << "dso_local global ";
    iter->second->printHelp();
    cout << endl;
  }

  for(map<string, Function*>::iterator iter=functions_table.begin(); iter!=functions_table.end(); iter++){
    string ret_type_str=getTypeStr(iter->second->ret_type);
    cout << "define dso_local " << ret_type_str << '@' << iter->first << " () #0" << '{' << endl;
    iter->second->printHelp();
    cout << '}' << endl;
  }
}

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

void cmd_printHelp(command* cmd){
  switch(cmd->cmd_type){
    case 0:{
      struct alloca_cmd* ac=new struct alloca_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct alloca_cmd*)vac, sizeof(alloca_cmd));
      ac->printHelp();
      break;
    }
    case 1:{
      struct store_cmd* sc=new struct store_cmd;
      void* vsc=cmd->cmd_ptr;
      memcpy(sc, (struct store_cmd*)vsc, sizeof(store_cmd));
      sc->printHelp();
      break;
    }
    case 2:{
      struct load_cmd* ac=new struct load_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct load_cmd*)vac, sizeof(load_cmd));
      ac->printHelp();
      break;
    }
    case 3:{
      struct getelementptr_cmd* ac=new struct getelementptr_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct getelementptr_cmd*)vac, sizeof(getelementptr_cmd));
      ac->printHelp();
      break;
    }
    case 4:{
      struct bitcast_cmd* ac=new struct bitcast_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct bitcast_cmd*)vac, sizeof(bitcast_cmd));
      ac->printHelp();
      break;
    }
    case 5:{
      struct add_cmd* ac=new struct add_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct add_cmd*)vac, sizeof(add_cmd));
      ac->printHelp();
      break;
    }
    case 6:{
      struct fadd_cmd* ac=new struct fadd_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct fadd_cmd*)vac, sizeof(fadd_cmd));
      ac->printHelp();
      break;
    }
    case 7:{
      struct sub_cmd* ac=new struct sub_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct sub_cmd*)vac, sizeof(sub_cmd));
      ac->printHelp();
      break;
    }
    case 8:{
      struct fsub_cmd* ac=new struct fsub_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct fsub_cmd*)vac, sizeof(fsub_cmd));
      ac->printHelp();
      break;
    }
    case 9:{
      struct div_cmd* ac=new struct div_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct div_cmd*)vac, sizeof(div_cmd));
      ac->printHelp();
      break;
    }
    case 10:{
      struct fdiv_cmd* ac=new struct fdiv_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct fdiv_cmd*)vac, sizeof(fdiv_cmd));
      ac->printHelp();
      break;
    }
    case 11:{
      struct mul_cmd* ac=new struct mul_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct mul_cmd*)vac, sizeof(mul_cmd));
      ac->printHelp();
      break;
    }
    case 12:{
      struct fmul_cmd* ac=new struct fmul_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct fmul_cmd*)vac, sizeof(fmul_cmd));
      ac->printHelp();
      break;
    }
    case 13:{
      struct mod_cmd* ac=new struct mod_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct mod_cmd*)vac, sizeof(mod_cmd));
      ac->printHelp();
      break;
    }
    case 14:{
      struct fmod_cmd* ac=new struct fmod_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct fmod_cmd*)vac, sizeof(fmod_cmd));
      cout << "here used fmod cmd" << endl;
      break;
    }
    case 15:{
      struct icmp_cmd* ac=new struct icmp_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct icmp_cmd*)vac, sizeof(icmp_cmd));
      ac->printHelp();
      break;
    }
    case 16:{
      struct fcmp_cmd* ac=new struct fcmp_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct fcmp_cmd*)vac, sizeof(fcmp_cmd));
      ac->printHelp();
      break;
    }
    case 17:{
      struct sitofp_cmd* ac=new struct sitofp_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct sitofp_cmd*)vac, sizeof(sitofp_cmd));
      ac->printHelp();
      break;
    }
    case 18:{
      struct fptosi_cmd* ac=new struct fptosi_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct fptosi_cmd*)vac, sizeof(fptosi_cmd));
      ac->printHelp();
      break;
    }
    case 19:{
      struct call_cmd* ac=new struct call_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct call_cmd*)vac, sizeof(call_cmd));
      ac->printHelp();
      break;
    }
    case 20:{
      struct br_cmd* ac=new struct br_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct br_cmd*)vac, sizeof(br_cmd));
      ac->printHelp();
      break;
    }
    case 21:{
      struct ret_cmd* ac=new struct ret_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (struct ret_cmd*)vac, sizeof(ret_cmd));
      ac->printHelp();
      break;
    }
  }
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
      cerr << "global command error !!!" << endl;
    }
  }
  return;
}
