#include "AST2IR.h"

int lastStmtsBBIdx;
//int lastEndBBIdx;

br_cmd* ifBrCmdPtr;

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


//TODO: 所有可能出现在逻辑运算符左右的表达式，包含变量与常量，其值为变量表最后一个
void expression_value(Function* func, BasicBlock* bb, syntax_tree_node* node)
{

}

void local_var_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    local_var* lv =new local_var;
    lv->local_var_type = types_get(node);
    lv->local_var_value = 
    func->local_var_table[func->local_var_table->size()]=lv;
    store_cmd * acmd = new store_cmd;
    command* storeCmd = new command;

    return ;
};

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
    BasicBlock* ifBB=new BasicBlock;
    int ifBBIdx = func->basic_blocks->size();
    func->basic_blocks->push_back(ifBB);
    logic_expressions_gen(func,ifBB,node->children[0]);

    local_var* brcond = func->local_var_table[func->local_var_table->size()-1];

    int stmtBBIdx = func->basic_blocks->size();
    BasicBlock* stmtBB=new BasicBlock;
    func->basic_blocks->push_back(stmtBB);
    basic_blocks_gen(func,stmtBB,node->children[1]);

    int elseBBidx = func->basic_blocks->size();
    BasicBlock* elseBB=new BasicBlock;
    func->basic_blocks->push_back(elseBB);


    br_cmd* ifbrcmd = new br_cmd;
    ifbrcmd->is_cond = true;
    ifbrcmd->cond_val = brcond;
    ifbrcmd->br_label_1 = stmtBBIdx;
    ifbrcmd->br_label_2 = elseBBidx;
    

    command* brbbcmd = new command;
    brbbcmd->cmd_type = br;
    brbbcmd->cmd_ptr = (void*) ifbrcmd;
    ifBB->command->push_back(brbbcmd);
    return ;
};

void if_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    BasicBlock* ifBB=new BasicBlock;
    int ifBBIdx = func->basic_blocks->size();
    func->basic_blocks->push_back(ifBB);
    logic_expressions_gen(func,ifBB,node->children[0]);

    local_var* brcond = func->local_var_table[func->local_var_table->size()-1];

    if(strcmp(node->children[1],"stmts"))
    {
        int stmtBBIdx = func->basic_blocks->size();

        lastStmtsBBIdx = stmtBBIdx;     //更新全局变量

        BasicBlock* stmtBB=new BasicBlock;
        func->basic_blocks->push_back(stmtBB);
        basic_blocks_gen(func,stmtBB,node->children[1]);
        int endBBIdx = func->basic_blocks->size();


        br_cmd* ifbrcmd = new br_cmd;
        ifbrcmd->is_cond = true;
        ifbrcmd->cond_val = brcond;
        ifbrcmd->br_label_1 = stmtBBIdx;
        ifbrcmd->br_label_2 = endBBIdx;
        
        ifBrCmdPtr = ifbrcmd;

        command* brbbcmd = new command;
        brbbcmd->cmd_type = br;
        brbbcmd->cmd_ptr = (void*) ifbrcmd;
        ifBB->command->push_back(brbbcmd);
    }

    else if(strcmp(node->children[1],"goto"))
    {
        br_cmd* ifbrcmd = new br_cmd;
        ifbrcmd->is_cond = true;
        ifbrcmd->cond_val = brcond;
        ifbrcmd->br_label_1 = lastStmtsBBIdx;
        int endBBIdx = func->basic_blocks->size();
        ifbrcmd->br_label_2 = endBBIdx;
        
        ifBrCmdPtr->br_label_2 = endBBIdx;        

        command* brbbcmd = new command;
        brbbcmd->cmd_type = br;
        brbbcmd->cmd_ptr = (void*) ifbrcmd;
        ifBB->command->push_back(brbbcmd);


        //std::reverse_iterator<std::vector<BasicBlock*>::iterator it(func->basic_blocks->end());
/*        bool inflag=0;
        {
            if(inflag==1)
            {
                break;
            }
            for(itcmd:itbb->command)//反向迭代当前基本块中的命令
            {
                if(itcmd->cmd_type!=br)
                {
                    continue;
                }
                br_cmd* itbr = (br_cmd*) itcmd->cmd_ptr;

                if(itbr->br_label_2==lastEndBBIdx)
                {
                    itbr->br_label_2+=1;
                }
                else
                {
                    inflag = 1;
                    break;
                }
            }
        }
        lastEndBBIdx += 1;*/
    }

    else
    {
        // TODO : ?
    }


    return ;
};

void while_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    BasicBlock* whileBB=new BasicBlock;
    int whileBBIdx = func->basic_blocks->size();
    func->basic_blocks->push_back(whileBB);
    logic_expressions_gen(func,whileBB,node->children[0]);

    local_var* brcond = func->local_var_table[func->local_var_table->size()-1];

    int stmtBBIdx = func->basic_blocks->size();
    BasicBlock* stmtBB=new BasicBlock;
    func->basic_blocks->push_back(stmtBB);
    basic_blocks_gen(func,stmtBB,node->children[1]);

    br_cmd* recmd = new br_cmd;
    recmd->is_cond = false;
    recmd->br_label_1 = whileBBIdx;

    command* cmd1  =new command;
    cmd1->cmd_type = br;
    cmd1->cmd_ptr = (void*) recmd;
    stmtBB->command->push_back(cmd1);

    int endBBIdx = func->basic_blocks->size();

    br_cmd* whilebrcmd = new br_cmd;
    whilebrcmd->is_cond = true;
    whilebrcmd->cond_val = brcond;
    whilebrcmd->br_label_1 = stmtBBIdx;
    whilebrcmd->br_label_2 = endBBIdx;
    

    command* brbbcmd = new command;
    brbbcmd->cmd_type = br;
    brbbcmd->cmd_ptr = (void*) whilebrcmd;
    whileBB->command->push_back(brbbcmd);
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
void logic_expressions_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
    int logic_type = isCompLogSta(node->name);
    if(logic_type == 1)
    {
/*
        expression_value(fun,bb,node->children[0]);
        local_var* leftVar;
        int leftIdx = func->local_var_table->size()-1;
        leftvar = func->local_var_table[leftIdx];
        expression_value(fun,bb,node->children[1]);
        local_var* rightVar;
        int rightIdx = func->local_var_table->size()-1;
        rightVar = func->local_var_table[rightIdx];

        */

        int leftIdx = algo_expressions_gen(bb->command,func,node->children[0]);
		local_var* leftVar;
        leftvar = func->local_var_table[leftIdx];
        local_var* rightVar;
        int rightIdx = algo_expressions_gen(bb->command,func,node->children[1]);
        rightVar = func->local_var_table[rightIdx];

        local_var* cmpValue = new local_var;
        int cmpVIdx = func->local_var_table->size();
        func->local_var_table[cmpVIdx]=cmpValue;
        command* bbcmp = new command;
        if(rightVar->local_var_type->val_type == i32)
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
        else if(rightVar->local_var_type->val_type == float_type)
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
        bb->command->push_back(bbcmp);
    }
    else if(logic_type == 2)
    {
    	logic_expressions_gen(func,bb,node->children[1]);

    }
    else if(logic_type == 3)
    {
        logic_expressions_gen(func,bb,node->children[0]);
        local_var* leftLeVar = new local_var;
        int leftLeIdx = func->local_var_table->size()-1;
        leftLeVar = func->local_var_table[leftLeIdx];

        logic_expressions_gen(func,bb,node->children[1]);
        local_var* rightLeVar = new local_var;
        int rightLeIdx = func->local_var_table->size()-1;
        rightLeVar = func->local_var_table[rightLeIdx];


        local_var* lorValue = new local_var;
        command* bbcmp = new command;
        int lorIdx = func->local_var_table->size();
        func->local_var_table[lorIdx]=lorValue;

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
            bb->command->push_back(bbcmp);
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
            bb->command->push_back(bbcmp);
        }
    }
    else
    {
        int midIdx = algo_expressions_gen(bb->command,func,node);
        local_var* midVar = new local_var;
        midVar = func->local_var_table[midIdx];
        bitcast_cmd* toBool = new bitcast_cmd;
        local_var* boolVar = new local_var;
        int toboolIdx = func->local_var_table->size();
        func->local_var_table[toboolIdx] = boolVar;

        toBool->dst_val = toboolIdx;
        toBool->dst_type = i1;
        toBool->src_val = midVar;
        toBool->src_type = midVar->local_var_type->val_type;
        toBool->is_glo_val = false;

        command* cmd2 = new command;
        cmd2->cmd_type = bitcast;
        cmd2->cmd_ptr = (void*) toBool;

    }
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
