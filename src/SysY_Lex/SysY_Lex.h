#ifndef __SYSY_LEX_H_
#define __SYSY_LEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "../../include/includeLex.h"
#include "../../include/createTree.h"
#include "../SysY_Yacc/SysY_Yacc.tab.h"

// int numNode;
// void SysY_lex(char* input_file, Token_Node* token_stream);
int count_num_enter(char *string);

#endif
