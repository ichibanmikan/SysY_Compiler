#ifndef __SYSY_IR_H_
#define __SYSY_IR_H_

#include <map>
#include <utility>
#include <string>
#include <vector>
#include <variant>
#include <stack>
#include <bits/stdint-intn.h>
#include <iostream>
#include <string.h>

using std::string;
using std::vector;
using std::map;
using std::variant;
using std::pair;
using std::stack;
using std::cerr;
using std::endl;
using std::cout;
using std::get;
using std::get_if;

// 联合体value表示当前变量名或者常量
// 举个例子: store i32 5, i32* %1
// value就指 5 以及 %1
// 具体怎么区分是哪个变量在命令结构体中都有对应的bool变量
// union value{
//   int local_val__const_i32_val; //表示当前是局部变量(%+数字，这里只保留数字)或者整型数值常量
//   string global_val; //当前是全局变量
//   float const_f_val; //浮点型数值常量

//   value(){}
//   value(string str){
//       global_val=str;
//   }
//   value(int param){
//     local_val__const_i32_val=param;
//   }
//   value(float param){
//     const_f_val=param;
//   }
//   ~value(){}
// };

//对于value我们使用一个和上面联合体等价的variant，方便操作
// typedef variant<int, float, string> value;

//这个local_var_value是局部变量的值
typedef variant<int32_t, float, string, int32_t*, float*, bool, bool*, int8_t, int16_t, int8_t*, int16_t*> __local_var_value;

//全局变量的值
// typedef variant<int32_t, float, int32_t*, float*> __global_var_value;
typedef __local_var_value __global_var_value;
typedef __local_var_value value;

void value_printHelp(value v);

// cmdTypes枚举类型表示所有的命令
enum cmdTypes{
    alloca_c=0,
    store=1,
    load=2,
    getelementptr=3,
    bitcast=4,
    add=5,
    fadd=6,
    sub=7,
    fsub=8,
    div_c=9,
    fdiv=10,
    mul=11,
    fmul=12,
    mod=13,
    fmod=14,
    icmp=15,
    fcmp=16,
    sitofp=17,
    fptosi=18,
    call=19,
    br=20,
    ret=21,
    phi=22,
    lor=23,
    land=24,
    un=25
};

enum logic_state{
  eq=0,
  ne=1,
  sgt=2,
  sge=3,
  slt=4,
  sle=5,
  true_st=6,
  false_st=7,
  oeq=8,
  ogt=9,
  oge=10,
  olt=11,
  ole=12,
  une=13
};

string getCompStateStr(int compState);
// valTypes表示当前是哪种类型的
enum valTypes{
  void_type=0,
  i1=1,
  i8=2,
  i16=3,
  i32=4,
  i1_ptr=5,
  i8_ptr=6,
  i16_ptr=7,
  i32_ptr=8,
  float_type=9,
  float_ptr=10,
  array_ptr=11
};

string getTypeStr(int val_type);

// struct arrayType{
//   int array_type;
//   vector<int> dimension_size;
// };

// union type{
//   int val_type;
//   arrayType array_type;
// };

// type结构体表示当前量的类型，因为要考虑数组所以引入vector，数组维度就是dimension_size.size()
// 因为数组维度未知，不敢直接开数组，直接用了更为安全的vector
struct type{
  int val_type; // 对应枚举类型valTypes
  vector<int> dimension_size; // 数组维度。dimension_size[0] 就代之第一维，以此类推

  type(int valType){
    val_type=valType;
  }
  type(){}

  void printHelp(){
    string typeStr=getTypeStr(val_type);
    if(dimension_size.size()==0){
      cout << typeStr;
    } else {
      for(int i=dimension_size.size()-1; i>=0; i--){
          string strTemp=typeStr;
          typeStr = (dimension_size[i]+'0');
          typeStr += " x ";
          bool b=(i!=dimension_size.size()-1);
          if(b){
              typeStr += '[';
          }
          typeStr += strTemp;
          if(b){
              typeStr += ']';
          }
      }
      cout << '[' << typeStr << ']';
    }
  }
};

struct un_cmd{
  int dst_val;

  int src_type;
  value src_val;
};

// alloca指令
struct alloca_cmd{
  type alloca_type; //需要给变量分配的类型

  int dst_val; //被使用alloca分配的变量只有可能是局部变量，所以直接用int值表示
  int align_len; //注意这里，每个命令都留有一个保留字，代指对齐方式
  void printHelp(){
    cout << '%' << dst_val << " = " << "alloca" << ' ';
    alloca_type.printHelp();
    cout << endl;
  }
};

//store指令，假设把a存到b
// class Function;

struct store_cmd{
  int src_type; //a的类型。a必然是寄存器值，所以不可能是数组

  bool is_val; // 是变量吗
  value src_val; // 可能是浮b点数常量，整型常量或者寄存器变量

  int dst_type; // 是内存中的一个地址，因此不可能是数组类型，而且必是那几个数组类型(ptr)，但指向的有可能是局部变量和全局变量

  bool is_glo_val; // 是全局变量吗
  value dst_val; // 变量名，由is_glo_val指示是否是全局变量
  void printHelp(){
    string src_type_str=getTypeStr(src_type);
    string dst_type_str=getTypeStr(dst_type);
    if(is_val&&is_glo_val){
      cout << "store" << ' ' << src_type_str << " %";
      cout << get<0>(src_val);
      cout << ", " << dst_type_str << " @";
      cout << get<2>(dst_val) << endl;
    } else if(!is_val&&is_glo_val){
      cout << "store" << ' ' << src_type_str << ' ';
      value_printHelp(src_val);
      cout << ", " << dst_type_str << " @";
      cout << get<2>(dst_val) << endl;
    } else if(is_val&&!is_glo_val){
      cout << "store" << ' ' << src_type_str << " %";
      cout << get<0>(src_val);
      cout << ", " << dst_type_str << " %";
      cout << get<0>(dst_val) << endl;
    } else {
      cout << "store" << ' ' << src_type_str << ' ';
      value_printHelp(src_val);
      cout << ", " << dst_type_str << " %";
      cout << get<0>(dst_val) << endl;
    }
  }
};

struct load_cmd{
  int dst_val;
  int dst_type;

  int src_type;
  bool is_glo_val;
  value src_val;

  void printHelp(){
    string dst_type_str=getTypeStr(dst_type);
    string src_type_str=getTypeStr(src_type);
    if(is_glo_val){
      cout << '%' << dst_val << " = " << "load ";
      cout << dst_type_str << ", " << src_type_str;
      cout << " @" << get<2>(src_val) << endl;
    } else {
      cout << '%' << dst_val << " = " << "load ";
      cout << dst_type_str << ", " << src_type_str;
      cout << " %" << get<0>(src_val);
    }
  }
};

struct getelementptr_cmd{
  int dst_val;

  type src_type;
  bool is_global_val;
  value src_val;

  int offset_type;
  int offset;
  getelementptr_cmd(){
    offset_type=i32;
  }
  void printHelp(){
    cout << '%' << dst_val << " = " << "getelementptr inbounds";
    src_type.printHelp();
    cout << ", ";
    src_type.printHelp();
    cout << "* ";
    if(is_global_val){
      cout << '@' << get<2>(src_val);
    } else{
      cout << '%' << get<0>(src_val);
    }
    string str=getTypeStr(offset_type);
    cout << ", " << str << " 0, " << str << ' ' << offset << endl;
  }
};

struct bitcast_cmd{
  int dst_val;

  type src_type;
  int src_val;

  type dst_type;
  void printHelp(){
    cout << '%' << dst_val << " = ";
    cout << "bitcast ";
    src_type.printHelp();
    cout << "* " << '%' << src_val << " to ";
    dst_type.printHelp();
    cout << endl;
  }
};

struct add_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;

  void printHelp(){
    cout << '%' << dst_val << " = " << "add";
    cout << " nsw " << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << src_val_1 << ", %" << src_val_2 << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << src_val_1 << ", " << src_val_2 << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << src_val_1 << ", " << src_val_2 << endl;
    } else {
      cout << src_val_1 << ", %" << src_val_2 << endl;
    }
  }
};

struct and_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
};

struct or_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
};

struct fadd_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;

  void printHelp(){
    cout << '%' << dst_val << " = " << "fadd ";
    cout << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << get<0>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << get<0>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << get<1>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else {
      cout << get<1>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    }
  }
};

struct sub_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
  void printHelp(){
    cout << '%' << dst_val << " = " << "sub";
    cout << " nsw " << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << src_val_1 << ", %" << src_val_2 << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << src_val_1 << ", " << src_val_2 << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << src_val_1 << ", " << src_val_2 << endl;
    } else {
      cout << src_val_1 << ", %" << src_val_2 << endl;
    }
  }
};

struct fsub_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
  void printHelp(){
    cout << '%' << dst_val << " = " << "fsub ";
    cout << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << get<0>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << get<0>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << get<1>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else {
      cout << get<1>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    }
  }
};

struct mul_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
  void printHelp(){
    cout << '%' << dst_val << " = " << "mul";
    cout << " nsw " << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << src_val_1 << ", %" << src_val_2 << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << src_val_1 << ", " << src_val_2 << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << src_val_1 << ", " << src_val_2 << endl;
    } else {
      cout << src_val_1 << ", %" << src_val_2 << endl;
    }
  }
};

struct fmul_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
  void printHelp(){
    cout << '%' << dst_val << " = " << "fmul ";
    cout << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << get<0>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << get<0>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << get<1>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else {
      cout << get<1>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    }
  }
};

struct div_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
  void printHelp(){
    cout << '%' << dst_val << " = " << "sdiv ";
    cout << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << src_val_1 << ", %" << src_val_2 << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << src_val_1 << ", " << src_val_2 << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << src_val_1 << ", " << src_val_2 << endl;
    } else {
      cout << src_val_1 << ", %" << src_val_2 << endl;
    }
  }
};

struct fdiv_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
  void printHelp(){
    cout << '%' << dst_val << " = " << "fdiv ";
    cout << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << get<0>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << get<0>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << get<1>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else {
      cout << get<1>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    }
  }
};

struct mod_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
  void printHelp(){
    cout << '%' << dst_val << " = " << "srem ";
    cout << getTypeStr(src_type) << ' ';
    if(is_val_1&&is_val_2){
      cout << '%' << src_val_1 << ", %" << src_val_2 << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << src_val_1 << ", " << src_val_2<< endl;
    } else if(!is_val_1&&!is_val_2){
      cout << src_val_1 << ", " << src_val_2<< endl;
    } else {
      cout << src_val_1 << ", %" << src_val_2 << endl;
    }
  }
};

struct fmod_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
};
//可能用不到fmod指令

struct icmp_cmd{
  int dst_val; //比较结果只能是局部变量

  int cmp_st; //比较方法

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
  void printHelp(){
    string cmp_st_str=getCompStateStr(cmp_st);
    cout << '%' << dst_val << " = " << "icmp ";
    cout << cmp_st_str << " i32 ";
    if(is_val_1&&is_val_2){
      cout << '%' << src_val_1 << ", %" << src_val_2 << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << src_val_1 << ", " << src_val_2 << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << src_val_1 << ", " << src_val_2 << endl;
    } else {
      cout << src_val_1 << ", %" << src_val_2 << endl;
    }
  }
};

struct fcmp_cmd{
  int dst_val; //只能是局部变量

  int cmp_st; //比较方法

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
  void printHelp(){
    string cmp_st_str=getCompStateStr(cmp_st);
    cout << '%' << dst_val << " = " << "fcmp ";
    cout << cmp_st_str << " float ";
    if(is_val_1&&is_val_2){
      cout << '%' << get<0>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    } else if(is_val_1&&!is_val_2){
      cout << '%' << get<0>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else if(!is_val_1&&!is_val_2){
      cout << get<1>(src_val_1) << ", " << get<1>(src_val_2) << endl;
    } else {
      cout << get<1>(src_val_1) << ", %" << get<0>(src_val_2) << endl;
    }
  }
};

struct sitofp_cmd{
  int dst_val; //一定是寄存器变量

  // bool is_val;
  int src_val; //一定是变量

  void printHelp(){
    cout << '%' << dst_val << " = sitofp i32 %";
    cout << src_val << " to float" << endl;
  }
};

struct fptosi_cmd{
  int dst_val;

  // bool is_val;
  int src_val;
  void printHelp(){
    cout << '%' << dst_val << " = fptosi float %";
    cout << src_val << " to i32" << endl;
  }
};

struct param{
  type param_type;
  bool is_local_val;
  bool is_global_val;
  value param_value;

  void printHelp(){
    param_type.printHelp();
    cout << ' ';
    value_printHelp(param_value);
  }
};

struct call_cmd{
  type ret_type; //返回值类型，先判断是不是为void
  int ret_value; //返回值一定先存储到寄存器变量

  string func_name;
  vector<param> params;

  void printHelp(){
    cout << '%' << ret_value << " = call ";
    ret_type.printHelp();
    cout << '@' << func_name << " (";
    for(int i=0; i<params.size()-1; i++){
      params[i].printHelp();
      cout << ", ";
    }
    params[params.size()-1].printHelp();
    cout << ')' << endl;
  }
};

struct br_cmd{
  bool is_cond; //有条件就是ture, 无条件跳转置为false

  int cond_val; //一定是个i1类型的变量

  int br_label_1; //如果有条件那么条件为真时 或 无条件时 跳转到的基本块号

  int br_label_2; //如果有条件那么条件为假时跳转到的基本块号

  void printHelp(){
    cout << "br ";
    if(is_cond){
      cout << "i1 %" << cond_val << ", label %";
      cout << br_label_1 << ", label %" << br_label_2 << endl;
    } else {
      cout << "label %" << br_label_1 << endl;
    }
  }
};

struct ret_cmd{
  type ret_type;

  value ret_value;
  void printHelp(){
    cout << "ret";
    ret_type.printHelp();
    value_printHelp(ret_value);
    cout << endl;
  }
};

struct phi_cmd{
  int dst_var;

  type dst_type;

  bool is_var_1;
  value src_val_1;

  bool is_var_2;
  value src_val_2;
};
//phi指令 dst_var代表目标变量
//假设基本块1修改了b并重命名为b1 基本块2修改了b并重命名为b2
//基本块1和2是基本块3的前驱基本块
//那么需要重命名一个b3在基本块3，用phi指令选择接受b1还是b2
//dst_type指明了b1b2b3的类型
//其中dst_var就是b3，src_val_1和src_val_2分别对应b1和b2


struct command{
  int cmd_type;
  void* cmd_ptr;
};

void cmd_printHelp(command* cmd);

struct local_var{
  type local_var_type;
  __local_var_value local_var_value;
  pair<int, int> live_span; //存活时间，方便后续进行常量替换等优化

  local_var(){}

  local_var(type varType_,__local_var_value v){
    local_var_type=varType_;
    local_var_value=v;
  }
};

struct global_var{
  type global_var_type;
  __global_var_value global_var_value;

  global_var(){}
  global_var(type varType_,__global_var_value varValue_)
  {
    global_var_type=varType_;
    global_var_value=varValue_;
  }

  void printHelp(){
    global_var_type.printHelp();
    cout << ' ';
    if(global_var_type.dimension_size.size()==0){
      if(get_if<0>(&global_var_value)){
        cout << get<0>(global_var_value);
      } else if(get_if<1>(&global_var_value)){
        cout << get<1>(global_var_value);
      } else {
        cerr << "global var value error 1!!!";
      }
    } else {
      cout << '[';
      int temp=1;
      for(int i=0; i<global_var_type.dimension_size.size(); i++){
        temp*=global_var_type.dimension_size[i];
      }
      if(get_if<3>(&global_var_value)){
        int32_t* glo_int_arr=get<3>(global_var_value);
        cout << '[';
        for(int i=0; i<temp-1; i++){
          cout << glo_int_arr[i] << ", " << endl;
        }
        cout << glo_int_arr[temp-1];
        cout << "] ";
      } else if(get_if<4>(&global_var_value)){
        float* glo_float_arr=get<4>(global_var_value);
        cout << '[';
        for(int i=0; i<temp-1; i++){
          cout << glo_float_arr[i] << ", " << endl;
        }
        cout << glo_float_arr[temp-1];
        cout << "] ";
      } else {
        cerr << "global var value error 2!!!";
      }
      cout << "] ";
    }
  }
};

typedef map<int, local_var*> __local_var_table; //每个函数块一个局部变量表，不同基本块表不同
typedef global_var const_var;
typedef map<int, const_var*> __local_const_var_table;

struct __local_var_index{
  // stack<int> store_index;
  int store_index;
  //栈顶元素代表当前的内存变量号
  //局部变量可以没有内存表示
  /*
    比如
      %8 = icmp ne i32 %7, 0
      br i1 %8, label %9, label %12
    %8就没有
  */
 //没有就用-1表示
 //每新store一次就要压入新的store_index
 //压入内容为local_var_table.size()
 int reg_index;
 //key代指内存形式的变量号
 //value代指被load出来的寄存器形式的变量号

//  int find_reg_index(int key){
//   if(reg_index.find(key)==reg_index.end()){
//     return -1;
//   } else {
//     return reg_index[key];
//   }
//  }

  int find_reg_index(){
    return reg_index;
  }

  __local_var_index(){
    store_index=-1;
    reg_index=-1;
  }
};
//两个int都指代变量号
//初代版本

class BasicBlock;

class Function{
  public:
    int ret_type;
    vector<valTypes>* func_params; //只要记录类型，因为这是函数声明，而不是实际的值
    __local_var_table* local_var_table;
    __local_const_var_table* local_const_var_table;
    vector<BasicBlock*>* basic_blocks;
    map<string, __local_var_index>* local_var_index;
    // map<int, bool>* is_used_var;

    //local_var_index和local_var_table的联系
    //大约是 变量名-变量号-变量值 的关系
    //l_v_i是根据变量名索引得到变量号
    //l_v_t是根据变量号索引得到变量值
    //l_v_i在现阶段用不太着，但是也要填

    int getVarNumStore(string str){
      // return (*local_var_index)[str].store_index.top();
      return (*local_var_index)[str].store_index;
    } //根据变量名获取当前变量的内存变量的变量号

    int getVarNumLoad(string str){
      return (*local_var_index)[str].reg_index;
      // return (*local_var_index)[str].find_reg_index((*local_var_index)[str].store_index.top());
    } //根据变量名获取当前变量的寄存器变量的变量号

    int add_new_var_store(local_var* lv, string var_name){
      local_var_table->insert(pair<int, local_var*>(local_var_table->size()+local_const_var_table->size(), lv));
      __local_var_index lvi;
      lvi.store_index=local_var_table->size()+local_const_var_table->size();
      local_var_index->insert(pair<string, __local_var_index>(var_name, lvi));
      // (*is_used_var)[local_var_table->size()]=false;
      return local_var_table->size()+local_const_var_table->size();
    }
    int add_new_local_var_store(local_var* lv, string var_name){
      int idx=local_var_table->size()+ local_const_var_table->size();
      local_var_table->insert(pair<int, local_var*>(idx, lv));
      __local_var_index lvi;
      lvi.store_index=idx;
      local_var_index->insert(pair<string, __local_var_index>(var_name, lvi));
      // (*is_used_var)[local_var_table->size()]=false;
      return idx;
    }

    int add_new_local_const_var_store(const_var* lcv, string var_name){
      int idx=local_var_table->size()+ local_const_var_table->size();
      local_const_var_table->insert(pair<int, const_var*>(idx, lcv));
      __local_var_index lvi;
      lvi.store_index=idx;
      local_var_index->insert(pair<string, __local_var_index>(var_name, lvi));
      return idx;
    }

    bool is_loaded(string var_name){
      int temp=(*local_var_index)[var_name].find_reg_index();
      if(temp==-1){
        return false;
      } else {
        return true;
      }
    }

    int add_new_var_load(local_var* lv, string var_name){
      int temp=(*local_var_index)[var_name].find_reg_index();
      // (*is_used_var)[(*local_var_index)[var_name].store_index.top()]=true;
      local_var_table->insert(pair<int, local_var*>(local_var_table->size()+local_const_var_table->size(), lv));
      (*local_var_index)[var_name].reg_index=local_var_table->size()+local_const_var_table->size();
      return local_var_table->size()+local_const_var_table->size();
    }

    int add_new_var_load(local_var* lv){
      local_var_table->insert(pair<int, local_var*>(local_var_table->size()+local_const_var_table->size(), lv));
      return local_var_table->size()+local_const_var_table->size();
    }

    Function(){
      func_params=new vector<valTypes>;
      local_var_table=new __local_var_table;
      basic_blocks=new vector<BasicBlock*>;
      local_const_var_table=new __local_const_var_table;
      local_var_index=new map<string, __local_var_index>;
      // is_used_var=new map<int, bool>;
    }
    ~Function(){
      delete func_params;
      delete local_var_table;
      delete basic_blocks;
      delete local_const_var_table;
      delete local_var_index;
      // delete is_used_var;
    }

    void printHelp();
    void local_var_printHelp();
};

extern map<string, global_var*> global_var_table;
extern map<string, const_var*> const_var_table;
extern map<string, Function*> functions_table;

class BasicBlock : public Function{
  public:
    int block_label;
    vector<command*>* cmds;
    vector<string>* changed_vars;
    //这是在这个基本块中记录下变量名
    //这些变量名需要满足的特点：
    /*
      1. 在这个基本块开始之前就被定义过
      2. 在这个基本块中被修改了
      3. 也就是记录store指令或是AST中=结点赋值过的变量
    */
    //记录之后顺便替换掉

    BasicBlock(){
      cmds=new vector<command*>;
    }
    ~BasicBlock(){
      delete cmds;
      delete changed_vars;
    }

    BasicBlock(int a){
      this->block_label=a;
      cmds=new vector<command*>;
    }

    void printHelp(){
      for(int i=0; i<cmds->size(); i++){
        cmd_printHelp((*cmds)[i]);
      }
    }

}; //之所以设置成类是方便我们后续进行机器无关优化，这些优化直接放置到基本块内部



#endif
