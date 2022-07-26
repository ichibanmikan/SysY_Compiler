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
  regVar->insert(pair<int, int>(0, -2));
  regVar->insert(pair<int, int>(1, -2));
  regVar->insert(pair<int, int>(2, -2));
  regVar->insert(pair<int, int>(3, -2));
  cmds2ASM((*func->basic_blocks)[0], varMM, regVar, funcNum);
  for(int i=1; i<func->basic_blocks->size(); i++){
    outfile << "LBB" << funcNum << '_' << i << ':' << endl;
    cmds2ASM((*func->basic_blocks)[i], varMM, regVar, funcNum);
  }
}

void cmds2ASM(BasicBlock* thisBB, map<int, string>* varMM, map<int, int>* regVar, int funcNum){
  for(int i=0; i<thisBB->cmds->size(); i++){
    switch((*thisBB->cmds)[i]->cmd_type){
      case 0:{
        break;
      }
      case 1:{
        store_cmd* scTemp=(store_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        if(scTemp->is_val){
          int reg_src=getReg(get<0>(scTemp->src_val), regVar);
          if(scTemp->is_glo_val){
            string gloLabel=get<2>(scTemp->dst_val);
            outfile << "  str r" << reg_src << ", " << gloLabel << endl;
          } else {
            outfile << "  str r" << reg_src << ", " << (*varMM)[get<0>(scTemp->dst_val)] << endl;
          }
        } else{
          if(scTemp->src_type==i32){
            int numReg=IntsetReg(get<0>(scTemp->src_val), regVar);
            if(scTemp->is_glo_val){
              string gloLabel=get<2>(scTemp->dst_val);
              outfile << "  str r" << numReg << ", " << gloLabel << endl;
            } else {
              outfile << "  str r" << numReg << ", " << (*varMM)[get<0>(scTemp->dst_val)] << endl;
            }
          } else if(scTemp->src_type==float_type){
            int numReg=FloatsetReg(get<1>(scTemp->src_val), regVar);
            if(scTemp->is_glo_val){
              string gloLabel=get<2>(scTemp->dst_val);
              outfile << "  str r" << numReg << ", " << gloLabel << endl;
            } else {
              outfile << "  str r" << numReg << ", " << (*varMM)[get<0>(scTemp->dst_val)] << endl;
            }
          } else {
            cerr << "IR2ASM const num error" << endl;
          }
        }
      }
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      default:
        cerr << "IR2ASM cmd Type error!!!" << endl;
    }
  }
}

int stackPos=0;

int IntsetReg(int num, map<int, int>* regVar){
  outfile << "  mov r";
  if(regVar->size()<8){
    outfile << regVar->size()-1 << ", #" << num;
    regVar->insert(pair<int, int>(regVar->size()-1, -2));
    return regVar->size()-1;
  } else {
    outfile << stackPos << ", #" << num;
    int retTemp=stackPos;
    (*regVar)[stackPos]=-2;
    if(stackPos==7){
      stackPos=0;
    } else {
      stackPos++;
    }
    return retTemp;
  }
}

int FloatsetReg(float num, map<int, int>* regVar){
  outfile << "  mov r";
  if(regVar->size()<8){
    outfile << regVar->size()-1 << ", #" << num;
    regVar->insert(pair<int, int>(regVar->size()-1, -2));
    return regVar->size()-1;
  } else {
    outfile << stackPos << ", #" << num;
    int retTemp=stackPos;
    (*regVar)[stackPos]=-2;
    if(stackPos==7){
      stackPos=0;
    } else {
      stackPos++;
    }
    return retTemp;
  }
}

int getReg(int varNum, map<int, int>* regVar){
  for(auto iter=regVar->begin(); iter!=regVar->end(); iter++){
    if(iter->second==varNum){
      return iter->first;
    }
  }
  return VarSetNewReg(varNum, regVar);
}

int VarSetNewReg(int varNum, map<int, int>* regVar){
  (*regVar)[stackPos]=varNum;
  int retTemp=stackPos;
  if(stackPos==7){
    stackPos=0;
  } else {
    stackPos++;
  }
  return retTemp;
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
