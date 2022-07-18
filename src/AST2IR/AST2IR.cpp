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

void printHelp(){
  for(map<string, global_var*>::iterator iter=global_var_table.begin(); iter!=global_var_table.end(); iter++){
    cout << '@' << iter->first << " = " << "dso_local global ";
    iter->second->printHelp();
    cout << endl;
  }

  for(map<string, const_var*>::iterator iter=const_var_table.begin(); iter!=const_var_table.end(); iter++){
    cout << '@' << iter->first << " = " << "dso_local global ";
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
  Function* func_ptr=new Function;
  func_ptr->ret_type=types_get(node->children[0]->name);

  params_gen(func_ptr, node->children[2]);

  basic_blocks_gen(func_ptr, node->children[3]);

  functions_table.insert(pair<string, Function*>(node->children[1]->name, func_ptr));
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
  set_sc_tree(node);
  BasicBlock* thisBB=new BasicBlock;
  func->basic_blocks->push_back(thisBB);
  thisBB->block_label=func->local_var_table->size();
  basic_cmds_gen(func, thisBB, node); //读入的是{...}，node就是AST中的stmts
} //basic_block_gen和basic_cmds_gen读取到的都是stmts结点

void set_sc_tree(syntax_tree_node* node){
  for(int i=0; i<node->children_num; i++){
    if(!strcmp(node->children[i]->name, "if_stmt")){
      while_set_sc_node(node->children[i], 1);
      while_cut_tree_node(node->children[i]);
    } else if(!strcmp(node->children[i]->name, "while_stmt")){
      while_set_sc_node(node->children[i], 1);
      while_cut_tree_node(node->children[i]);
    } else if(!strcmp(node->children[i]->name, "if_else_stmt")){
      while_set_sc_node(node->children[i], 1);
      if_else_cut_tree_node(node->children[i]);
    }
    continue;
  }
}

void if_else_cut_tree_node(syntax_tree_node* node){
  for(int i=0; i<node->children_num-2; i++){
    vector<syntax_tree_node*> vec;
    if(!strcmp(node->children[i]->name, "&&")){
      cut_tree_node(node->children[i], vec);
    }
    node->children[i]->children_num=0;
    for(int j=0; j<vec.size(); j++){
      syntax_tree_add_child(node->children[i], vec[j]);
    }
  }
}

void while_cut_tree_node(syntax_tree_node* node){
  for(int i=0; i<node->children_num-1; i++){
    vector<syntax_tree_node*> vec;
    if(!strcmp(node->children[i]->name, "&&")){
      cut_tree_node(node->children[i], vec);
    }
    node->children[i]->children_num=0;
    for(int j=0; j<vec.size(); j++){
      syntax_tree_add_child(node->children[i], vec[j]);
    }
  }
}

void cut_tree_node(syntax_tree_node* node, vector<syntax_tree_node*>& vec){
  if(!strcmp(node->children[0]->name, "&&")){
    cut_tree_node(node->children[0], vec);
    vec.push_back(node->children[1]);
  } else {
    vec.push_back(node->children[0]);
    vec.push_back(node->children[1]);
  }
}

void while_set_sc_node(syntax_tree_node* node, int pos){
  if(!strcmp(node->children[0]->name, "||")){
    add_children_by_pos(node, node->children[0]->children[1], pos);
    node->children[0]=node->children[0]->children[0];
    for(int i=0; i<node->children_num-1; i++){
      while_set_sc_node(node, i+1);
    }
  }
}

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
  if(get_if<3>(&v)){
    cout << get<3>(v);
  }
  if(get_if<4>(&v)){
    cout << get<4>(v);
  }
  if(get_if<10>(&v)){
    cout << get<10>(v);
  }
}

/*
params_gen可被functions_gen调用: 记录参数的类型；并修改lvt表的值，更新局部变量
形参只有两类：
param，param_array
类型type_specifier支持三种:
INT，FLOAT，VOID
*/
void params_gen(Function* func, syntax_tree_node* node){
  syntax_tree_node* t;

  if(strcmp(node->name,"void")!=0){
    int param_num=node->children_num;
    int key;

    for(int i=0;i<param_num;i++){
      local_var* lval_;
      valTypes val_;

      t=node->children[i];

      if(strcmp(t->name,"param")==0){//不为数组
        char* name_=t->children[0]->name;

        if(strcmp(name_,"int")==0){
          val_=i32;
        }
        else if(strcmp(name_,"float")==0){
          val_=float_type;
        }
        type t2(val_);
        lval_->local_var_type=t2;
        // add_new_var_store(local_var* lv, string var_name)
        func->add_new_var_store(lval_,t->children[1]->name);

      }
      else{//为数组
        char* name_=t->children[0]->name;

        if(strcmp(name_,"int")==0){
          val_=i32_ptr;
        }
        else if(strcmp(name_,"float")==0){
          val_=float_ptr;
        }

        type t2(val_);
        //如果形参为int a[1][2][]
        int dsize=t->children[2]->children_num;//取出这个数组的维度
        for(int j=0;j<dsize;j++){
          char* str=t->children[i]->name;
          if(strcmp(str,"void")==0){  //有个疑惑，当某一维不知道大小时，dimension_size[i]应该为多少？
            t2.dimension_size[j]=-1;
            break;
          }
          else{
            t2.dimension_size[j]=atoi(str);
          }
        }
        lval_->local_var_type=t2;
        func->add_new_var_store(lval_,t->children[1]->name);

      }

    }
  }
}

void global_val_gen(syntax_tree_node* node){
  return ;
}

void const_val_gen(syntax_tree_node* node){
  return ;
};

void if_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}
void while_stmt_gen
(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}

void rtmt_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}
/*
type ret_type; //返回值类型，先判断是不是为void
  int ret_value; //返回值一定先存储到寄存器变量
  string func_name;
  vector<param> params;
*/
void call_func_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  // Function* func_ptr=new Function;
  // func_ptr=functions_table[node->name];
  call_cmd* call_;
  call_->func_name=node->name;
  call_->ret_type=func->ret_type;

  // call_.ret_value=??

  int args_num=node->children_num;
  if(args_num>0){

    if(strcmp(node->children[0]->name,"args")==0){    //若调用的是自定义函数

      if(strcmp(node->children[0]->children[0]->name,"epsilon")!=0){
        int user_args_num=node->children[0]->children_num;
        for(int i=0;i<user_args_num;i++){
        param arg_;
        char arg_name[30];
        syntax_tree_node* t=node->children[0]->children[i];

        strcpy(arg_name,t->name);


        int key_;
        if(strcmp(arg_name,"+")==0||strcmp(arg_name,"-")==0||strcmp(arg_name,"/")==0||strcmp(arg_name,"*")==0){//为算数表达式：+

      //algo_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node)
         int __imp_name__=0;
         key_ = algo_expressions_gen(bb->cmds, func, t, __imp_name__);
        }
        else{

        if(func->is_loaded(arg_name)){
          key_=func->getVarNumLoad(arg_name);
        }
        else key_=func->getVarNumStore(arg_name);

        map<int, local_var*>::iterator it ;
        map<int, const_var*>::iterator it2 ;
        map<string, global_var*>::iterator it3 ;
        map<string, const_var*>::iterator it4 ;

        if(func->local_var_table->find(key_)!=func->local_var_table->end()){//若实参为局部变量
          it = func->local_var_table->find(key_);
          arg_.is_global_val=false;
          arg_.is_local_val=true;
          arg_.param_type=it->second->local_var_type;
          arg_.param_value=it->second->local_var_value;
        }
        else if(func->local_const_var_table->find(key_)!=func->local_const_var_table->end()){//若实参为局部常变量
          it2=func->local_const_var_table->find(key_);
          arg_.is_global_val=false;
          arg_.is_local_val=true;
          arg_.param_type=it2->second->global_var_type;
          arg_.param_value=it2->second->global_var_value;

        }
        else if(global_var_table.find(arg_name)!=global_var_table.end()){//若实参为全局变量
          it3=global_var_table.find(arg_name);
          arg_.is_global_val=true;
          arg_.is_local_val=false;
          arg_.param_type=it3->second->global_var_type;
          arg_.param_value=it3->second->global_var_value;


        }
        else if(const_var_table.find(arg_name)!=const_var_table.end()){//若实参为全局常变量
          it4=const_var_table.find(arg_name);
          arg_.is_global_val=true;
          arg_.is_local_val=false;
          arg_.param_type=it4->second->global_var_type;
          arg_.param_value=it4->second->global_var_value;

        }
        else{
          printf("error(AST2IR.438):找不到实参\n");
          exit(0);
        }
        call_->params.push_back(arg_);
      }

      }

      }


    }
    else{   //若调用的是特殊函数
      if(strcmp(node->children[0]->name,"epsilon")!=0){

        int lib_args_num=node->children_num;

        for(int i=0;i<lib_args_num;i++){
        param arg_;
        char arg_name[30];
        strcpy(arg_name,node->children[i]->name);

        int key_;
        if(strcmp(arg_name,"+")==0||strcmp(arg_name,"-")==0||strcmp(arg_name,"/")==0||strcmp(arg_name,"*")==0){//为算数表达式：+
          int __imp_name__=0;
          key_=algo_expressions_gen(bb->cmds, func, node->children[i], __imp_name__);
        }
        else{

        if(func->is_loaded(arg_name)){
          key_=func->getVarNumLoad(arg_name);
        }
        else key_=func->getVarNumStore(arg_name);


        map<int, local_var*>::iterator it ;
        map<int, const_var*>::iterator it2 ;
        map<string, global_var*>::iterator it3 ;
        map<string, const_var*>::iterator it4 ;


        if(func->local_var_table->find(key_)!=func->local_var_table->end()){//若实参为局部变量
          it = func->local_var_table->find(key_);
          arg_.is_global_val=false;
          arg_.is_local_val=true;
          arg_.param_type=it->second->local_var_type;
          arg_.param_value=it->second->local_var_value;
        }
        else if(func->local_const_var_table->find(key_)!=func->local_const_var_table->end()){//若实参为局部常变量
          it2=func->local_const_var_table->find(key_);
          arg_.is_global_val=false;
          arg_.is_local_val=true;
          arg_.param_type=it2->second->global_var_type;
          arg_.param_value=it2->second->global_var_value;

        }
        else if(global_var_table.find(arg_name)!=global_var_table.end()){//若实参为全局变量
          it3=global_var_table.find(arg_name);
          arg_.is_global_val=true;
          arg_.is_local_val=false;
          arg_.param_type=it3->second->global_var_type;
          arg_.param_value=it3->second->global_var_value;


        }
        else if(const_var_table.find(arg_name)!=const_var_table.end()){//若实参为全局常变量
          it4=const_var_table.find(arg_name);
          arg_.is_global_val=true;
          arg_.is_local_val=false;
          arg_.param_type=it4->second->global_var_type;
          arg_.param_value=it4->second->global_var_value;

        }
        else{
          printf("error(AST2IR.135):找不到实参\n");
          exit(0);
        }
        call_->params.push_back(arg_);
        }
      }


    }

  }


  }

  command* callcmd;
  callcmd->cmd_type=19;
  callcmd->cmd_ptr=call_;
  bb->cmds->push_back(callcmd);

}

void break_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}
void assignment_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}
void var_declaration_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}
void const_declartion_assignment_gen
(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}

void continue_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
}

/*
|  |  |  |  |  |  |  |  |  >--+ e
|  |  |  |  |  |  |  |  |  |  >--+ array_size
|  |  |  |  |  |  |  |  |  |  |  >--* 1
|  |  |  |  |  |  |  |  |  |  |  >--* 2
|  |  |  |  |  |  |  |  |  |  |  >--* 3
*/
int array_offset_gen(Function* func,vector<command*>* vcmd,syntax_tree_node* node,int key,type stype){
  cout<<"----run array_offset_gen----: node_name="<<node->name<<endl;
  type arr_type=stype;
  int size_=node->children_num;
  int res;
  type last_type;
  if(stype.val_type==i32_ptr){
    last_type.val_type=i32;
  }
  else last_type.val_type=float_type;

  for(int i=0;i<size_;i++){

  vector<int>::iterator k = arr_type.dimension_size.begin();

  arr_type.dimension_size.erase(k);

  getelementptr_cmd* gcmd=new getelementptr_cmd;
  local_var* gcmddst=new local_var;
    if(i==size_-1){
      gcmddst->local_var_type=last_type;
    }
    else{
      gcmddst->local_var_type=arr_type;
    }
  gcmd->dst_val=func->add_new_var_load(gcmddst);
  gcmd->is_global_val=0;
  gcmd->src_val=key;
  gcmd->src_type=stype;
  char offset_str[30];
  strcpy(offset_str,node->children[i]->name);
  gcmd->offset=atoi(offset_str);

  command* cmd=new command;
  cmd->cmd_type=3;
  cmd->cmd_ptr=gcmd;
  vcmd->push_back(cmd);

  res=gcmd->dst_val;
  cout<<"当前数组规模："<<arr_type.dimension_size.size()<<endl;
  cout<<"当前变量号："<<res<<endl;

  }
  return res;
}
void logic_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node){
  return ;
}
/*
函数计算b=a+c+b中“a+c+b”的值，并返回
a+3的情况？
%x=add
|  |  |  |  |  |  >--+ +
|  |  |  |  |  |  |  >--+ +
|  |  |  |  |  |  |  |  >--* a
|  |  |  |  |  |  |  |  >--* c
|  |  |  |  |  |  |  >--* b
*/
map<int, local_var*>::iterator it ;
map<int, const_var*>::iterator it2 ;
map<string, global_var*>::iterator it3 ;
map<string, const_var*>::iterator it4 ;

int algo_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node){
  int __imp_name__=0;
  return algo_expressions_gen(vcmd, func, node, __imp_name__);
}

int algo_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node,int &has_f ){
  char arg_name[30],arg_name2[30],op_name[30];
  strcpy(arg_name,node->name);
  int key1,key2;

  if(strcmp(arg_name,"+")==0||strcmp(arg_name,"-")==0||strcmp(arg_name,"/")==0||strcmp(arg_name,"*")==0){
    strcpy(op_name,arg_name);
    // strcpy(arg_name,node->name);
    int has_float=0,has_float2=0;

    key1=algo_expressions_gen(vcmd, func, node->children[0],has_float);
    strcpy(arg_name2,node->children[1]->name);
    if(func->is_loaded(arg_name2)){
      key2=func->getVarNumLoad(arg_name2);
    }
    else {
      key2=func->getVarNumStore(arg_name2);
    // load

    __local_var_value t2;
    type ty2;

    if(func->local_var_table->find(key2)!=func->local_var_table->end()){//若实参为局部变量

          it = func->local_var_table->find(key2);
          ty2=it->second->local_var_type;
          t2=it->second->local_var_value;
        }
    else if(func->local_const_var_table->find(key2)!=func->local_const_var_table->end()){//若实参为局部常变量
          it2=func->local_const_var_table->find(key2);
          ty2=it2->second->global_var_type;
          t2=it2->second->global_var_value;

        }
    else if(global_var_table.find(arg_name2)!=global_var_table.end()){//若实参为全局变量
          it3=global_var_table.find(arg_name2);

          ty2=it3->second->global_var_type;
          t2=it3->second->global_var_value;


        }
    else if(const_var_table.find(arg_name2)!=const_var_table.end()){//若实参为全局常变量
          it4=const_var_table.find(arg_name2);
          ty2=it4->second->global_var_type;
          t2=it4->second->global_var_value;

        }
    else{
          printf("error(AST2IR.810):找不到实参\n");
          exit(0);
    }
    //若为数组，load取出值
    if(ty2.val_type==i32_ptr){
     int ptr1= array_offset_gen(func,vcmd,node->children[0],key2,ty2);
    load_cmd* loadcmd;
      // loadcmd->dst_val=ptr1+1;
      local_var* loaddst=new local_var;
      type loaddst_type;
      loaddst_type.val_type=4;
      loaddst->local_var_type=loaddst_type;
      loadcmd->dst_val=func->add_new_var_load(loaddst);
      loadcmd->dst_type=4;
      loadcmd->is_glo_val=0;
      loadcmd->src_val=ptr1;
      loadcmd->src_type=8;

      command* cmd=new command;
      cmd->cmd_type=2;
      cmd->cmd_ptr=loadcmd;
      vcmd->push_back(cmd);

      key2=loadcmd->dst_val;
    }
    else if(ty2.val_type==float_ptr){
     has_float2=1;
    int ptr1= array_offset_gen(func,vcmd,node->children[0],key2,ty2);
      load_cmd* loadcmd;
      local_var* loaddst=new local_var;
      type loaddst_type;
      loaddst_type.val_type=float_type;
      loaddst->local_var_type=loaddst_type;
      loadcmd->dst_val=func->add_new_var_load(loaddst);

      // loadcmd->dst_val=ptr1+1;
      loadcmd->dst_type=9;
      loadcmd->is_glo_val=0;
      loadcmd->src_val=ptr1;
      loadcmd->src_type=10;
      command* cmd;
      cmd->cmd_type=2;
      cmd->cmd_ptr=loadcmd;
      vcmd->push_back(cmd);
      key2=loadcmd->dst_val;

    }
  }

    //浮点数和整型一起运算时，整型值需要进行类型提升，转换成浮点数类型
    if(has_float==0&&has_float2==0){
      local_var* loaddst=new local_var;
      type loaddst_type;
      loaddst_type.val_type=i32;
      loaddst->local_var_type=loaddst_type;

      if(strcmp(op_name,"+")==0){
  // %7      = fadd float    %5, %6
  //  dst_val       src_type  src_val_1 src_val_2

      add_cmd* add=new add_cmd;
      add->dst_val=func->add_new_var_load(loaddst);
      add->is_val_1=1;
      add->is_val_2=1;
      add->src_type=9;
      add->src_val_1=key1;
      add->src_val_2=key2;

      command* addcmd=new command;
        addcmd->cmd_type=5;
        addcmd->cmd_ptr=add;
        vcmd->push_back(addcmd);
        return add->dst_val;
    }
    else if(strcmp(op_name,"-")==0){
      sub_cmd* sub;
      sub->dst_val=func->add_new_var_load(loaddst);
      sub->is_val_1=1;
      sub->is_val_2=1;
      sub->src_type=9;
      sub->src_val_1=key1;
      sub->src_val_2=key2;

      command* subcmd;
        subcmd->cmd_type=7;
        subcmd->cmd_ptr=sub;
        vcmd->push_back(subcmd);
        return sub->dst_val;
    }
    else if(strcmp(op_name,"*")==0){
      mul_cmd* mul;
      mul->dst_val=func->add_new_var_load(loaddst);
      mul->is_val_1=1;
      mul->is_val_2=1;
      mul->src_type=9;
      mul->src_val_1=key1;
      mul->src_val_2=key2;

      command* mulcmd;
        mulcmd->cmd_type=11;
        mulcmd->cmd_ptr=mul;
        vcmd->push_back(mulcmd);
        return mul->dst_val;
    }
    else {
      div_cmd* div;
      div->dst_val=func->add_new_var_load(loaddst);
      div->is_val_1=1;
      div->is_val_2=1;
      div->src_type=9;
      div->src_val_1=key1;
      div->src_val_2=key2;

      command* divcmd;
        divcmd->cmd_type=9;
        divcmd->cmd_ptr=div;
        vcmd->push_back(divcmd);
        return div->dst_val;
    }
    }
    else{
      local_var* loaddst=new local_var;
      type loaddst_type;
      loaddst_type.val_type=float_type;
      loaddst->local_var_type=loaddst_type;
    if(has_float==1){
      if(has_float2==0){
        local_var* loaddst2=new local_var;
        type loaddst_type2;
        loaddst_type2.val_type=float_type;
        loaddst2->local_var_type=loaddst_type2;

        // int key2_f=func->local_var_table->size();
        sitofp_cmd* itof;
        itof->dst_val=func->add_new_var_load(loaddst2);
        itof->src_val=key2;
        command* itofcmd;
        itofcmd->cmd_type=17;
        itofcmd->cmd_ptr=itof;
        vcmd->push_back(itofcmd);
      }
    }
    else if(has_float2==1){
      if(has_float==0){
        local_var* loaddst2=new local_var;
        type loaddst_type2;
        loaddst_type2.val_type=float_type;
        loaddst2->local_var_type=loaddst_type2;

        // int key1_f=func->local_var_table->size();
        sitofp_cmd* itof;
        itof->dst_val=func->add_new_var_load(loaddst2);
        itof->src_val=key1;
        command* itofcmd;
        itofcmd->cmd_type=17;
        itofcmd->cmd_ptr=itof;
        vcmd->push_back(itofcmd);
      }
    }
    if(strcmp(op_name,"+")==0){
  // %7      = fadd float    %5, %6
  //  dst_val       src_type  src_val_1 src_val_2
      fadd_cmd* fadd;
      fadd->dst_val=func->add_new_var_load(loaddst);
      fadd->is_val_1=1;
      fadd->is_val_2=1;
      fadd->src_type=9;
      fadd->src_val_1=key1;
      fadd->src_val_2=key2;

      command* faddcmd;
        faddcmd->cmd_type=6;
        faddcmd->cmd_ptr=fadd;
        vcmd->push_back(faddcmd);
        return fadd->dst_val;
    }
    else if(strcmp(op_name,"-")==0){
      fsub_cmd* fsub;
      fsub->dst_val=func->add_new_var_load(loaddst);
      fsub->is_val_1=1;
      fsub->is_val_2=1;
      fsub->src_type=9;
      fsub->src_val_1=key1;
      fsub->src_val_2=key2;

      command* fsubcmd;
        fsubcmd->cmd_type=8;
        fsubcmd->cmd_ptr=fsub;
        vcmd->push_back(fsubcmd);
        return fsub->dst_val;
    }
    else if(strcmp(op_name,"*")==0){
      fmul_cmd* fmul;
      fmul->dst_val=func->add_new_var_load(loaddst);
      fmul->is_val_1=1;
      fmul->is_val_2=1;
      fmul->src_type=9;
      fmul->src_val_1=key1;
      fmul->src_val_2=key2;

      command* fmulcmd;
        fmulcmd->cmd_type=12;
        fmulcmd->cmd_ptr=fmul;
        vcmd->push_back(fmulcmd);
        return fmul->dst_val;
    }
    else {
      fdiv_cmd* fdiv;
      fdiv->dst_val=func->add_new_var_load(loaddst);
      fdiv->is_val_1=1;
      fdiv->is_val_2=1;
      fdiv->src_type=9;
      fdiv->src_val_1=key1;
      fdiv->src_val_2=key2;

      command* fdivcmd;
        fdivcmd->cmd_type=10;
        fdivcmd->cmd_ptr=fdiv;
        vcmd->push_back(fdivcmd);
        return fdiv->dst_val;
    }

    }


  }
  else{

    int key_1;
    if(func->is_loaded(arg_name)){
      key_1=func->getVarNumLoad(arg_name);
    }
    else {
      key_1=func->getVarNumStore(arg_name);
    // load

    __local_var_value t1;
    type ty1;

    if(func->local_var_table->find(key_1)!=func->local_var_table->end()){//若实参为局部变量

          it = func->local_var_table->find(key_1);
          ty1=it->second->local_var_type;
          t1=it->second->local_var_value;
        }
    else if(func->local_const_var_table->find(key_1)!=func->local_const_var_table->end()){//若实参为局部常变量
          it2=func->local_const_var_table->find(key_1);
          ty1=it2->second->global_var_type;
          t1=it2->second->global_var_value;

        }
    else if(global_var_table.find(arg_name)!=global_var_table.end()){//若实参为全局变量
          it3=global_var_table.find(arg_name);

          ty1=it3->second->global_var_type;
          t1=it3->second->global_var_value;


        }
    else if(const_var_table.find(arg_name)!=const_var_table.end()){//若实参为全局常变量
          it4=const_var_table.find(arg_name);
          ty1=it4->second->global_var_type;
          t1=it4->second->global_var_value;

        }
    else{
          printf("error(AST2IR.810):找不到实参\n");
          exit(0);
    }
    //若为数组，load取出值
    if(ty1.val_type==i32_ptr){
     int ptr1= array_offset_gen(func,vcmd,node->children[0],key_1,ty1);
    load_cmd* loadcmd;
      // loadcmd->dst_val=ptr1+1;
      local_var* loaddst=new local_var;
      type loaddst_type;
      loaddst_type.val_type=4;
      loaddst->local_var_type=loaddst_type;
      loadcmd->dst_val=func->add_new_var_load(loaddst);
      loadcmd->dst_type=4;
      loadcmd->is_glo_val=0;
      loadcmd->src_val=ptr1;
      loadcmd->src_type=8;

      command* cmd=new command;
      cmd->cmd_type=2;
      cmd->cmd_ptr=loadcmd;
      vcmd->push_back(cmd);

      key_1=loadcmd->dst_val;
    }
    else if(ty1.val_type==float_ptr){
     has_f=1;
    int ptr1= array_offset_gen(func,vcmd,node->children[0],key_1,ty1);
      load_cmd* loadcmd;
      local_var* loaddst=new local_var;
      type loaddst_type;
      loaddst_type.val_type=float_type;
      loaddst->local_var_type=loaddst_type;
      loadcmd->dst_val=func->add_new_var_load(loaddst);

      // loadcmd->dst_val=ptr1+1;
      loadcmd->dst_type=9;
      loadcmd->is_glo_val=0;
      loadcmd->src_val=ptr1;
      loadcmd->src_type=10;
      command* cmd;
      cmd->cmd_type=2;
      cmd->cmd_ptr=loadcmd;
      vcmd->push_back(cmd);
      key_1=loadcmd->dst_val;

    }
  }
    return key_1;
  }

}




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

