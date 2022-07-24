#include "../../include/IR.h"
#include "../AST2IR/AST2IR.h"
#include <fstream>

using std::ofstream;
using std::endl;

extern map<string, global_var*> global_var_table;//全局变量表
extern map<string, const_var*> const_var_table;//全局常量表
extern map<string, Function*> functions_table; //函数表，这里实在想不出来表示方法了

std::ofstream outfile("out.s");
