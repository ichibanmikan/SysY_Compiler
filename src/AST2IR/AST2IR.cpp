#include "AST2IR.h"

//int break2BBIdx;
//int continue2BBIdx;

br_cmd* breakCmdPtr;
br_cmd* continueCmdPtr;

bool ifBreak = false;
bool ifContinue = false;

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
    cerr << "type error !!!" << endl;
    return -1;
}

//添加无条件跳转命令
void addUnCondBr(BasicBlock* bb,int tolabel,int f=0)
{
    br_cmd* recmd = new br_cmd;
    recmd->is_cond = false;
    recmd->br_label_1 = tolabel;

    command* cmd1  =new command;
    cmd1->cmd_type = br;
    cmd1->cmd_ptr = (void*) recmd;
    bb->cmds->push_back(cmd1);

    if(f==1)    //更新全局变量
    {
        breakCmdPtr = recmd;
    }
    else if(f==2)
    {
        continueCmdPtr = recmd;
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

void forAndsBB(Function* func, BasicBlock* condBB, syntax_tree_node* node,int stmtBBIdx)
{
    int nextBBIdx = func->basic_blocks->size();
    int andEndIdx = nextBBIdx+node->children_num-1;
    for(int i=0;i<node->children_num-1; i++)
    {
        // TODO:满足跳到下一个，不满足end
        // 最后一个满足，就跳到stmt
        logic_expressions_gen(func,condBB,node->children[i]);
        //local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
        addCondBr(condBB,nextBBIdx,andEndIdx,func->local_var_table->size()-1);

        BasicBlock* bb = new BasicBlock;
        condBB = bb;
        func->basic_blocks->push_back(condBB);
    }
    nextBBIdx = func->basic_blocks->size();
    logic_expressions_gen(func,condBB,node->children[node->children_num-1]);
    //local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
    addCondBr(condBB,stmtBBIdx,nextBBIdx,func->local_var_table->size()-1);
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
    } else if(!strcmp(node->children[i]->name, "if_else_stmt")){
      if_else_stmt_gen(func, bb, node->children[i]);
    } else {
      call_func_gen(func, bb, node->children[i]);
    }
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
/*void if_else_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    //BasicBlock* ifBB=new BasicBlock;
    ifBB = bb;
    int ifBBIdx = func->basic_blocks->size();
    //func->basic_blocks->push_back(ifBB);
    logic_expressions_gen(func,ifBB,node->children[0]);

    local_var* brcond = (*func->local_var_table)[func->local_var_table->size()-1];
    int brcondIdx = func->local_var_table->size()-1;
    if(!strcmp(node->children[1]->name,"stmts"))
    {
        int stmtBBIdx = func->basic_blocks->size();
        BasicBlock* stmtBB=new BasicBlock;
        func->basic_blocks->push_back(stmtBB);
        basic_cmds_gen(func,stmtBB,node->children[1]);
        stmtBB = (*func->basic_blocks)[func->basic_blocks->size()-1];

        int elseBBidx = func->basic_blocks->size();
        BasicBlock* elseBB=new BasicBlock;
        func->basic_blocks->push_back(elseBB);
        basic_cmds_gen(func,elseBB,node->children[2]);
        elseBB = (*func->basic_blocks)[func->basic_blocks->size()-1];

        //给前面的bb添加跳转
        int nextBBIdx = func->basic_blocks->size();
        addUnCondBr(stmtBB,nextBBIdx);
        addUnCondBr(elseBB,nextBBIdx);


        br_cmd* ifbrcmd = new br_cmd;
        ifbrcmd->is_cond = true;
        ifbrcmd->cond_val = brcondIdx;
        ifbrcmd->br_label_1 = stmtBBIdx;
        ifbrcmd->br_label_2 = elseBBidx;
        
        command* brbbcmd = new command;
        brbbcmd->cmd_type = br;
        brbbcmd->cmd_ptr = (void*) ifbrcmd;
        ifBB->cmds->push_back(brbbcmd);
        return ;
    }
    else if(!strcmp(node->children[1]->name,"goto"))
    {
        int elseBBIdx = func->basic_blocks->size();
        BasicBlock* elseBB=new BasicBlock;
        func->basic_blocks->push_back(elseBB);
        basic_cmds_gen(func,elseBB,node->children[2]);
        int endBBIdx = func->basic_blocks->size();

        br_cmd* ifbrcmd = new br_cmd;
        ifbrcmd->is_cond = true;
        ifbrcmd->cond_val = brcondIdx;
        ifbrcmd->br_label_1 = lastStmtsBBIdx;
        ifbrcmd->br_label_2 = elseBBIdx;
        
        //ifBrCmdPtr->br_label_2 = endBBIdx;
        unCondBrCmdPtr->br_label_1 = endBBIdx;

        command* brbbcmd = new command;
        brbbcmd->cmd_type = br;
        brbbcmd->cmd_ptr = (void*) ifbrcmd;
        ifBB->cmds->push_back(brbbcmd);
        return ;
    }
};*/
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
    //addUnCondBr(bb,condBBIdx); //非常重要
    if(ifContinue)
    {
        ifContinue=false;
        continueCmdPtr->br_label_1 = condBBIdx;
    }
    //continue2BBIdx = condBBIdx;
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
    //break2BBIdx = nextBBIdx;
    //addUnCondBr(stmtBB,condBBIdx);
    if(ifBreak)
    {
        ifBreak=false;
        breakCmdPtr->br_label_1 = nextBBIdx;
    }
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
};

void rtmt_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    int returnIDx = algo_expressions_gen(bb->cmds,func,node->children[0]);
    local_var* returnVar = (*func->local_var_table)[returnIDx];
    ret_cmd* recmd = new ret_cmd;
    //recmd->ret_type = 函数的返回

    if(returnVar->local_var_type.val_type==func->ret_type)
    {
        recmd->ret_value=returnIDx;
    }
    else
    {
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
};
void call_func_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
  return ;
};
void break_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
    ifBreak = true;
    addUnCondBr(bb,break2BBIdx,1);
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
    ifContinue = true;
    addUnCondBr(bb,continue2BBIdx,2);
  return ;
};

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
        toBool->is_glo_val = false;

        command* cmd2 = new command;
        cmd2->cmd_type = bitcast;
        cmd2->cmd_ptr = (void*) toBool;

        bb->cmds->push_back(cmd2);

    }
    return ;
};
int algo_expressions_gen(vector<command*>* vcmd, Function* func, syntax_tree_node* node)
{
    return 0;
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
      cerr << "command error !!!" << endl;
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