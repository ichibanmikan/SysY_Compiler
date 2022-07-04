# 优化部分

## 去除多余load

我们在实现IR的时候由于分类实现，大家在拿到自己那部分的IR的时候都会重新load一次，我们首先要把这些多余的load去掉

## 指令扩展

### select

在第一层IR我们实现了基本块，每个基本块最终都对应一个终止语句

当终止语句为br时，我们可以考虑直接注销两个基本块，改用更加快速的select指令

```c++
int a=1;
int b=2;
if(a==b){
 return b+2;
} else {
 return b-2;
}
```

初代IR

```assembly
%1 = alloca i32
%2 = alloca i32

%3 = load i32, i32* %1
%4 = load i32, i32* %2

%5 = icmp eq i32 %3, i32 %4
br i1 %5, label %6, label %9

6:
 %7 = load i32, i32* %2
 %8 = add nsw i32 %7, i32 2
 ret i32 %8
9:
 %10 = load i32, i32* %2
 %11 = sub nsw i32 %10, i32 2
 ret i32 %11
```

可以转化为

```assembly
%1 = alloca i32
%2 = alloca i32

%3 = load i32, i32* %1
%4 = load i32, i32* %2

%5 = icmp eq i32 %3, i32 %4

%6 = select i1 %5, i32 2, i32 -2;
%7 = add nsw i32 %6, i32 2

ret i32 %7
```

### phi

## 转换为SSA
