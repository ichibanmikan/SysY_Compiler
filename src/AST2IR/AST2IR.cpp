#include "AST2IR.h"

void Function::printHelp(){
  for(int i=0; i<basic_blocks->size(); i++){
    cout << (*basic_blocks)[i]->block_label << ':' << endl;
    (*basic_blocks)[i]->printHelp();
  }
}

void Function::local_var_printHelp(){
  for(auto iter=local_var_table->begin(); iter!=local_var_table->end(); iter++){
    cout << '%' << iter->first << ' ' << endl;
    iter->second->local_var_type.printHelp();
  }
}

// void init_scope(){
//   scope.enter();//create an empty scope
// }

void printHelp(){
  for(map<string, global_var*>::iterator iter=global_var_table.begin(); iter!=global_var_table.end(); iter++){
    cout << '@' << iter->first << " = " << "dso_local global ";
    iter->second->printHelp();
    cout << endl;
  }

  for(map<string, const_var*>::iterator iter=const_var_table.begin(); iter!=const_var_table.end(); iter++){
    cout << '@' << iter->first << " = " << "dso_local constant ";
    iter->second->printHelp();
    cout << endl;
  }

  for(map<string, Function*>::iterator iter=functions_table.begin(); iter!=functions_table.end(); iter++){
    string ret_type_str=getTypeStr(iter->second->ret_type);
    cout << "define dso_local " << ret_type_str << " @" << iter->first << "() #0" << '{' << endl;
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
  // scope.push(node->name);//全局作用域内存放函数
  // scope.enter();//进入函数的作用域

  Function* func_ptr=new Function;
  func_ptr->ret_type=types_get(node->children[0]->name);

  params_gen(func_ptr, node->children[2]);

  basic_blocks_gen(func_ptr, node->children[3]);

  functions_table.insert(pair<string, Function*>(node->children[1]->name, func_ptr));

  // scope.exit();
}

void cmd_printHelp(command* cmd){
  switch(cmd->cmd_type){
    case 0:{
      alloca_cmd* ac=new alloca_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (alloca_cmd*)vac, sizeof(alloca_cmd));
      ac->printHelp();
      break;
    }
    case 1:{
      store_cmd* sc=new store_cmd;
      void* vsc=cmd->cmd_ptr;
      memcpy(sc, (store_cmd*)vsc, sizeof(store_cmd));
      sc->printHelp();
      break;
    }
    case 2:{
      load_cmd* ac=new load_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (load_cmd*)vac, sizeof(load_cmd));
      ac->printHelp();
      break;
    }
    case 3:{
      getelementptr_cmd* ac=new getelementptr_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (getelementptr_cmd*)vac, sizeof(getelementptr_cmd));
      ac->printHelp();
      break;
    }
    case 4:{
      bitcast_cmd* ac=new bitcast_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (bitcast_cmd*)vac, sizeof(bitcast_cmd));
      ac->printHelp();
      break;
    }
    case 5:{
      add_cmd* ac=new add_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (add_cmd*)vac, sizeof(add_cmd));
      ac->printHelp();
      break;
    }
    case 6:{
      fadd_cmd* ac=new fadd_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (fadd_cmd*)vac, sizeof(fadd_cmd));
      ac->printHelp();
      break;
    }
    case 7:{
      sub_cmd* ac=new sub_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (sub_cmd*)vac, sizeof(sub_cmd));
      ac->printHelp();
      break;
    }
    case 8:{
      fsub_cmd* ac=new fsub_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (fsub_cmd*)vac, sizeof(fsub_cmd));
      ac->printHelp();
      break;
    }
    case 9:{
      div_cmd* ac=new div_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (div_cmd*)vac, sizeof(div_cmd));
      ac->printHelp();
      break;
    }
    case 10:{
      fdiv_cmd* ac=new fdiv_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (fdiv_cmd*)vac, sizeof(fdiv_cmd));
      ac->printHelp();
      break;
    }
    case 11:{
      mul_cmd* ac=new mul_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (mul_cmd*)vac, sizeof(mul_cmd));
      ac->printHelp();
      break;
    }
    case 12:{
      fmul_cmd* ac=new fmul_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (fmul_cmd*)vac, sizeof(fmul_cmd));
      ac->printHelp();
      break;
    }
    case 13:{
      mod_cmd* ac=new mod_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (mod_cmd*)vac, sizeof(mod_cmd));
      ac->printHelp();
      break;
    }
    case 14:{
      fmod_cmd* ac=new fmod_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (fmod_cmd*)vac, sizeof(fmod_cmd));
      cout << "here used fmod cmd" << endl;
      break;
    }
    case 15:{
      icmp_cmd* ac=new icmp_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (icmp_cmd*)vac, sizeof(icmp_cmd));
      ac->printHelp();
      break;
    }
    case 16:{
      fcmp_cmd* ac=new fcmp_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (fcmp_cmd*)vac, sizeof(fcmp_cmd));
      ac->printHelp();
      break;
    }
    case 17:{
      sitofp_cmd* ac=new sitofp_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (sitofp_cmd*)vac, sizeof(sitofp_cmd));
      ac->printHelp();
      break;
    }
    case 18:{
      fptosi_cmd* ac=new fptosi_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (fptosi_cmd*)vac, sizeof(fptosi_cmd));
      ac->printHelp();
      break;
    }
    case 19:{
      call_cmd* ac=new call_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (call_cmd*)vac, sizeof(call_cmd));
      ac->printHelp();
      break;
    }
    case 20:{
      br_cmd* ac=new br_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (br_cmd*)vac, sizeof(br_cmd));
      ac->printHelp();
      break;
    }
    case 21:{
      ret_cmd* ac=new ret_cmd;
      void* vac=cmd->cmd_ptr;
      memcpy(ac, (ret_cmd*)vac, sizeof(ret_cmd));
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
/*
int a=1;
int b;
int c,d=2;
>--+ declarations
|  >--+ var_declaration
|  |  >--* int
|  |  >--+ idenfiers
|  |  |  >--+ =
|  |  |  |  >--* a
|  |  |  |  >--* 1
|  >--+ var_declaration
|  |  >--* int
|  |  >--+ idenfiers
|  |  |  >--* b
|  >--+ var_declaration
|  |  >--* int
|  |  >--+ idenfiers
|  |  |  >--* c
|  |  |  >--+ =
|  |  |  |  >--* d
|  |  |  |  >--* 2
*/
void global_val_gen(syntax_tree_node* node){
  int varType_ = types_get(node->children[0]->name);
  bool isInt=(varType_==4);
  bool isFloat=(varType_==9);
  type varTypeWrapped(varType_);

  // loops: BType VarDef {, VarDef, ...}
  for(int i=0; i<node->children[1]->children_num; i++){
    // alloc
    // command* cmd=new command;
    // cmd->cmd_type=alloca_c;
    // alloca_cmd* ac=new alloca_cmd;

    // store
    __global_var_value varValue_;// init as 0
    if(isInt){
      varValue_=(int)0;
    }else if(isFloat){
      varValue_=(float)0;
    }
    string varName_ = node->children[1]->children[i]->name;
    if(!strcmp(node->children[1]->children[i]->name, "=")){
      varName_ = node->children[1]->children[i]->children[0]->name;
      if(isInt){
        varValue_ = std::stoi(node->children[1]->children[i]->children[1]->name);
      }else if(isFloat){
        varValue_ = std::stof(node->children[1]->children[i]->children[1]->name);
      }
    }
    global_var *gvar=new global_var(varTypeWrapped,varValue_);
    global_var_table.insert(pair<string, global_var*>(varName_,gvar));

    // ac->dst_val = idx;//index
    // ac->align_len = getTypeSize(node->children[0]->name);
    // cmd->cmd_ptr = ac;
  }
  return ;
};
/*
****************************************
ConstDecl     → 'const' BType ConstDef { ',' ConstDef } ';'
ConstDef      → Ident { '[' ConstExp ']' } '=' ConstInitVal
ConstInitVal  → ConstExp
              | '{' [ ConstInitVal { ',' ConstInitVal } ] '}'
****************************************

const int a=1;
>--+ const_declartion_assignment
|  >--* int
|  >--+ declartion_assignments
|  |  >--+ =
|  |  |  >--* a
|  |  |  >--* 1

const int b=2,c=3;
>--+ const_declartion_assignment
|  >--* int
|  >--+ declartion_assignments
|  |  >--+ =
|  |  |  >--* b
|  |  |  >--* 2
|  |  >--+ =
|  |  |  >--* c
|  |  |  >--* 3

// const int d;

const int e=a;//may be initialized with global,const,local var
>--+ const_declartion_assignment
|  >--* int
|  >--+ declartion_assignments
|  |  >--+ =
|  |  |  >--* e
|  |  |  >--* a

*/
void global_const_val_gen(syntax_tree_node* node){
  int varType_ = types_get(node->children[0]->name);
  bool isInt=(varType_==4);
  bool isFloat=(varType_==9);
  type varTypeWrapped(varType_);

  // loops: BType VarDef {, VarDef, ...}
  for(int i=0; i<node->children[1]->children_num; i++){
    // alloc
    // command* cmd=new command;
    // cmd->cmd_type=alloca_c;
    // alloca_cmd* ac=new alloca_cmd;

    // store
    __global_var_value varValue_;// init as 0
    if(isInt){
      varValue_=(int)0;
    }else if(isFloat){
      varValue_=(float)0;
    }
    string varName_ = node->children[1]->children[i]->name;
    if(!strcmp(node->children[1]->children[i]->name, "=")){
      varName_ = node->children[1]->children[i]->children[0]->name;
      if(isInt){
        varValue_ = std::stoi(node->children[1]->children[i]->children[1]->name);
      }else if(isFloat){
        varValue_ = std::stof(node->children[1]->children[i]->children[1]->name);
      }
    }
    const_var *cvar=new const_var(varTypeWrapped,varValue_);
    const_var_table.insert(pair<string, const_var*>(varName_,cvar));

    // ac->dst_val = idx;//index
    // ac->align_len = getTypeSize(node->children[0]->name);
    // cmd->cmd_ptr = ac;
  }
  return ;
};
/*
****************************************
Stmt    → LVal = Exp; 
        | [Exp];
        | Block
Exp     ->  AddExp
VarDef  ->  Ident {[ConstExp]} = InitVal
****************************************
int b,c=2;
c=3;
|  >--+ var_declaration
|  |  >--* int
|  |  >--+ idenfiers
|  |  |  >--* b
|  |  |  >--+ =
|  |  |  |  >--* c
|  |  |  |  >--* 2
|  >--+ =
|  |  >--* c
|  |  >--* 3

int b,c=2;
//c=3,b=4;
*/
void assignment_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  string varName_=node->children[0]->name;
  
  int store_index = func->getVarNumStore(varName_);// if haven't declare...
  map<int ,local_var*> ::iterator it=func->local_var_table->find(store_index);
  if(it==func->local_var_table->end()){
    cerr<<"assign undefined variable!"<<endl;
    return;
  }
  type varType_=(*it).second->local_var_type;
  bool isInt=(varType_.val_type==4);
  bool isFloat=(varType_.val_type==9);

  __local_var_value varValue_;
  if(isInt){
    varValue_ = std::stoi(node->children[1]->name);
  }else if(isFloat){
    varValue_ = std::stof(node->children[1]->name);
  }

  // global value ?
  local_var *lv=new local_var(varType_,varValue_);
  func->add_new_local_var_store(lv,varName_);
  return ;
};
/*
const int d=1,e=2;
|  |  |  >--+ const_declartion_assignment
|  |  |  |  >--* int
|  |  |  |  >--+ declartion_assignments
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* d
|  |  |  |  |  |  >--* 1
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* e
|  |  |  |  |  |  >--* 2
*/
int getTypeSize(char* name){

  if(!strcmp(name, "int")){
    return 4;
  }
  if(!strcmp(name, "float")){
    return 4;
  }
  // if(!strcmp(name, "void*")){
  //   return 4;
  // }
  // system("pause");
  cerr << "type error !!!" << endl;
  return -1;
}

void const_declartion_assignment_gen
(Function* func, BasicBlock* bb, syntax_tree_node* node){
  int varType_ = types_get(node->children[0]->name);
  bool isInt=(varType_==4);
  bool isFloat=(varType_==9);
  type varTypeWrapped(varType_);
  
  // loops: BType VarDef {, VarDef, ...}
  for(int i=0; i<node->children[1]->children_num; i++){
    // alloc
    command* cmd=new command;
    cmd->cmd_type=alloca_c;
    alloca_cmd* ac=new alloca_cmd;


    // store
    __global_var_value varValue_;// init as 0
    if(isInt){
      varValue_=(int)0;
    }else if(isFloat){
      varValue_=(float)0;
    }
    string varName_ = node->children[1]->children[i]->name;
    if(!strcmp(node->children[1]->children[i]->name, "=")){
      varName_ = node->children[1]->children[i]->children[0]->name;
      if(isInt){
        //expression
        varValue_ = std::stoi(node->children[1]->children[i]->children[1]->name);
      }else if(isFloat){
        varValue_ = std::stof(node->children[1]->children[i]->children[1]->name);
      }
    }
    const_var *cvar=new const_var(varTypeWrapped,varValue_);
    int idx=func->add_new_local_const_var_store(cvar,varName_);


    // ac->dst_val = idx;//index
    ac->align_len = getTypeSize(node->children[0]->name);
    cmd->cmd_ptr = ac;
    bb->cmds->push_back(cmd);
  }
  return ;
};
/*
*****************************************
VarDecl ->  BType VarDef {, VarDef};
VarDef  ->  Ident {[ConstExp]}
        |   Ident {[ConstExp]} = InitVal
InitVal ->  Exp
        |   { [InitVal {,InitVal}] }
Exp     ->  AddExp
AddExp  ->  
******************************************

int b,c=2;
|  |  |  >--+ var_declaration
|  |  |  |  >--* int
|  |  |  |  >--+ idenfiers
|  |  |  |  |  >--* b
|  |  |  |  |  >--+ =
|  |  |  |  |  |  >--* c
|  |  |  |  |  |  >--* 2
*/
// update local var table\global var table
void var_declaration_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  int varType_ = types_get(node->children[0]->name);
  bool isInt=(varType_==4);
  bool isFloat=(varType_==9);
  type varTypeWrapped(varType_);

  // loops: BType VarDef {, VarDef, ...}
  for(int i=0; i<node->children[1]->children_num; i++){
    // alloc
    command* cmd=new command;
    cmd->cmd_type=alloca_c;
    alloca_cmd* ac=new alloca_cmd;

    // store
    __local_var_value varValue_;// init as 0
    if(isInt){
      varValue_=(int)0;
    }else if(isFloat){
      varValue_=(float)0;
    }
    string varName_ = node->children[1]->children[i]->name;
    if(!strcmp(node->children[1]->children[i]->name, "=")){
      varName_ = node->children[1]->children[i]->children[0]->name;
      if(isInt){
        varValue_ = std::stoi(node->children[1]->children[i]->children[1]->name);
      }else if(isFloat){
        varValue_ = std::stof(node->children[1]->children[i]->children[1]->name);
      }
    }
    local_var *lv=new local_var(varTypeWrapped,varValue_);
    int idx=func->add_new_local_var_store(lv,varName_);

    ac->dst_val = idx;//index
    //ac->align_len = getTypeSize(node->children[0]->name);
    cmd->cmd_ptr = ac;
    bb->cmds->push_back(cmd);
  }  
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
      global_const_val_gen(tree->root->children[i]);
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