#ifndef __INCLUDE_LEX_H_
#define __INCLUDE_LEX_H_

#define MAX_NUM_TOKEN_NODE 4096

typedef enum {
    //运行时库
    GETINT = 100,
    GETCH = 101,
    GETFLOAT = 102,
    GETARRAY = 103,
    GETFARRAY = 104,
    PUTINT = 105,
    PUTCH = 106,
    PUTFLOAT = 107,
    PUTARRAY = 108,
    PUTFARRAY = 109,
    PUTF = 110,
    STARTTIME = 111,
    STOPTIME = 112,
    //运算符
    ADD = 200,
    SUB = 201,
    MUL = 202,
    DIV = 203,
    LT = 204,
    LTE = 205,
    GT = 206,
    GTE = 207,
    EQ = 208,
    NEQ = 209,
    MOD = 210,
    AND = 211,
    OR = 212,
    NOT = 213,
    ASSIGN = 214, //赋值
    //符号
    SEMICOLON = 300, //;
    COMMA = 301, //,
    LPARENTHESE = 302,
    RPARENTHESE = 303, //()
    LBRACKET = 304, //[
    RBRACKET = 305, //]
    LBRACE = 306,
    RBRACE = 307, //{}
    //关键字
    CONST = 400,
    INT = 401,
    FLOAT = 402,
    VOID = 403,
    IF = 404,
    WHILE = 405,
    BREAK = 406,
    ELSE = 407,
    CONTINUE = 408,
    RETURN = 409,
    //ID和NUM
    IDENTIFIER = 500,
    INTEGER = 501,
    FLOATPOINT = 502,
    ARRAY = 503, //[]
    //others
    EOL = 600,
    COMMENT = 601,
    BLANK = 602,
    ERROR = 603,
    COMMENTONELINE = 604,
    CONTROLSTRING = 605
} Sysy_token_type;

typedef struct {
    char text[256];
    int token;
    int lines;
    int pos_start;
    int pos_end;
} Token_Node;

#endif
