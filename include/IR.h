#ifndef __SYSY_IR_H_
#define __SYSY_IR_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

// 联合体value表示当前变量名或者常量
// 举个例子: store i32 5, i32* %1
// value就指 5 以及 %1
// 具体怎么区分是哪个变量在命令结构体中都有对应的bool变量
union value{
  int local_val__const_i32_val; //表示当前是局部变量(%+数字，这里只保留数字)或者整型数值常量
  string global_val; //当前是全局变量
  float const_f_val; //浮点型数值常量

  value(){}
  value(string str){
      global_val=str;
  }
  value(int param){
    local_val__const_i32_val=param;
  }
  value(float param){
    const_f_val=param;
  }
  ~value(){}
};

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
    ptrtoint=19,
    call=20,
    br=21,
    ret=22
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

  type src_type;
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

#endif