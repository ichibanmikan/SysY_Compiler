%{
#include "SysY_Yacc.h"

// external functions from lex
extern int yylex();
extern FILE* yyin;
// external variables from lexical_analyzer module
extern int lines;
extern char *yytext;
extern int pos_end;
extern int pos_start;
extern void yyrestart  (FILE * input_file );

// Global syntax tree
syntax_tree *gt;

// Error reporting
void yyerror(const char *s);

// Helper functions written for you with love
syntax_tree_node *node(const char *node_name, int children_num, ...);
%}


%union {
    syntax_tree_node* node;
}


%start program
%token <node> ADD SUB MUL DIV LT LTE GT GTE EQ NEQ AND OR NOT MOD ASSIGN SEMICOLON COMMA LPARENTHESE RPARENTHESE LBRACKET RBRACKET LBRACE RBRACE ELSE IF INT FLOAT RETURN VOID WHILE IDENTIFIER INTEGER FLOATPOINT ARRAY LETTER EOL COMMENT BLANK ERROR CONTINUE BREAK CONST COMMENTONELINE GETINT GETCH GETFLOAT GETARRAY GETFARRAY PUTINT PUTCH PUTFLOAT PUTARRAY PUTFARRAY PUTF STARTTIME STOPTIME CONTROLSTRING
%type <node> program
%type <node> type_specifier relop addop mulop logiclop
%type <node> declaration_list declaration var_declaration fun_declaration local_declarations local_declartion_assignment
%type <node> compound_stmt statement_list statement expression_stmt iteration_stmt selection_stmt return_stmt
%type <node> expression simple_expression logic_expression var additive_expression term factor integer float call calllib
%type <node> params param_list param args arg_list array_size

%%
/* TODO: Your rules here. */

program : declaration_list {
            $$ = node("program", 1, $1);
            gt->root = $$;
        }
declaration_list : declaration_list declaration {
                    $$ = node("declaration_list", 2, $1, $2);
                 }
                 | declaration {
                     $$ = node("declaration_list", 1, $1);
                 }
declaration : var_declaration {
                $$ = node("declaration", 1, $1);
            }
            |fun_declaration {
                $$ = node("declaration", 1, $1);
            }
var_declaration : CONST type_specifier IDENTIFIER SEMICOLON{
                    $$ = node("var_declaration", 4, $1, $2, $3, $4);
                }
                |CONST type_specifier IDENTIFIER array_size SEMICOLON{
                    $$ = node("var_declaration", 5, $1, $2, $3, $4, $5);
                }
                |type_specifier IDENTIFIER SEMICOLON {
                    $$ = node("var_declaration", 3, $1, $2, $3);
                }
                |type_specifier IDENTIFIER array_size SEMICOLON{
                    $$ = node("var_declaration", 4, $1, $2, $3, $4);
                }
type_specifier : INT {
                    $$ = node("type_specifier", 1, $1);
                }
                |FLOAT {
                    $$ = node("type_specifier", 1, $1);
                }
                |VOID {
                    $$ = node("type_specifier", 1, $1);
                }
array_size : array_size LBRACKET additive_expression RBRACKET{
              $$ = node("array_size", 4, $1, $2, $3, $4);
           }
           | LBRACKET additive_expression RBRACKET{
              $$ = node("array_size", 3, $1, $2, $3);
           }
fun_declaration : type_specifier IDENTIFIER LPARENTHESE params RPARENTHESE compound_stmt {
                    $$ = node("fun_declaration", 6, $1, $2, $3, $4, $5, $6);
                }
params : param_list {
            $$ = node("params", 1, $1);
        }
        |VOID {
            $$ = node("params" ,1, $1);
        }
        | {
          $$ = node("param", 0);
        }
param_list : param_list COMMA param {
                $$ = node("param_list", 3, $1, $2, $3);
            }
            |param {
                $$ = node("param_list", 1, $1);
            }
param : type_specifier IDENTIFIER {
            $$ = node("param", 2, $1, $2);
        }
    |type_specifier IDENTIFIER ARRAY {
        $$ = node("param", 3, $1, $2, $3);
    }
compound_stmt : LBRACE statement_list RBRACE {
                    $$ = node("compound_stmt", 3, $1, $2, $3);
                }
local_declarations : local_declarations var_declaration {
                        $$ = node("local_declarations", 2, $1, $2);
                    }
                    | {
                        $$ = node("local_declarations", 0);
                    }

statement_list : statement_list statement {
                    $$ = node("statement_list", 2, $1, $2);
                }
                | {
                    $$ = node("statement_list", 0);
                }
statement : expression_stmt {
                $$ = node("statement", 1, $1);
            }
            |compound_stmt {
                $$ = node("statement", 1, $1);
            }
            |selection_stmt {
                $$ = node("statement", 1, $1);
            }
            |iteration_stmt {
                $$ = node("statement", 1, $1);
            }
            |return_stmt {
                $$ = node("statement", 1, $1);
            }
            |local_declarations{
                $$ = node("statement", 1, $1);
            }
            |local_declartion_assignment{
                $$ = node("statement", 1, $1);
            }
            |BREAK SEMICOLON {
              $$ = node("statement", 2, $1, $2);
            }
            |CONTINUE SEMICOLON {
              $$ = node("statement", 2, $1, $2);
            }
expression_stmt : expression SEMICOLON {
                    $$ = node("expression_stmt", 2, $1, $2);
                }
                |SEMICOLON {
                    $$ = node("expression_stmt", 1, $1);
                }
selection_stmt : IF LPARENTHESE expression RPARENTHESE statement {
                    $$ = node("selection_stmt", 5, $1, $2, $3, $4, $5);
                }
                |IF LPARENTHESE expression RPARENTHESE statement ELSE statement {
                    $$ = node("selection_stmt", 7, $1, $2, $3, $4, $5, $6, $7);
                }
                |IF LPARENTHESE logic_expression RPARENTHESE statement {
                    $$ = node("selection_stmt", 5, $1, $2, $3, $4, $5);
                }
                |IF LPARENTHESE logic_expression RPARENTHESE statement ELSE statement {
                    $$ = node("selection_stmt", 7, $1, $2, $3, $4, $5, $6, $7);
                }
iteration_stmt : WHILE LPARENTHESE expression RPARENTHESE statement {
                    $$ = node("iteration_stmt", 5, $1, $2, $3, $4, $5);
                }
                |WHILE LPARENTHESE logic_expression RPARENTHESE statement {
                    $$ = node("iteration_stmt", 5, $1, $2, $3, $4, $5);
                }
return_stmt : RETURN SEMICOLON {
                $$ = node("return_stmt", 2, $1, $2);
            }
            |RETURN expression SEMICOLON {
                $$ = node("return_stmt", 3, $1, $2, $3);
            }
local_declartion_assignment : CONST type_specifier expression SEMICOLON{
                              $$ = node("local_declartion_assignment", 3, $1, $2, $3);
                            }
                            |type_specifier expression SEMICOLON{
                              $$ = node("local_declartion_assignment", 2, $1, $2);
                            }
                            |CONST type_specifier IDENTIFIER array_size ASSIGN LBRACE arg_list RBRACE SEMICOLON{
                              $$ = node("local_declartion_assignment", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);
                            }
                            |type_specifier IDENTIFIER array_size ASSIGN LBRACE arg_list RBRACE SEMICOLON{
                              $$ = node("local_declartion_assignment", 8, $1, $2, $3, $4, $5, $6, $7, $8);
                            }
expression : var ASSIGN expression {
                $$ = node("expression", 3, $1, $2, $3);
            }
            |simple_expression {
                $$ = node("expression", 1, $1);
            }
var : IDENTIFIER {
        $$ = node("var", 1, $1);
    }
    |IDENTIFIER LBRACKET expression RBRACKET {
        $$ = node("var", 4, $1, $2, $3, $4);
    }
logic_expression : additive_expression logiclop additive_expression{
                   $$ = node("logic_expression", 3, $1, $2, $3);
                 }
                 | NOT additive_expression{
                   $$ = node("logic_expression", 2, $1, $2);
                 }
logiclop : AND{
            $$ = node("logiclop", 1, $1);
          }
          |OR{
            $$ = node("logiclop", 1, $1);
          }
simple_expression : additive_expression relop additive_expression {
                        $$ = node("simple_expression", 3, $1, $2, $3);
                    }
                    |additive_expression {
                        $$ = node("simple_expression", 1, $1);
                    }
relop : LTE {
            $$ = node("relop", 1, $1);
        }
        |LT {
            $$ = node("relop", 1, $1);
        }
        |GT {
            $$ = node("relop", 1, $1);
        }
        |GTE {
            $$ = node("relop", 1, $1);
        }
        |EQ {
            $$ = node("relop", 1, $1);
        }
        |NEQ {
            $$ = node("relop", 1, $1);
        }
additive_expression : additive_expression addop term {
                        $$ = node("additive_expression", 3, $1, $2, $3);
                    }
                    |term {
                        $$ = node("additive_expression", 1, $1);
                    }
addop : ADD {
            $$ = node("addop", 1, $1);
        }
        |SUB {
            $$ = node("addop", 1, $1);
        }
term : term mulop factor {
            $$ = node("term", 3, $1, $2, $3);
        }
        |factor {
            $$ = node("term", 1, $1);
        }
mulop : MUL {
            $$ = node("mulop", 1, $1);
        }
        |DIV {
            $$ = node("mulop", 1, $1);
        }
        |MOD {
            $$ = node("mulop", 1, $1);
        }
factor : LPARENTHESE expression RPARENTHESE {
            $$ = node("factor", 3, $1, $2, $3);
        }
        |var {
            $$ = node("factor", 1, $1);
        }
        |call {
            $$ = node("factor", 1, $1);
        }
        |integer {
            $$ = node("factor", 1, $1);
        }
        |float {
            $$ = node("factor", 1, $1);
        }
        |calllib {
            $$ = node("calllib", 1, $1);
        }
integer : INTEGER {
            $$ = node("integer", 1, $1);
        }
        | ADD INTEGER{
            $$ = node("integer", 1, $2);
        }
        | SUB INTEGER{
            $$ = node("integer", 2, $1, $2);
        }
float : FLOATPOINT {
            $$ = node("float", 1, $1);
        }
        | ADD FLOATPOINT{
            $$ = node("float", 1, $2);
        }
        | SUB FLOATPOINT{
            $$ = node("float", 2, $1, $2);
        }
call : IDENTIFIER LPARENTHESE args RPARENTHESE {
        $$ = node("call", 4, $1, $2, $3, $4);
     }
calllib : GETINT LPARENTHESE RPARENTHESE {
        $$ = node("getint", 3, $1, $2, $3);
    }
    | GETCH LPARENTHESE RPARENTHESE {
        $$ = node("getch", 3, $1, $2, $3);
    }
    | GETFLOAT LPARENTHESE RPARENTHESE {
        $$ = node("getfloat", 3, $1, $2, $3);
    }
    | GETARRAY LPARENTHESE expression RPARENTHESE {
        $$ = node("getarray", 4, $1, $2, $3, $4);
    }
    | GETFARRAY LPARENTHESE expression RPARENTHESE {
        $$ = node("getfarray", 4, $1, $2, $3, $4);
    }
    | PUTINT LPARENTHESE expression RPARENTHESE {
        $$ = node("putin", 4, $1, $2, $3, $4);
    }
    | PUTCH LPARENTHESE expression RPARENTHESE{
        $$ = node("putch", 4, $1, $2, $3, $4);
    }
    | PUTFLOAT LPARENTHESE expression RPARENTHESE{
        $$ = node("putfloat", 4, $1, $2, $3, $4);
    }
    | PUTARRAY LPARENTHESE expression expression RPARENTHESE{
        $$ = node("putin", 5, $1, $2, $3, $4, $5);
    }
    | PUTFARRAY LPARENTHESE expression expression RPARENTHESE{
        $$ = node("putin", 4, $1, $2, $3, $4);
    }
    | PUTF LPARENTHESE CONTROLSTRING COMMA args RPARENTHESE{
        $$ = node("putin", 5, $1, $2, $3, $4, $5);
    }
    | STARTTIME LPARENTHESE RPARENTHESE{
        $$ = node("getfloat", 3, $1, $2, $3);
    }
    | STOPTIME LPARENTHESE RPARENTHESE{
        $$ = node("getfloat", 3, $1, $2, $3);
    }

args : arg_list {
        $$ = node("args", 1, $1);
    }
    | {
        $$ = node("args", 0);
    }
arg_list : arg_list COMMA expression {
            $$ = node("arg_list", 3, $1, $2, $3);
        }
        |expression {
            $$ = node("arg_list", 1, $1);
        }
%%

void yyerror(const char *s) {
    fprintf(stderr, "error at line %d column %d: %s\n", lines, pos_start, s);
}

syntax_tree *parse() {
    lines = pos_start = pos_end = 1;
    gt = new_syntax_tree();
    yyrestart(yyin);
    yyparse();
    return gt;
}

syntax_tree_node *node(const char *name, int children_num, ...) {
    syntax_tree_node *p = new_syntax_tree_node(name);
    syntax_tree_node *child;
    if (children_num == 0) {
        child = new_syntax_tree_node("epsilon");
        syntax_tree_add_child(p, child);
    } else {
        va_list ap;
        va_start(ap, children_num);
        for (int i = 0; i < children_num; ++i) {
            child = va_arg(ap, syntax_tree_node *);
            syntax_tree_add_child(p, child);
        }
        va_end(ap);
    }
    return p;
}
