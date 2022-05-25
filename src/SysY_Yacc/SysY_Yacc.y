%{
#include "SysY_Yacc.h"

extern int yylex();
extern FILE* yyin;
extern int lines;
extern char *yytext;
extern int pos_end;
extern int pos_start;
extern void yyrestart  (FILE * input_file );

syntax_tree *gt;

void yyerror(const char *s);

syntax_tree_node *node(const char *node_name, int children_num, ...);
%}


%union {
    syntax_tree_node* node;
}

%left NOT
%start program
%token <node> ADD SUB MUL DIV LT LTE GT GTE EQ NEQ AND OR NOT MOD ASSIGN SEMICOLON COMMA LPARENTHESE RPARENTHESE LBRACKET RBRACKET LBRACE RBRACE ELSE IF INT FLOAT RETURN VOID WHILE IDENTIFIER INTEGER FLOATPOINT ARRAY LETTER EOL COMMENT BLANK ERROR CONTINUE BREAK CONST COMMENTONELINE GETINT GETCH GETFLOAT GETARRAY GETFARRAY PUTINT PUTCH PUTFLOAT PUTARRAY PUTFARRAY PUTF STARTTIME STOPTIME CONTROLSTRING
%type <node> program
%type <node> type_specifier relop addop mulop
%type <node> declaration_list declaration var_declaration fun_declaration const_declartion_assignment declartion_assignment_expression logic_or_expression logic_and_expression equal_expression relop_expression
%type <node> compound_stmt statement_list statement expression_stmt iteration_stmt selection_stmt return_stmt idenfier_list
%type <node> expression additive_expression logic_expression var term factor call calllib unary_ops_size unary_ops
%type <node> params param_list param args arg_list array_size init_val_size init_val_size_size declartion_assignment_size idenfier_size

%%

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
            |const_declartion_assignment{
                $$ = node("declaration", 1, $1);
            }
            |fun_declaration {
                $$ = node("declaration", 1, $1);
            }
idenfier_size : idenfier_size COMMA idenfier_list{
                $$ = node("idenfier_size", 3, $1, $2, $3);
              }
              | idenfier_list{
                $$ = node("idenfier_size", 1);
              }
idenfier_list : IDENTIFIER{
                $$ = node("idenfier_list", 1, $1);
              }
              | IDENTIFIER ASSIGN init_val_size{
                $$ = node("idenfier_list", 3, $1, $2, $3);
              }
              | IDENTIFIER array_size{
                $$ = node("idenfier_list", 2, $1, $2);
              }
              | IDENTIFIER array_size ASSIGN init_val_size{
                $$ = node("idenfier_list", 4, $1, $2, $3, $4);
              }

var_declaration :type_specifier idenfier_size SEMICOLON {
                    $$ = node("var_declaration", 3, $1, $2, $3);
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
            |var_declaration{
                $$ = node("statement", 1, $1);
            }
            |const_declartion_assignment{
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
selection_stmt : IF LPARENTHESE logic_expression RPARENTHESE statement {
                    $$ = node("selection_stmt", 5, $1, $2, $3, $4, $5);
                }
                |IF LPARENTHESE logic_expression RPARENTHESE statement ELSE statement {
                    $$ = node("selection_stmt", 7, $1, $2, $3, $4, $5, $6, $7);
                }
iteration_stmt : WHILE LPARENTHESE logic_expression RPARENTHESE statement {
                    $$ = node("iteration_stmt", 5, $1, $2, $3, $4, $5);
                }
return_stmt : RETURN SEMICOLON {
                $$ = node("return_stmt", 2, $1, $2);
            }
            |RETURN expression SEMICOLON {
                $$ = node("return_stmt", 3, $1, $2, $3);
            }
const_declartion_assignment : CONST type_specifier declartion_assignment_size SEMICOLON{
                              $$ = node("const_declartion_assignment", 3, $1, $2, $3);
                            }

init_val_size : expression{
                $$ = node("init_val_size", 1, $1);
              }
              |LBRACE RBRACE{
                $$ = node("init_val_size", 2, $1, $2);
              }
              |LBRACE init_val_size_size RBRACE{
                $$ = node("init_val_size", 3, $1, $2, $3);
              }

init_val_size_size : init_val_size_size COMMA init_val_size{
                      $$ = node("array_init_val_size_size", 3, $1, $2, $3);
                  }
                  |init_val_size{
                    $$ = node("init_val_size_size", 1, $1);
                  }

declartion_assignment_size : declartion_assignment_size COMMA declartion_assignment_expression{
                            $$ = node("declartion_assignment_size", 3, $1, $2, $3);
                          }
                          |declartion_assignment_expression{
                            $$ = node("declartion_assignment_size", 1, $1);
                          }

declartion_assignment_expression : var ASSIGN init_val_size {
                                    $$ = node("declartion_assignment_expression", 3, $1, $2, $3);
                                  }

expression : var ASSIGN expression {
                $$ = node("expression", 3, $1, $2, $3);
            }
            |additive_expression {
                $$ = node("expression", 1, $1);
            }
var : IDENTIFIER {
        $$ = node("var", 1, $1);
    }
    |IDENTIFIER array_size {
        $$ = node("var", 2, $1, $2);
    }

logic_expression : logic_or_expression{
                    $$ = node("logic_expression", 1, $1);
                  }

logic_or_expression : logic_and_expression{
                      $$ = node("logic_or_expression", 1, $1);
                    }
                    |logic_or_expression OR logic_and_expression{
                      $$ = node("logic_or_expression", 3, $1, $2, $3);
                    }

logic_and_expression : equal_expression{
                        $$ = node("logic_and_expression", 1, $1);
                      }
                      | logic_and_expression AND equal_expression{
                        $$ = node("logic_and_expression", 3, $1, $2, $3);
                      }

equal_expression : relop_expression{
            $$ = node("equal_expression", 1, $1);
          }
          | equal_expression EQ relop_expression{
            $$ = node("equal_expression", 3, $1, $2, $3);
          }
          | equal_expression NEQ relop_expression{
            $$ = node("equal_expression", 3, $1, $2, $3);
          }

relop_expression : additive_expression{
            $$ = node("additive_expression", 1, $1);
          }
          |relop_expression relop additive_expression{
            $$ = node("additive_expression", 3, $1, $2, $3);
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
        |unary_ops_size factor{
            $$ = node("term", 2, $1, $2);
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
        |INTEGER {
            $$ = node("factor", 1, $1);
        }
        |FLOATPOINT {
            $$ = node("factor", 1, $1);
        }
        |calllib {
            $$ = node("calllib", 1, $1);
        }

unary_ops_size : unary_ops_size unary_ops{
                  $$ = node("unary_ops_size", 2, $1, $2);
                }
                |unary_ops{
                  $$ = node("unary_ops_size", 1, $1);
                }

unary_ops : ADD{}
          |SUB{
            $$ = node("unary_ops", 1, $1);
          }
          |NOT{
            $$ = node("unary_ops", 1, $1);
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
