#include "IR2ASM.h"

/*
extern map<string, global_var*> global_var_table;//全局变量表
extern map<string, const_var*> const_var_table;//全局常量表
extern map<string, Function*> functions_table; //函数表，这里实在想不出来表示方法了
*/

void IR2ASM(){
  for(auto iter=map<string, global_var*>::iterator; iter!=global_var_table.end(); iter++){
    // cout << iter->first
  }
  for(auto iter=map<string, Function*>::iterator; iter!=functions_table->size(); iter++){
    outfile << iter->first << ':' << endl;
  }
}
