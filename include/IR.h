#ifndef __SYSY_IR_H_
#define __SYSY_IR_H_

#include <string>

using std::string;

union value{
  int local_val__const_i32_val;
  string global_val;
  float const_f_val;

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

enum valTypes{
  i1=0,
  i8=1,
  i16=2,
  i32=3,
  i1_ptr=4,
  i8_ptr=5,
  i16_ptr=6,
  i32_ptr=7,
  const_float=8,
  float_ptr=9
};

struct alloca_cmd{
  int alloca_type;
  int dst_val;
  int align_len;
};

struct store_cmd{
  int src_type;

  bool is_val;
  value src_val;

  int dst_type;

  bool is_glo_val;
  value dst_val;
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

  int src_type;

}

#endif
