#ifndef __SYSY_LEX_H_
#define __SYSY_LEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
// #include "../../include/includeLex.h"
#include "../../include/createTree.h"
#include "../SysY_Yacc/SysY_Yacc.tab.h"

#define INT_MAX 2147483647

// int numNode;
// void SysY_lex(char* input_file, Token_Node* token_stream);
int count_num_enter(char *string);
int HextoDec(char *str);
int OcttoDec(char* text);
const char* InttoString(int num);
void setNewChar(char* ch, char* p);

#endif
