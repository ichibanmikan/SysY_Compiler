#ifndef __SYSY_IR_H_
#define __SYSY_IR_H_

#include <map>
#include <utility>
#include <string>
#include <vector>
#include <variant>
#include <bits/stdint-intn.h>

using std::string;
using std::vector;
using std::map;
using std::variant;
using std::pair;

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
typedef variant<int, float, string> value;

//这个local_var_value是局部变量的值
typedef variant<bool, int8_t, int16_t, int32_t, float, bool*, int8_t*, int16_t*, int32_t*> __local_var_value;

//全局变量的值
typedef variant<int32_t, float, int32_t*, float*> __global_var_value;

// cmdTypes枚举类型表示所有的命令
enum cmdTypes{
    alloca_cmd=0,
    store=1,
    load=2,
    getelementptr=3,
    bitcast=4,
    add=5,
    fadd=6,
    sub=7,
    fsub=8,
    div_cmd=9,
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
    ret=21
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
  type(){

  }
};

// alloca指令
struct alloca_cmd{
  type alloca_type; //需要给变量分配的类型

  int dst_val; //被使用alloca分配的变量只有可能是局部变量，所以直接用int值表示
  int align_len; //注意这里，每个命令都留有一个保留字，代指对齐方式
};

//store指令，假设把a存到b
struct store_cmd{
  int src_type; //a的类型。a必然是寄存器值，所以不可能是数组

  bool is_val; // 是变量吗
  value src_val; // 可能是浮点数常量，整型常量或者寄存器变量

  int dst_type; // 是内存中的一个地址，因此不可能是数组类型，而且必是那几个数组类型(ptr)，但指向的有可能是局部变量和全局变量

  bool is_glo_val; // 是全局变量吗
  value dst_val; // 变量名，由is_glo_val指示是否是全局变量
};

struct load_cmd{
  int dst_val;
  int dst_type;

  int src_type;
  bool is_glo_val;
  value src_val;
};

struct getelementptr_cmd{
  int dst_val;

  int src_type;
  value src_val;

  int offset_type;
  int offset;
  getelementptr_cmd(){
    offset_type=i32;
  }
};

struct bitcast_cmd{
  int dst_val;

  type src_type;
  bool is_glo_val;
  int src_val;

  type dst_type;
};

struct add_cmd{
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
};

struct sub_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
};

struct fsub_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
};

struct mul_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
};

struct fmul_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
};

struct div_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
};

struct fdiv_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
};

struct mod_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
};

struct fmod_cmd{
  int dst_val;

  int src_type;

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
};

struct icmp_cmd{
  int dst_val; //比较结果只能是局部变量

  int cmp_st; //比较方法

  bool is_val_1;
  int src_val_1;

  bool is_val_2;
  int src_val_2;
};

struct fcmp_cmd{
  int dst_val; //只能是局部变量

  int cmp_st; //比较方法

  bool is_val_1;
  value src_val_1;

  bool is_val_2;
  value src_val_2;
};

struct sitofp_cmd{
  int dst_val; //一定是寄存器变量

  bool is_val;
  int src_val;
};

struct fptosi_cmd{
  int dst_val;

  bool is_val;
  value src_val;
};

struct param{
  type param_type;
  bool is_local_val;
  bool is_global_val;
  value param_value;
};

struct call_cmd{
  type ret_type; //返回值类型，先判断是不是为void
  int ret_value; //返回值一定先存储到寄存器变量

  string func_name;
  vector<param> params;
};

struct br_cmd{
  bool is_cond; //有条件就是ture, 无条件跳转置为false

  int cond_val; //一定是个i1类型的变量

  int br_label_1; //如果有条件那么条件为真时 或 无条件时 跳转到的基本块号

  int br_label_2; //如果有条件那么条件为假时跳转到的基本块号
};

struct ret_cmd{
  type ret_type;

  value ret_value;
};

struct command{
  int cmd_type;
  void* cmd_ptr;
};

struct local_var{
  type local_var_type;
  __local_var_value local_var_value;
  pair<int, int> live_span; //存活时间，方便后续进行常量替换等优化
};

struct global_var{
  type global_value;
  __global_var_value global_var_value;
};

typedef map<int, local_var*> __local_var_table; //每个函数块一个局部变量表，不同基本块表不同
typedef global_var const_var;
typedef map<int, const_var*> __local_const_var_table;

class BasicBlock;

class Function{
  public:
    int ret_type;
    vector<valTypes>* func_params; //只要记录类型，因为这是函数声明，而不是实际的值
    __local_var_table* local_var_table;
    __local_const_var_table* local_const_var_table;
    vector<BasicBlock*>* basic_blocks;

    Function(){
      func_params=new vector<valTypes>;
      local_var_table=new __local_var_table;
      basic_blocks=new vector<BasicBlock*>;
    }
    ~Function(){
      delete func_params;
      delete local_var_table;
      delete basic_blocks;
    }
};

extern map<string, global_var*> global_var_table;
extern map<string, const_var*> const_var_table;
extern map<string, Function*> functions_table;

class BasicBlock : public Function{
  public:
    int block_label;
    vector<command*>* cmds;

  BasicBlock(){
    cmds=new vector<command*>;
  }
  ~BasicBlock(){
    delete cmds;
  }
}; //之所以设置成类是方便我们后续进行机器无关优化，这些优化直接放置到基本块内部

#endif
