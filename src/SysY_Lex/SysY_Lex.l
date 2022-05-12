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
\<  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LT;}
\<= {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return LTE;}
\>  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return GT;}
\>= {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return GTE;}
==  {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return EQ;}
!=  {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return NEQ;}
=   {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return ASSIGN;}
;   {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return SEMICOLON;}
,   {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return COMMA;}
\(  {printf("%d\n", 444); pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LPARENTHESE;}
\)  {printf("%d\n", 555); pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return RPARENTHESE;}
\{  {printf("%d\n", 666); pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LBRACE;}
\}  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return RBRACE;}
\[  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return LBRACKET;}
\]  {pos_start = pos_end; pos_end += 1; yylval.node = new_syntax_tree_node(yytext); return RBRACKET;}
{Else}    {pos_start = pos_end; pos_end += 4; yylval.node = new_syntax_tree_node(yytext); return ELSE;}
{If}  {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return IF;}
{Int} {printf("%d\n", 222); pos_start = pos_end; pos_end += 3; yylval.node = new_syntax_tree_node(yytext); return INT;}
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
[_a-zA-Z]+[_0-9a-zA-Z]*   {printf("%d\n", 333); pos_start = pos_end; pos_end += strlen(yytext); yylval.node = new_syntax_tree_node(yytext); return IDENTIFIER;}
[0-9]+  {pos_start = pos_end; pos_end += strlen(yytext); yylval.node = new_syntax_tree_node(yytext); return INTEGER;}
([0-9]*\.[0-9]+|[0-9]+\.)   {pos_start = pos_end; pos_end += strlen(yytext); yylval.node = new_syntax_tree_node(yytext); return FLOATPOINT;}
\[\]    {pos_start = pos_end; pos_end += 2; yylval.node = new_syntax_tree_node(yytext); return ARRAY;}
\n  {printf("%d\n", 777); lines++; pos_start = 1; pos_end = 1;}
[ \t]   {pos_start = pos_end; pos_end += 1;}
\/\/\/*.* {return COMMENTONELINE;}
\".*\" {pos_start = pos_end; pos_end += strlen(yytext); yylval.node = new_syntax_tree_node(yytext); return CONTROLSTRING;}

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
        if(string[index] == '\n')
            ret++;
        index++;
    }
    yylval.node = new_syntax_tree_node(yytext); return ret;
}















