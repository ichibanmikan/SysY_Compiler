#include "IR2ASM.h"

/*
extern map<string, global_var*> global_var_table;//全局变量表
extern map<string, const_var*> const_var_table;//全局常量表
extern map<string, Function*> functions_table; //函数表，这里实在想不出来表示方法了
*/

void IR2ASM(){
  outfile << "  .global main";
  for(auto iter=global_var_table.begin(); iter!=global_var_table.end(); iter++){
    outfile << iter->first << ':' << endl;

    if(iter->second->global_var_type.dimension_size.size()==0){
      outfile << "  .long   ";
      if(get_if<0>(&iter->second->global_var_value)){
        outfile << get<0>(iter->second->global_var_value);
      } else if(get_if<1>(&iter->second->global_var_value)){
        outfile << get<1>(iter->second->global_var_value);
      } else {
        cerr << "IR2ASM() global var value error 1!!!";
      }
      outfile << endl;
    } else {
      int numSize=0;
      for(int j=0; j<iter->second->global_var_type.dimension_size.size(); j++){
        numSize+=iter->second->global_var_type.dimension_size[j];
      }

      if(get_if<3>(&iter->second->global_var_value)){
        int32_t* glo_int_arr=get<3>(iter->second->global_var_value);
        for(int j=0; j<numSize; j++){
          outfile << "  .long   " << glo_int_arr[j] << endl;
        }
      } else if(get_if<4>(&iter->second->global_var_value)){
        float* glo_float_arr=get<4>(iter->second->global_var_value);
        for(int j=0; j<numSize; j++){
          outfile << "  .long   " << glo_float_arr[j] << endl;
        }
      } else {
        cerr << "IR2ASM global var value error 2!!!";
      }
    }

  }

  int funcNum=0;
  for(auto iter=functions_table.begin(); iter!=functions_table.end(); iter++){
    outfile << iter->first << ':' << endl;
    funcNum++;
    Function2ASM(iter->second, funcNum);
  }
}

void Function2ASM(Function* func, int funcNum){
  // outfile << "  sub   sp, sp, #" << func->func_params->size()*4 << endl;
  map<int, string>* varMM=new map<int, string>;
  int sum=func->func_params->size();
  int num=0;
  for(auto iter=func->local_var_index->begin(); iter!=func->local_var_index->end(); iter++){
    if(iter->second.store_index!=-1){
      string varPos="[sp, #";
      varPos+=to_string(num*4);
      varPos+=']';
      varMM->insert(pair<int, string>(iter->second.store_index, varPos));
      num++;
    }
  }
  sum+=num;
  outfile << "  sub   sp, sp, #" << (sum-1)*4 << endl;
  if(func->func_params->size()<=4){
    for(int i=0; i<func->func_params->size(); i++){
      outfile << "  str r" << i << " [sp, #" << (sum-i-1)*4 << endl;
    }
  }
  Blocks2ASM(func, varMM, funcNum);
}

void Blocks2ASM(Function* func, map<int, string>* varMM, int funcNum){
  map<int, int>* regVar=new map<int, int>;
  cmds2ASM((*func->basic_blocks)[0], varMM, regVar, funcNum);
  for(int i=1; i<func->basic_blocks->size(); i++){
    outfile << "LBB" << funcNum << '_' << i << endl;
    cmds2ASM((*func->basic_blocks)[i], varMM, regVar, funcNum);
  }
}

void cmds2ASM(BasicBlock* thisBB, map<int, string>* varMM, map<int, int>* regVar, int funcNum){
  for(int i=0; i<thisBB->cmds->size(); i++){
    switch((*thisBB->cmds)[i]->cmd_type){
      case 1:
        return ;
      case 2:
        return ;
    }
  }
}

int getReg(int varNum, map<int, int>* regVar){
  for(auto iter=regVar->begin(); iter!=regVar->end(); iter++){
    if(iter->second==varNum){
      return iter->first;
    }
  }
  return -1;
}

/*
	.text
	.global a
a:
	.long 10

	.global b
b:
	.long 2
	.global main
main:

*/
