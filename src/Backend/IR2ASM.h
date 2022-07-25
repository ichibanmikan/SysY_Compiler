#include "../../include/IR.h"
#include "../AST2IR/AST2IR.h"
#include <fstream>
#include <string>
#include <map>

using std::ofstream;
using std::endl;
using std::string;
using std::map;
using std::to_string;

extern map<string, global_var*> global_var_table;//全局变量表
extern map<string, const_var*> const_var_table;//全局常量表
extern map<string, Function*> functions_table; //函数表，这里实在想不出来表示方法了

std::ofstream outfile("out.s");

void IR2ASM();
void Function2ASM(Function* func, int funcNum);
void Blocks2ASM(Function* func, map<int, string>* varMM, int funcNum);
void cmds2ASM(BasicBlock* thisBB, map<int, string>* varMM, map<int, int>* regVar, int funcNum);
