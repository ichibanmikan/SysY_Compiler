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
        break;
      }
      case 2:{
        load_cmd* lc=(load_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int regNum=getReg(lc->dst_val, regVar);
        if(lc->is_glo_val){
          outfile << "  ldr r" << regNum << ", " << get<2>(lc->src_val) << endl;
        } else {
          outfile << "  ldr, r" << regNum << ", " << (*varMM)[get<0>(lc->src_val)] << endl;
        }
      }
      case 3:{
        getelementptr_cmd* gc=(getelementptr_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int regNum=getReg(gc->dst_val, regVar);
        if(gc->is_var){
          int offsetRegNum=getReg(gc->offset, regVar);
          outfile << "  mov r" << regNum << ", r" << offsetRegNum << ", LSL #2" << endl;
        } else {
          int offsetRegNum=IntsetReg(gc->offset, regVar);
          outfile << "  mov r" << regNum << ", r" << offsetRegNum << ", LSL #2" << endl;
        }
      }
      case 4:{
        bitcast_cmd* bc=(bitcast_cmd*)(*thisBB->cmds)[i]->cmd_ptr;

      }
      case 5:{
        add_cmd* ac=(add_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int var_1_regNum;
        int var_2_regNum;
        int dst_regNum=getReg(ac->dst_val, regVar);
        if(ac->is_val_1){
          var_1_regNum=getReg(ac->src_val_1, regVar);
        } else {
          var_1_regNum=IntsetReg(ac->src_val_1, regVar);
        }
        if(ac->is_val_2){
          var_2_regNum=getReg(ac->src_val_2, regVar);
        } else {
          var_2_regNum=IntsetReg(ac->src_val_2, regVar);
        }
        outfile << "  add r" << dst_regNum << ", r" << var_1_regNum << ", r" << var_2_regNum << endl;
      }
      case 6:{
        fadd_cmd* fac=(fadd_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int var_1_regNum;
        int var_2_regNum;
        int dst_regNum=getReg(fac->dst_val, regVar);
        if(fac->is_val_1){
          var_1_regNum=getReg(get<0>(fac->src_val_1), regVar);
        } else {
          var_1_regNum=FloatsetReg(get<1>(fac->src_val_1), regVar);
        }
        if(fac->is_val_2){
          var_2_regNum=getReg(get<0>(fac->src_val_2), regVar);
        } else {
          var_2_regNum=FloatsetReg(get<1>(fac->src_val_2), regVar);
        }
        outfile << "  add r" << dst_regNum << ", r" << var_1_regNum << ", r" << var_2_regNum << endl;
      }
      case 7:{
        sub_cmd* subc=(sub_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int var_1_regNum;
        int var_2_regNum;
        int dst_regNum=getReg(subc->dst_val, regVar);
        if(subc->is_val_1){
          var_1_regNum=getReg(subc->src_val_1, regVar);
        } else {
          var_1_regNum=IntsetReg(subc->src_val_1, regVar);
        }
        if(subc->is_val_2){
          var_2_regNum=getReg(subc->src_val_2, regVar);
        } else {
          var_2_regNum=IntsetReg(subc->src_val_2, regVar);
        }
        outfile << "  sub r" << dst_regNum << ", r" << var_1_regNum << ", r" << var_2_regNum << endl;
      }
      case 8:{
        fsub_cmd* ac=(fsub_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int var_1_regNum;
        int var_2_regNum;
        int dst_regNum=getReg(ac->dst_val, regVar);
        if(ac->is_val_1){
          var_1_regNum=getReg(get<0>(ac->src_val_1), regVar);
        } else {
          var_1_regNum=FloatsetReg(get<1>(ac->src_val_1), regVar);
        }
        if(ac->is_val_2){
          var_2_regNum=getReg(get<0>(ac->src_val_2), regVar);
        } else {
          var_2_regNum=FloatsetReg(get<1>(ac->src_val_2), regVar);
        }
        outfile << "  sub r" << dst_regNum << ", r" << var_1_regNum << ", r" << var_2_regNum << endl;
      }
      case 9:{
        div_cmd* ac=(div_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        if(ac->is_val_1){
          int var_1_regNum=getReg(ac->src_val_1, regVar);
          outfile << "  mov r" << var_1_regNum << ", r0";
        } else {
          IntsetSpiReg(ac->src_val_1, 0, regVar);
        }
        if(ac->is_val_2){
          int var_2_regNum=getReg(ac->src_val_2, regVar);
          outfile << "  mov r" << var_2_regNum << ", r1";
        } else {
          IntsetSpiReg(ac->src_val_2, 1, regVar);
        }
        outfile << "  bl      __aeabi_idiv" << endl;
        VarSetSpiReg(ac->dst_val, 0, regVar);
      }
      case 10:{
        fdiv_cmd* ac=(fdiv_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        if(ac->is_val_1){
          int var_1_regNum=getReg(get<0>(ac->src_val_1), regVar);
          outfile << "  mov r" << var_1_regNum << ", r0";
        } else {
          FloatsetSpiReg(get<1>(ac->src_val_1), 0, regVar);
        }
        if(ac->is_val_2){
          int var_2_regNum=getReg(get<0>(ac->src_val_2), regVar);
          outfile << "  mov r" << var_2_regNum << ", r1";
        } else {
          FloatsetSpiReg(get<1>(ac->src_val_2), 1, regVar);
        }
        outfile << "  bl      __aeabi_idiv" << endl;
        VarSetSpiReg(ac->dst_val, 0, regVar);
      }
      case 11:{
        mul_cmd* ac=(mul_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int var_1_regNum;
        int var_2_regNum;
        int dst_regNum=getReg(ac->dst_val, regVar);
        if(ac->is_val_1){
          var_1_regNum=getReg(ac->src_val_1, regVar);
        } else {
          var_1_regNum=IntsetReg(ac->src_val_1, regVar);
        }
        if(ac->is_val_2){
          var_2_regNum=getReg(ac->src_val_2, regVar);
        } else {
          var_2_regNum=IntsetReg(ac->src_val_2, regVar);
        }
        outfile << "  mul r" << dst_regNum << ", r" << var_1_regNum << ", r" << var_2_regNum << endl;
      }
      case 12:{
        fmul_cmd* ac=(fmul_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
        int var_1_regNum;
        int var_2_regNum;
        int dst_regNum=getReg(ac->dst_val, regVar);
        if(ac->is_val_1){
          var_1_regNum=getReg(get<0>(ac->src_val_1), regVar);
        } else {
          var_1_regNum=FloatsetReg(get<1>(ac->src_val_1), regVar);
        }
        if(ac->is_val_2){
          var_2_regNum=getReg(get<0>(ac->src_val_2), regVar);
        } else {
          var_2_regNum=FloatsetReg(get<1>(ac->src_val_2), regVar);
        }
        outfile << "  mul r" << dst_regNum << ", r" << var_1_regNum << ", r" << var_2_regNum << endl;
      }
      case 13:{
        mod_cmd* ac=(mod_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 14:{
        fmod_cmd* ac=(fmod_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 15:{
        icmp_cmd* ac=(icmp_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 16:{
        fcmp_cmd* ac=(fcmp_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 17:{
        sitofp_cmd* ac=(sitofp_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 18:{
        fptosi_cmd* ac=(fptosi_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 19:{
        call_cmd* ac=(call_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 20:{
        br_cmd* ac=(br_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
      case 21:{
        ret_cmd* ac=(ret_cmd*)(*thisBB->cmds)[i]->cmd_ptr;
      }
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

void VarSetSpiReg(int varNum, int regNum, map<int, int>* regVar){
  (*regVar)[regNum]=varNum;
  stackPos=regNum+1;
  if(stackPos>7){
    stackPos=0;
  }
}

void IntsetSpiReg(int num, int regNum, map<int, int>* regVar){
  outfile << "  mov r" << regNum << ", #" << num;
  (*regVar)[regNum]=-2;
  stackPos=regNum+1;
  if(stackPos>7){
    stackPos=0;
  }
}

void FloatsetSpiReg(float num, int regNum, map<int, int>* regVar){
  outfile << "  mov r" << regNum << ", #" << num;
  (*regVar)[regNum]=-2;
  stackPos=regNum+1;
  if(stackPos>7){
    stackPos=0;
  }
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
