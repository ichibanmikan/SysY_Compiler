#include "IR2ASM.h"

/*
extern map<string, global_var*> global_var_table;//全局变量表
extern map<string, const_var*> const_var_table;//全局常量表
extern map<string, Function*> functions_table; //函数表，这里实在想不出来表示方法了
*/

void IR2ASM(){
  outfile << "  .global main"
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

  for(auto iter=functions_table.begin(); iter!=functions_table->size(); iter++){
    outfile << iter->first << ':' << endl;
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
