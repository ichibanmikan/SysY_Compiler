#include "RMLoad.h"

void remove_load(){
  for(auto iter=functions_table.begin(); iter!=functions_table.end(); iter++){
    remove_load_func(iter->second);
  }
}

inline void remove_load_func(Function* func){
  for(int i=0; i<func->basic_blocks->size(); i++){

  }
}
