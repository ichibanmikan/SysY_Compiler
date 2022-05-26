%option noyywrap
%{


#include "SysY_Lex.h"

int files_count;
int lines;
int pos_start;
int pos_end;

%}

Int int
Else else
If if
Return return
Void void
While while
Float float
Continue continue
Break break
Const const
Getint getint
Getch getch
Getfloat getfloat
Getarray getarray
Getfarray getfarray
Putint putint
Putch putch
Putfloat putfloat
Putarray putarray
Putfarray putfarray
Putf putf
StartTime starttime
StopTime stoptime

%%
\+  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return ADD;}
\-  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return SUB;}
\*  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return MUL;}
\/  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return DIV;}
% {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return MOD;}
\<  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LT;}
\<= {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return LTE;}
\>  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return GT;}
\>= {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return GTE;}
==  {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return EQ;}
!=  {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return NEQ;}
=   {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return ASSIGN;}
\|\| {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return OR;}
&& {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return AND;}
! {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return NOT;}
;   {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return SEMICOLON;}
,   {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return COMMA;}
\(  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LPARENTHESE;}
\)  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return RPARENTHESE;}
\{  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LBRACE;}
\}  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return RBRACE;}
\[  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LBRACKET;}
\]  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return RBRACKET;}
{Else}    {pos_start = pos_end; pos_end += 4; yylval.node = new_syntax_tree_node(yytext); return ELSE;}
{If}  {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return IF;}
{Int} {pos_start = pos_end; pos_end += 3; yylval.node = new_syntax_tree_node(yytext); return INT;}
{Float}   {pos_start = pos_end; pos_end += 5; yylval.node = new_syntax_tree_node(yytext); return FLOAT;}
{Return}  {pos_start = pos_end; pos_end += 6; yylval.node = new_syntax_tree_node(yytext);  return RETURN;}
{Void}    {pos_start = pos_end; pos_end += 4; yylval.node = new_syntax_tree_node(yytext); return VOID;}
{While}   {pos_start = pos_end; pos_end += 5; yylval.node = new_syntax_tree_node(yytext); return WHILE;}
{Continue} {pos_start = pos_end; pos_end += 8; yylval.node = new_syntax_tree_node(yytext); return CONTINUE;}
{Break} {pos_start = pos_end; pos_end += 5; yylval.node = new_syntax_tree_node(yytext); return BREAK;}
{Const} {pos_start = pos_end; pos_end += 5; yylval.node = new_syntax_tree_node(yytext); return CONST;}
{Getint} {pos_start = pos_end; pos_end += 6; yylval.node = new_syntax_tree_node(yytext); return GETINT;}
{Getch} {pos_start = pos_end; pos_end += 5; yylval.node = new_syntax_tree_node(yytext); return GETCH;}
{Getfloat} {pos_start = pos_end; pos_end += 8; yylval.node = new_syntax_tree_node(yytext); return GETFLOAT;}
{Getarray} {pos_start = pos_end; pos_end += 8; yylval.node = new_syntax_tree_node(yytext); return GETARRAY;}
{Getfarray} {pos_start = pos_end; pos_end += 9; yylval.node = new_syntax_tree_node(yytext); return GETFARRAY;}
{Putint} {pos_start = pos_end; pos_end += 6; yylval.node = new_syntax_tree_node(yytext); return PUTINT;}
{Putch} {pos_start = pos_end; pos_end += 5; yylval.node = new_syntax_tree_node(yytext); return PUTCH;}
{Putfloat} {pos_start = pos_end; pos_end += 8; yylval.node = new_syntax_tree_node(yytext); return PUTFLOAT;}
{Putarray} {pos_start = pos_end; pos_end += 8; yylval.node = new_syntax_tree_node(yytext); return PUTARRAY;}
{Putfarray} {pos_start = pos_end; pos_end += 9; yylval.node = new_syntax_tree_node(yytext); return PUTFARRAY;}
{Putf} {pos_start = pos_end; pos_end += 4; yylval.node = new_syntax_tree_node(yytext); return PUTF;}
{StartTime} {pos_start = pos_end; pos_end += 9; yylval.node = new_syntax_tree_node(yytext); return STARTTIME;}
{StopTime} {pos_start = pos_end; pos_end += 8; yylval.node = new_syntax_tree_node(yytext); return STOPTIME;}
[_a-zA-Z]+[_0-9a-zA-Z]*   {pos_start = pos_end; pos_end += strlen(yytext); yylval.node = new_syntax_tree_node(yytext); return IDENTIFIER;}
0[0-7]* {
  pos_start = pos_end; pos_end += strlen(yytext);
  char* str=(char *)malloc(sizeof(char*)*20);
  setNewChar(str, yytext);
  yylval.node = new_syntax_tree_node(InttoString(OcttoDec(str)));
  return INTEGER;
}
[1-9][0-9]*  {
  pos_start = pos_end; pos_end += strlen(yytext);
  yylval.node = new_syntax_tree_node(yytext);
  return INTEGER;
}
0(x|X)[0-9a-fA-F]+ {
  pos_start = pos_end; pos_end += strlen(yytext);
  char* str=(char *)malloc(sizeof(char*)*20);
  setNewChar(str, yytext);
  yylval.node = new_syntax_tree_node(InttoString(HextoDec(str)));
  return INTEGER;
}

(([0-9]*\.[0-9]+|[0-9]+\.|[0-9]+)((e|E)[-+]?([0-9]+))?)   {
  pos_start = pos_end;
  pos_end += strlen(yytext);
  yylval.node = new_syntax_tree_node(yytext);
  return FLOATPOINT;
}

0(x|X)((([0-9a-fA-F]*\.[0-9a-fA-F]+|[0-9a-fA-F]+\.)(P|p)[-+]?([0-9]+))|(([0-9a-fA-F]+)((P|p)[-+]?([0-9]+))?)) {
  pos_start = pos_end;
  pos_end += strlen(yytext);
  yylval.node = new_syntax_tree_node(yytext);
  return FLOATPOINT;
}

\n  {lines++; pos_start = 1; pos_end = 1;}
[ \t]   {pos_start = pos_end; pos_end += 1;}
\/\/\/*.* { yylval.node = new_syntax_tree_node(yytext);}
\"(\\.|[^"\\])*\" {pos_start = pos_end; pos_end += strlen(yytext); yylval.node = new_syntax_tree_node(yytext); return CONTROLSTRING;}

\/\*([^\*]|(\*)*[^\*/])*(\*)*\*\/   {
    pos_start = pos_end;
    int num = count_num_enter(yytext);
    if ( num != 0 ) {
        lines += num;
        pos_end = strlen(strrchr(yytext, '\n'));
    } else {
        pos_end += strlen(yytext);
    }
}

. {return ERROR;}

%%

/*
void SysY_lex(char* input_file, Token_Node* token_stream){
    numNode=0;
    lines = 1;
    pos_start = 1;
    pos_end = 1;
    if(!(yyin = fopen(input_file,"r"))){
        printf("[ERR] No input file\n");
        exit(1);
    }
    printf("[START]: Read from: %s\n", input_file);

    int token;

    while(token = yylex()){
        switch(token){
            case COMMENT:{
                pos_end+=2;
                pos_start=pos_end-2;
                int i=2;
                while(true){
                    if(yytext[i]=='*'&&yytext[i+1]=='/'){
                        pos_end+=2;
                        break;
                    }
                    if(yytext[i]=='\n'){
                        lines++;
                        pos_end=1;
                        pos_start=1;
                    } else {
                        pos_end++;
                    }
                    i++;
                }
            }
            case COMMENTONELINE:
                break;
            case BLANK:
                break;
            case EOL:
                break;
            case ERROR:
                printf("[ERR]: unable to analysize %s at %d line, from %d to %d\n", yytext, lines, pos_start, pos_end);
            default :
                if (token == ERROR){
                    sprintf(token_stream[numNode].text, "[ERR]: unable to analysize %s at %d line, from %d to %d", yytext, lines, pos_start, pos_end);
                } else {
                    strcpy(token_stream[numNode].text, yytext);
                }
                token_stream[numNode].token = token;
                token_stream[numNode].lines = lines;
                token_stream[numNode].pos_start = pos_start;
                token_stream[numNode].pos_end = pos_end;
                numNode++;
                if (numNode >= MAX_NUM_TOKEN_NODE){
                    printf("%s has too many tokens (> %d)", input_file, MAX_NUM_TOKEN_NODE);
                    exit(1);
                }
        }
    }
    printf("[END]: Analysis completed.\n");
    return;
}
//辅助测试函数
*/

int count_num_enter(char *string) {
    int ret = 0;
    int index = 0;
    while(string[index] != '\0') {
        if(string[index] == '\n'){
          ret++;
        }
        index++;
    }
    yylval.node = new_syntax_tree_node(yytext); return ret;
}

int HextoDec(char *str){
	int sum = 0;
	int index = 1;
	if(*str=='-'||*str=='+'){
		if(*str=='-'){
			index = -1;
		}
		str++;
	}

	if((*str=='0') && (*(str+1)=='x'|| *(str+1)=='X')){
		str+=2;
	} else {
		return INT_MAX;
	}

	while(isxdigit(*str)) {
		if(isdigit(*str)) {
			sum = sum*16 + (*str-'0');
		} else if(islower(*str)) {
			sum = sum*16 + (*str-'a'+10);
		} else {
			sum = sum*16 + (*str-'A'+10);
		}
		str++;
	}
	if(*str == '\0'){
    return sum * index;
  }
	return INT_MAX;
}

int OcttoDec(char* text){
  int index=1;
  if(*text=='-'||*text=='+'){
    if(*text=='-'){
      index=-1;
    }
    text++;
  }
  while(*text=='0'){
    text++;
  }
  if(*text=='\0'){
    return 0;
  }
  int sum=0;
  while(*text!='\0'){
    sum=(sum*8+(*text-'0'));
    text++;
  }
  return index*sum;
}


const char* InttoString(int num){
  char *str;
	int i = 0;
	if(num<0){
		num = -num;
		str[0] = '-';
    i++;
	}
	do {
		str[i] = num%10+48;
		num /= 10;
    i++;
	} while(num);
	str[i] = '\0';
	int j = 0;
	if(str[0]=='-'){
		j = 1;
		i++;
	}
	for(;j<i/2;j++){
		str[j] = str[j] + str[i-1-j];
		str[i-1-j] = str[j] - str[i-1-j];
		str[j] = str[j] - str[i-1-j];
	}
  const char* constStr=str;
	return constStr;
}


void setNewChar(char* ch, char* p){
  int i=0;
  while(p[i]!='\0'){
    ch[i]=p[i];
    i++;
  }
}
