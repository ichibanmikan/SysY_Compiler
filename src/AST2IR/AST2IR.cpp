#include "AST2IR.h"
#include <regex>

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
int lastStmtsBBIdx; //第一个if
//int lastEndBBIdx;

int break2BBIdx;
int continue2BBIdx;

br_cmd* ifBrCmdPtr;

br_cmd* unCondBrCmdPtr;

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
  cerr << name << " " << "type error !!!" << endl;
  return -1;
}

int isCompLogSta(char* name)
{
    if(!strcmp(name, "==") || !strcmp(name, "!=") || !strcmp(name, ">=")
        || !strcmp(name, "<=") || !strcmp(name, ">") || !strcmp(name, "<"))
    {
        return 1;
    }
    if(!strcmp(name, "unary_ops_factor"))
    {
        return 2;
    }
    if(!strcmp(name, "||") || !strcmp(name, "&&"))
    {
        return 3;
    }
    // system("pause");
    return -1;
}

//添加无条件跳转命令
void addUnCondBr(BasicBlock* bb,int tolabel,bool f=false)
{
    br_cmd* recmd = new br_cmd;
    recmd->is_cond = false;
    recmd->br_label_1 = tolabel;

    command* cmd1  =new command;
    cmd1->cmd_type = br;
    cmd1->cmd_ptr = (void*) recmd;
    bb->cmds->push_back(cmd1);

    if(f)    //更新全局变量
    {
        unCondBrCmdPtr = recmd;
    }
}

void addCondBr(BasicBlock* bb,int label1,int label2,int brcond,bool f=false)
{
    br_cmd* ifbrcmd = new br_cmd;
    ifbrcmd->is_cond = true;
    ifbrcmd->cond_val = brcond;
    ifbrcmd->br_label_1 = label1;
    ifbrcmd->br_label_2 = label2;


    command* brbbcmd = new command;
    brbbcmd->cmd_type = br;
    brbbcmd->cmd_ptr = (void*) ifbrcmd;
    bb->cmds->push_back(brbbcmd);
}


void forAnds(Function* func, BasicBlock* bb, syntax_tree_node* node,int stmtBBIdx)
{
    int nextBBIdx = func->basic_blocks->size();
    for(int i=0;i<node->children_num-1; i++)
    {
        // TODO:满足跳转到下一个，不满足跳出去
        // 不用添加基本块
        // 最后一个满足，就跳到stmt
        logic_expressions_gen(func,bb,node->children[i]);
        //local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
        addCondBr(bb,nextBBIdx,-1,func->local_var_table->size()-1);
    }
    logic_expressions_gen(func,bb,node->children[node->children_num-1]);
    //local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
    addCondBr(bb,stmtBBIdx,nextBBIdx,func->local_var_table->size()-1);

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
    } else if(!strcmp(node->children[i]->name, "if_else_stmt")){
      if_else_stmt_gen(func, bb, node->children[i]);
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
      local_var* lval_=new local_var;
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

void if_else_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    // 先生成stmt，最后在stmt后添加跳转
    // 记得给continue和break维护全局变量
    int stmtBBIdx = func->basic_blocks->size();
    BasicBlock* stmtBB = new BasicBlock;
    func->basic_blocks->push_back(stmtBB);
    basic_cmds_gen(func,stmtBB,node->children[node->children_num-2]);
    stmtBB = (*func->basic_blocks)[func->basic_blocks->size()-1];

    int condBBIdx = func->basic_blocks->size();
    addUnCondBr(bb,condBBIdx); //非常重要

    //BasicBlock* condBB = new BasicBlock;
    //func->basic_blocks->push_back(condBB);
    for(int i=0; i<node->children_num-1; i++)
    {
        if(!strcmp(node->children[i]->name,"&&"))
        {
            BasicBlock* condBB = new BasicBlock;
            func->basic_blocks->push_back(condBB);
            forAnds(func,condBB,node->children[i],stmtBBIdx);
        }
        else
        {
            BasicBlock* condBB = new BasicBlock;
            func->basic_blocks->push_back(condBB);
            logic_expressions_gen(func,condBB,node->children[i]);
            //local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
            int nextBBIdx = func->basic_blocks->size();
            addCondBr(condBB,stmtBBIdx,nextBBIdx,func->local_var_table->size()-1);
            // TODO:满足跳转到stmt，不满足跳转到下一个条件
            // 需要新基本块
        }
    }
    int elseBBIdx = func->basic_blocks->size();
    BasicBlock* elseBB = new BasicBlock;
    func->basic_blocks->push_back(elseBB);
    basic_cmds_gen(func,elseBB,node->children[node->children_num-2]);
    elseBB = (*func->basic_blocks)[func->basic_blocks->size()-1];


    int nextBBIdx = func->basic_blocks->size();
    addUnCondBr(elseBB,nextBBIdx);
    addUnCondBr(stmtBB,nextBBIdx);
    //给stmt添加跳转
}

void if_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    // 先生成stmt，最后在stmt后添加跳转
    // 记得给continue和break维护全局变量
    int stmtBBIdx = func->basic_blocks->size();
    BasicBlock* stmtBB = new BasicBlock;
    func->basic_blocks->push_back(stmtBB);
    basic_cmds_gen(func,stmtBB,node->children[node->children_num-1]);
    stmtBB = (*func->basic_blocks)[func->basic_blocks->size()-1];

    int condBBIdx = func->basic_blocks->size();
    addUnCondBr(bb,condBBIdx); //非常重要

    //BasicBlock* condBB = new BasicBlock;
    //func->basic_blocks->push_back(condBB);
    for(int i=0; i<node->children_num-1; i++)
    {
        if(!strcmp(node->children[i]->name,"&&"))
        {
            BasicBlock* condBB = new BasicBlock;
            func->basic_blocks->push_back(condBB);
            forAnds(func,condBB,node->children[i],stmtBBIdx);
        }
        else
        {
            BasicBlock* condBB = new BasicBlock;
            func->basic_blocks->push_back(condBB);
            logic_expressions_gen(func,condBB,node->children[i]);
            //local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
            int nextBBIdx = func->basic_blocks->size();
            addCondBr(condBB,stmtBBIdx,nextBBIdx,func->local_var_table->size()-1);
            // TODO:满足跳转到stmt，不满足跳转到下一个条件
            // 需要新基本块
        }
    }
    int nextBBIdx = func->basic_blocks->size();
    addUnCondBr(stmtBB,nextBBIdx);
    //给stmt添加跳转
}
/*void if_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    //BasicBlock* ifBB=new BasicBlock;
    ifBB = bb;
    int ifBBIdx = func->basic_blocks->size();
    //func->basic_blocks->push_back(ifBB);
    logic_expressions_gen(func,ifBB,node->children[0]);

    local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
    int brcondIdx=func->local_var_table->size()-1;

    if(!strcmp(node->children[1]->name,"stmts"))
    {
        int stmtBBIdx = func->basic_blocks->size();

        BasicBlock* stmtBB=new BasicBlock;
        func->basic_blocks->push_back(stmtBB);
        basic_cmds_gen(func,stmtBB,node->children[1]);
        int endBBIdx = func->basic_blocks->size();

        lastStmtsBBIdx = stmtBBIdx;     //更新全局变量,处理嵌套的if之后更新，应该没问题吧

        stmtBB = (*func->basic_blocks)[endBBIdx-1];
        addUnCondBr(stmtBB,endBBIdx,true);  //这里是暂时让stmt跳转到下一个，但是保存了这个跳转命令

        br_cmd* ifbrcmd = new br_cmd;
        ifbrcmd->is_cond = true;
        ifbrcmd->cond_val = brcondIdx;
        ifbrcmd->br_label_1 = lastStmtsBBIdx;
        ifbrcmd->br_label_2 = endBBIdx;

        int endBBIdx = func->basic_blocks->size();
        //ifBrCmdPtr = ifbrcmd;

        command* brbbcmd = new command;
        brbbcmd->cmd_type = br;
        brbbcmd->cmd_ptr = (void*) ifbrcmd;
        ifBB->cmds->push_back(brbbcmd);
    }

    else if(!strcmp(node->children[1]->name,"goto"))
    {
        br_cmd* ifbrcmd = new br_cmd;
        ifbrcmd->is_cond = true;
        ifbrcmd->cond_val = brcondIdx;
        ifbrcmd->br_label_1 = lastStmtsBBIdx;
        int endBBIdx = func->basic_blocks->size();
        ifbrcmd->br_label_2 = endBBIdx;

        //ifBrCmdPtr->br_label_2 = endBBIdx;
        unCondBrCmdPtr->br_label_1 = endBBIdx;

        command* brbbcmd = new command;
        brbbcmd->cmd_type = br;
        brbbcmd->cmd_ptr = (void*) ifbrcmd;
        ifBB->cmds->push_back(brbbcmd);


        //std::reverse_iterator<std::vector<BasicBlock*>::iterator it(func->basic_blocks->end());
    }

    else
    {
        // TODO : ?
    }


    return ;
};*/



void while_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    // 先生成stmt，最后在stmt后添加跳转
    // 记得给continue和break维护全局变量
    int stmtBBIdx = func->basic_blocks->size();
    BasicBlock* stmtBB = new BasicBlock;
    func->basic_blocks->push_back(stmtBB);
    basic_cmds_gen(func,stmtBB,node->children[node->children_num-1]);
    stmtBB = (*func->basic_blocks)[func->basic_blocks->size()-1];

    int condBBIdx = func->basic_blocks->size();
    addUnCondBr(bb,condBBIdx); //非常重要
    continue2BBIdx = condBBIdx;
    //BasicBlock* condBB = new BasicBlock;
    //func->basic_blocks->push_back(condBB);
    for(int i=0; i<node->children_num-1; i++)
    {
        if(!strcmp(node->children[i]->name,"&&"))
        {
            BasicBlock* condBB = new BasicBlock;
            func->basic_blocks->push_back(condBB);
            forAnds(func,condBB,node->children[i],stmtBBIdx);
        }
        else
        {
            BasicBlock* condBB = new BasicBlock;
            func->basic_blocks->push_back(condBB);
            logic_expressions_gen(func,condBB,node->children[i]);
            //local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
            int nextBBIdx = func->basic_blocks->size();
            addCondBr(condBB,stmtBBIdx,nextBBIdx,func->local_var_table->size()-1);
            // TODO:满足跳转到stmt，不满足跳转到下一个条件
            // 需要新基本块
        }
    }
    int nextBBIdx = func->basic_blocks->size();
    break2BBIdx = nextBBIdx;
    addUnCondBr(stmtBB,condBBIdx);
    //给stmt添加跳转



/*    BasicBlock* whileBB=new BasicBlock;
    int whileBBIdx = func->basic_blocks->size();
    func->basic_blocks->push_back(whileBB);
    logic_expressions_gen(func,whileBB,node->children[0]);

    local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];

    int stmtBBIdx = func->basic_blocks->size();
    BasicBlock* stmtBB=new BasicBlock;
    func->basic_blocks->push_back(stmtBB);
    basic_cmds_gen(func,stmtBB,node->children[1]);

    br_cmd* recmd = new br_cmd;
    recmd->is_cond = false;
    recmd->br_label_1 = whileBBIdx;

    command* cmd1  =new command;
    cmd1->cmd_type = br;
    cmd1->cmd_ptr = (void*) recmd;
    stmtBB->cmds->push_back(cmd1);

    int endBBIdx = func->basic_blocks->size();

    br_cmd* whilebrcmd = new br_cmd;
    whilebrcmd->is_cond = true;
    whilebrcmd->cond_val = brcond;
    whilebrcmd->br_label_1 = stmtBBIdx;
    whilebrcmd->br_label_2 = endBBIdx;

    command* brbbcmd = new command;
    brbbcmd->cmd_type = br;
    brbbcmd->cmd_ptr = (void*) whilebrcmd;
    whileBB->cmds->push_back(brbbcmd);
    return ;*/
}

void rtmt_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    
    // cout<<"rtmt:"<<node->children[0]->name;//+
    
    int returnIDx = algo_expressions_gen(bb->cmds,func,node->children[0]);
    // cout<<"returnIDx:"<<returnIDx<<endl;
    
    // %3=add $1,$2
    local_var* returnVar = (*func->local_var_table)[returnIDx];
    // cout<<"returnVar::"<<returnVar;
    ret_cmd* recmd = new ret_cmd;
    //recmd->ret_type = 函数的返回
    // int tttt=returnVar->local_var_type.val_type==func->ret_type;
    // cout<<"111:"<<returnVar->local_var_type.val_type;
    // exit(0);
    if(returnVar->local_var_type.val_type==func->ret_type)
    {
        cout<<"r1";
    // exit(0);
        recmd->ret_value=returnIDx;
    }
    else
    {
      cout<<"r2";
    // exit(0);
        bitcast_cmd* changeCmd = new bitcast_cmd;
        int dstVarIdx = func->local_var_table->size();
        local_var* dstVar = new local_var;
        (*func->local_var_table)[dstVarIdx] = dstVar;
        changeCmd->dst_val = dstVarIdx;
        changeCmd->src_val = returnIDx;
        changeCmd->dst_type = func->ret_type;
        changeCmd->src_type = returnVar->local_var_type.val_type;
        recmd->ret_value = dstVarIdx;

        command* zhuanhuan = new command;
        zhuanhuan->cmd_ptr = (void*) changeCmd;
        zhuanhuan->cmd_type = bitcast;
    }

    

    // TODO:返回值的类型？把returnVar转换成func->ret_type?

    command* fanhui = new command;
    fanhui->cmd_ptr=(void*)recmd;
    fanhui->cmd_type=ret;
    bb->cmds->push_back(fanhui);
    return ;
}

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
          printf("error(AST2IR.906):找不到实参\n");
          // exit(0);
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
          printf("error(AST2IR.980):找不到实参\n");
          // exit(0);
        }
        call_->params.push_back(arg_);
        }
      }


    }

  }


  }

  command* callcmd=new command;
  callcmd->cmd_type=19;
  callcmd->cmd_ptr=call_;
  bb->cmds->push_back(callcmd);

}

void break_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
    addUnCondBr(bb,break2BBIdx);
  return ;
}
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
}

void continue_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
    addUnCondBr(bb,continue2BBIdx);
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
  cout<<arr_type.dimension_size.size();//0
  vector<int>::iterator k = arr_type.dimension_size.begin();

  // arr_type.dimension_size.erase(k);
  // cout<<"kkk";
  exit(0);

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
/*
+
a
b
*/
int algo_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node,int &has_f ){
  
  
  char arg_name[30],arg_name2[30],op_name[30];
  strcpy(arg_name,node->name);
  // cout<<arg_name<<endl;
  int key1,key2;

  if(strcmp(arg_name,"+")==0||strcmp(arg_name,"-")==0||strcmp(arg_name,"/")==0||strcmp(arg_name,"*")==0){
    strcpy(op_name,arg_name);
    // cout<<op_name<<endl;
    // exit(0);
    int has_float=0,has_float2=0;
    cout<<endl<<"l:"<<node->children[0]->name<<endl;
    
    key1=algo_expressions_gen(vcmd, func, node->children[0],has_float);
    
    strcpy(arg_name2,node->children[1]->name);
    cout<<endl<<"r:"<<arg_name2<<endl;//b
    if(regex_match(arg_name2,std::regex("[0-9]+"))){
      key2=-2;
      // return key_1;
    }
    if(key2==-2){
      // 不作处理
    }
    else{
    if(func->is_loaded(arg_name2)){
      // cout<<"h1";
        key2=func->getVarNumLoad(arg_name2);
    }
    else {
      // cout<<"h2";

      key2=func->getVarNumStore(arg_name2);
      // cout<<key2<<endl;//0
      // exit(0);
    // load

    __local_var_value t2;
    type ty2;

    if(func->local_var_table->find(key2)!=func->local_var_table->end()){//若实参为局部变量

          it = func->local_var_table->find(key2);
          ty2=it->second->local_var_type;
          t2=it->second->local_var_value;
          cout<<"1.."<<endl;
          cout<<"r type:"<<ty2.val_type<<endl;
          // exit(0);
        }
    else if(func->local_const_var_table->find(key2)!=func->local_const_var_table->end()){//若实参为局部常变量
          it2=func->local_const_var_table->find(key2);
          ty2=it2->second->global_var_type;
          t2=it2->second->global_var_value;
          cout<<"2.."<<endl;
          // exit(0);

        }
    else if(global_var_table.find(arg_name2)!=global_var_table.end()){//若实参为全局变量
          it3=global_var_table.find(arg_name2);

          ty2=it3->second->global_var_type;
          t2=it3->second->global_var_value;
          cout<<"3.."<<endl;
          // exit(0);

        }
    else if(const_var_table.find(arg_name2)!=const_var_table.end()){//若实参为全局常变量
          it4=const_var_table.find(arg_name2);
          ty2=it4->second->global_var_type;
          t2=it4->second->global_var_value;
          cout<<"4.."<<endl;
          // exit(0);

        }
    else{
          printf("error(AST2IR.1453):找不到实参\n");
          // exit(0);
    }

   
    ty2.val_type=8;
    //若为数组，load取出值
    if(ty2.val_type==i32_ptr){
    
      // cout<<"====12..";
      // exit(0);

     int ptr1= array_offset_gen(func,vcmd,node->children[0],key2,ty2);
      load_cmd* loadcmd=new load_cmd;
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
      cout<<"11..";
      // exit(0);
    }
    else if(ty2.val_type==float_ptr){
    cout<<"====13..";


     has_float2=1;
    int ptr1= array_offset_gen(func,vcmd,node->children[0],key2,ty2);
      load_cmd* loadcmd=new load_cmd;;
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
      command* cmd=new command;
      cmd->cmd_type=2;
      cmd->cmd_ptr=loadcmd;
      vcmd->push_back(cmd);
      key2=loadcmd->dst_val;
      cout<<"12..";
      // exit(0);

    }
    else if(ty2.val_type==9){
      has_float2=1;
    }
  }
  }
// cout<<"has_float:"<<has_float<<" has_float2:"<<has_float2<<endl;
      // exit(0);
    //浮点数和整型一起运算时，整型值需要进行类型提升，转换成浮点数类型

    // cout<<"h1";
    if(key1==-2){
      has_float=has_float2;
    }
    else if(key2==-2){
      has_float2=has_float;
    }

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
      if(key1==-2){
        add->is_val_1=0;
        add->src_val_1=atoi(arg_name);
      }
      else {
        add->is_val_1=1;
        add->src_val_1=key1;
      }

      if(key2==-2){
        add->is_val_2=0;
        add->src_val_2=atoi(arg_name2);
      }
      else {
        add->is_val_2=1;
        add->src_val_2=key2;
      }
      add->src_type=4;
      command* addcmd=new command;
        addcmd->cmd_type=5;
        addcmd->cmd_ptr=add;
        vcmd->push_back(addcmd);
        
        return add->dst_val;
    }
    else if(strcmp(op_name,"-")==0){
       cout<<"132..";

      sub_cmd* sub=new sub_cmd;
      sub->dst_val=func->add_new_var_load(loaddst);
      if(key1==-2){
        sub->is_val_1=0;
        sub->src_val_1=atoi(arg_name);
      }
      else {
        sub->is_val_1=1;
        sub->src_val_1=key1;
      }
      sub->src_type=4;
      
      command* subcmd=new command;
        subcmd->cmd_type=7;
        subcmd->cmd_ptr=sub;
        vcmd->push_back(subcmd);

        

        return sub->dst_val;
    }
    else if(strcmp(op_name,"*")==0){
      mul_cmd* mul=new mul_cmd;
      mul->dst_val=func->add_new_var_load(loaddst);
      if(key1==-2){
        mul->is_val_1=0;
        mul->src_val_1=atoi(arg_name);
      }
      else {
        mul->is_val_1=1;
        mul->src_val_1=key1;
      }
      mul->src_type=4;
      

      command* mulcmd=new command;
        mulcmd->cmd_type=11;
        mulcmd->cmd_ptr=mul;
        vcmd->push_back(mulcmd);
        
        
        
        return mul->dst_val;
    }
    else {
      div_cmd* div=new div_cmd;
      div->dst_val=func->add_new_var_load(loaddst);
      if(key1==-2){
        div->is_val_1=0;
        div->src_val_1=atoi(arg_name);
      }
      else {
        div->is_val_1=1;
        div->src_val_1=key1;
      }
      div->src_type=4;
      

      command* divcmd=new command;
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
        sitofp_cmd* itof=new sitofp_cmd;
        itof->dst_val=func->add_new_var_load(loaddst2);
        itof->src_val=key2;
        command* itofcmd=new command;
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
        sitofp_cmd* itof=new sitofp_cmd;
        itof->dst_val=func->add_new_var_load(loaddst2);
        itof->src_val=key1;
        command* itofcmd=new command;
        itofcmd->cmd_type=17;
        itofcmd->cmd_ptr=itof;
        vcmd->push_back(itofcmd);
      }
    }
    if(strcmp(op_name,"+")==0){
  // %7      = fadd float    %5, %6
  //  dst_val       src_type  src_val_1 src_val_2
      fadd_cmd* fadd=new fadd_cmd;
      fadd->dst_val=func->add_new_var_load(loaddst);
      if(key1==-2){
        fadd->is_val_1=0;
        fadd->src_val_1=atoi(arg_name);
      }
      else {
        fadd->is_val_1=1;
        fadd->src_val_1=key1;
      }
      fadd->src_type=9;
      

      command* faddcmd=new command;
        faddcmd->cmd_type=6;
        faddcmd->cmd_ptr=fadd;
        vcmd->push_back(faddcmd);

        // func->add_new_var_load(loaddst);
        return fadd->dst_val;
    }
    else if(strcmp(op_name,"-")==0){
      fsub_cmd* fsub=new fsub_cmd;
      fsub->dst_val=func->add_new_var_load(loaddst);
      if(key1==-2){
        fsub->is_val_1=0;
        fsub->src_val_1=atoi(arg_name);
      }
      else {
        fsub->is_val_1=1;
        fsub->src_val_1=key1;
      }
      fsub->src_type=9;
      

      command* fsubcmd=new command;
        fsubcmd->cmd_type=8;
        fsubcmd->cmd_ptr=fsub;
        vcmd->push_back(fsubcmd);

        // func->add_new_var_load(loaddst);
        return fsub->dst_val;
    }
    else if(strcmp(op_name,"*")==0){
      fmul_cmd* fmul=new fmul_cmd;
      fmul->dst_val=func->add_new_var_load(loaddst);
      if(key1==-2){
        fmul->is_val_1=0;
        fmul->src_val_1=atoi(arg_name);
      }
      else {
        fmul->is_val_1=1;
        fmul->src_val_1=key1;
      }
      fmul->src_type=9;


      command* fmulcmd=new command;
        fmulcmd->cmd_type=12;
        fmulcmd->cmd_ptr=fmul;
        vcmd->push_back(fmulcmd);

        // func->add_new_var_load(loaddst);
        return fmul->dst_val;
    }
    else {
      fdiv_cmd* fdiv=new fdiv_cmd;
      fdiv->dst_val=func->add_new_var_load(loaddst);
      if(key1==-2){
        fdiv->is_val_1=0;
        fdiv->src_val_1=atoi(arg_name);
      }
      else {
        fdiv->is_val_1=1;
        fdiv->src_val_1=key1;
      }
      fdiv->src_type=9;
    

      command* fdivcmd=new command;
        fdivcmd->cmd_type=10;
        fdivcmd->cmd_ptr=fdiv;
        vcmd->push_back(fdivcmd);

        // func->add_new_var_load(loaddst);
        return fdiv->dst_val;
    }

    }

  
  }
  else{

    int key_1;
    // smatch results;
    if(regex_match(arg_name,std::regex("[0-9]+"))){
      key_1=-2;
      return key_1;
    }
    else if(func->is_loaded(arg_name)){
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
          printf("error(AST2IR.1719):找不到实参\n");
          // exit(0);
    }
    //若为数组，load取出值
    
    if(ty1.val_type==i32_ptr){
     int ptr1= array_offset_gen(func,vcmd,node->children[0],key_1,ty1);
    load_cmd* loadcmd=new load_cmd;
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
      load_cmd* loadcmd=new load_cmd;
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
      command* cmd=new command;
      cmd->cmd_type=2;
      cmd->cmd_ptr=loadcmd;
      vcmd->push_back(cmd);
      key_1=loadcmd->dst_val;

    }
    else if(ty1.val_type==9){
      has_f=1;
    }
  }
    return key_1;
  }

}



void array_offset_gen(syntax_tree_node* node){
  return ;
};
void logic_expressions_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
    int logic_type = isCompLogSta(node->name);
    if(logic_type == 1)
    {
/*
        expression_value(fun,bb,node->children[0]);
        local_var* leftVar;
        int leftIdx = func->local_var_table->size()-1;
        leftvar = (*func->local_var_table)[leftIdx];
        expression_value(fun,bb,node->children[1]);
        local_var* rightVar;
        int rightIdx = func->local_var_table->size()-1;
        rightVar = (*func->local_var_table)[rightIdx];

        */

        int leftIdx = algo_expressions_gen(bb->cmds,func,node->children[0]);
		local_var* leftVar;
        leftVar = (*func->local_var_table)[leftIdx];
        local_var* rightVar;
        int rightIdx = algo_expressions_gen(bb->cmds,func,node->children[1]);
        rightVar = (*func->local_var_table)[rightIdx];

        local_var* cmpValue = new local_var;
        int cmpVIdx = func->local_var_table->size();
        (*func->local_var_table)[cmpVIdx]=cmpValue;
        command* bbcmp = new command;
        if(rightVar->local_var_type.val_type == i32)
        {
            icmp_cmd* icmd = new icmp_cmd;
            icmd->src_val_1 = leftIdx;
            icmd->src_val_2 = rightIdx;
            if(!strcmp(node->name, "=="))
            {
                icmd->cmp_st = eq;
            }
            else if(!strcmp(node->name, "!="))
            {
                icmd->cmp_st = ne;
            }
            else if(!strcmp(node->name, ">="))
            {
                icmd->cmp_st = sge;
            }
            else if(!strcmp(node->name, "<="))
            {
                icmd->cmp_st = sle;
            }
            else if(!strcmp(node->name, ">"))
            {
                icmd->cmp_st = sgt;
            }
            else if(!strcmp(node->name, "<"))
            {
                icmd->cmp_st = slt;
            }
            else
            {
                printf("cmp error\n");
            }
            icmd->dst_val = cmpVIdx;
            bbcmp->cmd_type = icmp;
            bbcmp->cmd_ptr = (void*) icmd;
        }
        else if(rightVar->local_var_type.val_type == float_type)
        {
            fcmp_cmd* fcmd = new fcmp_cmd;
            fcmd->src_val_1 = leftIdx;
            fcmd->src_val_2 = rightIdx;
            if(!strcmp(node->name, "=="))
            {
                fcmd->cmp_st = oeq;
            }
            else if(!strcmp(node->name, "!="))
            {
                fcmd->cmp_st = une;
            }
            else if(!strcmp(node->name, ">="))
            {
                fcmd->cmp_st = oge;
            }
            else if(!strcmp(node->name, "<="))
            {
                fcmd->cmp_st = ole;
            }
            else if(!strcmp(node->name, ">"))
            {
                fcmd->cmp_st = ogt;
            }
            else if(!strcmp(node->name, "<"))
            {
                fcmd->cmp_st = olt;
            }
            else
            {
                printf("cmp error\n");
            }
            fcmd->dst_val = cmpVIdx;
            bbcmp->cmd_type = fcmp;
            bbcmp->cmd_ptr = (void*) fcmd;
        }
        else
        {
            printf("data type error\n");
        }
        bb->cmds->push_back(bbcmp);
    }
    else if(logic_type == 2)
    {
    	logic_expressions_gen(func,bb,node->children[1]);
        local_var* srcVar = new local_var;
        int dstVarIdx = func->local_var_table->size();
        srcVar = (*func->local_var_table)[dstVarIdx-1];
        un_cmd* unCmd = new un_cmd;
        local_var* dstVar = new local_var;
        (*func->local_var_table)[dstVarIdx] = dstVar;
        unCmd->dst_val=dstVarIdx;
        unCmd->src_val=dstVarIdx-1;
        unCmd->src_type=srcVar->local_var_type.val_type;

        command* qufan = new command;
        qufan->cmd_type=un;
        qufan->cmd_ptr=(void*) unCmd;

        bb->cmds->push_back(qufan);

    }
    else if(logic_type == 3)
    {
        printf("这句话不该出现，有bug\n");
        /*logic_expressions_gen(func,bb,node->children[0]);
        local_var* leftLeVar = new local_var;
        int leftLeIdx = func->local_var_table->size()-1;
        leftLeVar = (*func->local_var_table)[leftLeIdx];

        logic_expressions_gen(func,bb,node->children[1]);
        local_var* rightLeVar = new local_var;
        int rightLeIdx = func->local_var_table->size()-1;
        rightLeVar = (*func->local_var_table)[rightLeIdx];


        local_var* lorValue = new local_var;
        command* bbcmp = new command;
        int lorIdx = func->local_var_table->size();
        (*func->local_var_table)[lorIdx]=lorValue;

        //TODO：变量的类型，bool？

        if(!strcmp(node->name, "||"))
        {
            or_cmd* orcmd = new or_cmd;
            orcmd->src_val_1 = leftLeIdx;
            orcmd->src_val_2 = rightLeIdx;
            //orcmd->cmp_st = lor;
            orcmd->dst_val = lorValue;
            bbcmp->cmd_type = lor;
            bbcmp->cmd_ptr = (void*) orcmd;
            bb->cmds->push_back(bbcmp);
        }
        else if(!strcmp(node->name, "&&"))
        {
            and_cmd* andcmd = new and_cmd;
            andcmd->src_val_1 = leftLeIdx;
            andcmd->src_val_2 = rightLeIdx;
            //andcmd->cmp_st = land;
            andcmd->dst_val = landValue;
            bbcmp->cmd_type = land;
            bbcmp->cmd_ptr = (void*) andcmd;
            bb->cmds->push_back(bbcmp);
        }*/
    }
    else
    {
        int midIdx = algo_expressions_gen(bb->cmds,func,node);
        local_var* midVar = new local_var;
        midVar = (*func->local_var_table)[midIdx];
        bitcast_cmd* toBool = new bitcast_cmd;
        local_var* boolVar = new local_var;
        int toboolIdx = func->local_var_table->size();
        (*func->local_var_table)[toboolIdx] = boolVar;

        toBool->dst_val = toboolIdx;
        toBool->dst_type = i1;
        toBool->src_val = midIdx;
        toBool->src_type = midVar->local_var_type.val_type;

        command* cmd2 = new command;
        cmd2->cmd_type = bitcast;
        cmd2->cmd_ptr = (void*) toBool;

        bb->cmds->push_back(cmd2);

    }
    return ;
}

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


/*

.........................................................................l.kk...............................
......................................................................ee..kkk...............................
..................................................................rl.....kkkk...............................
..............................................................al.......kkkkka...............................
................ll..........................................ekkkkkkaikkkkkkkl...............................
.................lk........rl.............................ekkkkkkkkkkkkkkkkkl...............................
..................akkkkkkkkkka.l..aaaea.....rbllllbeaaaaakkkkkkkkkkkkkkkkkkal...............................
...................kkkkkkkkkkkkkkl.aalakrlkaaaablalaaellblkkkkkkkkkeakkkkkilr...............................
....................ikkkkkkkkkkkkkkkbakkkkaealkkkkkkklllllllllkkkleakkkkkkliiiibl...........................
.....................kkkkkkkkkkkaekkkkllllllelllllllllbllllllllleaaakkkkkeaaiiiiiib.........................
......................lkkkkkkkkkkaellllllllllllelllllellbelllbeaaaaaaaaeaaaaakkkiiiikb......................
.......................ekkkkkkkkkkaabllllllbllllllllllllllllalaaaaelaaaaaaaaaak..aiiiiib....................
.........................rlakkkkkkkkaaaaaaallllllllllllllllllaaaaaaaaaaaaaaaak......kiiib...................
.........................biiiaalellllleeaaaallllllllllllllllaaaaaaaaaaaaaaaake.......rkiiib.................
.......................biiiiaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaallllaaakkkkkkb...ikkkiiib................
.....................liiiikkkkkkaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalllaaa...akkkkklkkkkkkkiiil..............
....................biiiikkkk....kakkaaaaaaaaaaaaaaaaaaaaaaaaaakkkkklaal.a....akkkkkkklaakkiiib.............
...................iiiiikkk.......kkkkkkkkkkkkakkkakkkkkkkkkkkkkkkkkli.........llkkkkkkaaaakkiib............
.................aiiiiiikk.......kkkkkkkkkkkka.....kkkkkkkkkkkkkil..................rlkkalaaaaiib...........
................eiiiirikkr......kk....kkkkkkka.....kkr....kkkkl......i..................aaklaaaiib..........
...............biiiibiikkkkaalkraarlkkkkkkkkki......kk..akkkkka..i...........................kaaiib.........
...............iiirliiiki.l...........lkkkkkkk.....kkkkkkkkkkka................................iliik........
..............iiiki...rr.........iiiaa.allakkkkkkkkkkkkkkkkka............................e.......kia........
.............biiila.irl.........................eakkkkkkkkak............................l........klkb.......
............riiibllir............................akkaaaaaal...........................k..........aale.......
............eiiillla...........................aa.llllaaaal...k.....................la..........aaa..e......
...........aiiielll..............................alaaalaaaaa.a....a.............arl...........rraa....a.....
...........biiillae......................aiiiia.llllllllaaaalaa.a..........kleall............iaaa.......e...
...........biillbkkb..........................kallllllaallllllllllaaaaaiarr.aaaklll.......laaaaa.........l..
...........kikbaaakkkb.....................kallllllllllllllllllllblllllaaa.....aa.llraaraaaaaa............l.
...........ibaaaaaaaalllllbrar.aaaaaaaaalllllllllllllllllllllllllllllbaa...........blaaaaaaa...............a
............llaaaaaaelllellllllllllabllllllbbbbbbllllllllbllllllllllba.............k.lll....................
...........iii.......iiiiiiialllllaallllbbllllllllllllllr.lllllb..b.................ablll...................
..........aabaaakkiiikkkklellllllraalllbrallllllllllllbaaaaaar..............b.........blal..................
.........a.aa.baaelllllllllbllllaaaalll.aaabbbblaraaaaa................beellllllllee..bllaa.................
............aaaaablllllllerllllearaaelbrraaaaaaa.....................b................iellaa................
........l......aaaaaaaaaaarllleaaaaaklaa.......................................i......iblaaa................
........k...........aaaaaerrelbkaaa...be.eleeeeea.....................................iil.aaa...............
.........................errrrkkaa....elea...................................r....a...iraaaaa...............
.........................lrrrrkkl....ll...............................................baaaaaaa.............l
........a................aaarrkke..alb......................allkkkkkl................albaaaaaaaaa.........l.
........e.................aakrkkk.......................lkkkkkkkkkkkke...............lllbaaaaaaaaaaa.....l..
.......bi.................aaarkkkba....i..............lkkkkaaaaaaaaaal..............llllabaaaaaaaaaaaaaal...
.......eia.................aaaaakar.a.a................aaaaaaaaaaaaal..............allllllaaaaaaaaaaaaal....
.......eiik.................aaaaaaeia...................laaaaaaaaaal..............lllalllllllaaaaaaaaaal....
.......biila................aaaaaaabai.....................laaaar...............llllellllllllllraaaaaalll...
........iiialk..............aaaaaaaaaelr......................................alllllllllllllllllabrlllllle..
........biiaall............aaaaaaaeaaablll................................lkaaalllllllllllllllllllaelllllla.
.........kiilellal.......aaaaaaaabaaaaabllllla.......................aleaaaabaallllllblllllllllllllllblllll.
.........biilllellla....raaaaaarlaaaaaaablllllllllllkiirrarikaalleeeeleeeaaabaabllllalllllllllllllllllllabl.
..........biklellblllaaiaaaaaaa.laaaaaaaablllllllllllllbaalelllleeeebb.arrrrbaaellllelllllllllllllllllllll..
........bllleillllllbblllelaaaaeaaaaaaaaaabllallllllllllleaaaaarraaaarrarrbleaaablllllllllllllllllllllb.....
......biiaaaaleaalllkrrrrllllllaaaaaalllllaellaaaalllllllllbaaararaarbblllllbaaaaelllllllalllllllll.........
....ikiiaaaaaaiiaaaarrrralllllaaaaaallllllllbllaaaaaaallllllllllalllllllllllaaaaaaeellllllllllab............


 */
