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

int isCompLogSta(char* name)
{
    if(!strcmp(name, "==") || !strcmp(name, "!=") || !strcmp(name, ">=") 
        || !strcmp(name, "<=") || !strcmp(name, ">") || !strcmp(name, "<"))
    {
        return 1;
    }
    if(!strcmp(name, "!"))
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

void qiuzhi(Function* func, BasicBlock* bb, syntax_tree_node* node)
{

}

void local_var_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    local_var* lv =new local_var;
    lv->local_var_type = types_get(node);
    lv->local_var_value = 
    func->local_var_table[func->local_var_table.size()]=lv;
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

void if_stmt_gen(Function* func, BasicBlock* bb, syntax_tree_node* node)
{
    BasicBlock* ifBB=new BasicBlock;
    func->basic_blocks->push_back(ifBB);
    logic_expressions_gen(func,bb,node[0]->children);
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
void logic_expressions_gen(Function* func, BasicBlock* bb, syntax_tree_node* node){
    int logic_type = isCompLogSta(node->name);
    if(logic_type == 1)
    {
        qiuzhi(fun,bb,node->children[0]);
        local_var* leftVar;
        int leftIdx = func->local_var_table.size()-1;
        leftvar = func->local_var_table[leftIdx];
        qiuzhi(fun,bb,node->children[1]);
        local_var* rightVar;
        int rightIdx = func->local_var_table.size()-1;
        rightVar = func->local_var_table[rightIdx];
        local_var* cmpValue = new local_var;
        int cmpVIdx = func->local_var_table.size();
        func->local_var_table[cmpVIdx]=lv;
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
            bbcmp->com_type = icmp;
            bbcmp->cmd_ptr = (void*) icmd;
        }
        else if(rightVar->local_var_type->val_type == float_type)
        {
            fcmp_cmd* fcmd = new fcmp_cmd;
            fcmd->src_val_1 = leftIdx;
            fcmd->src_val_2 = rightIdx;
            if(!strcmp(node->name, "=="))
            {
                fcmd->cmp_st = eq;
            }
            else if(!strcmp(node->name, "!="))
            {
                fcmd->cmp_st = ne;
            }
            else if(!strcmp(node->name, ">="))
            {
                fcmd->cmp_st = sge;
            }
            else if(!strcmp(node->name, "<="))
            {
                fcmd->cmp_st = sle;
            }
            else if(!strcmp(node->name, ">"))
            {
                fcmd->cmp_st = sgt;
            }
            else if(!strcmp(node->name, "<"))
            {
                fcmd->cmp_st = slt;
            }
            else
            {
                printf("cmp error\n");
            }
            fcmd->dst_val = cmpVIdx;
            bbcmp->com_type = fcmp;
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

    }
    else if(logic_type == 3)
    {

    }
    else
    {
        printf("fuck\n");
    }
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
