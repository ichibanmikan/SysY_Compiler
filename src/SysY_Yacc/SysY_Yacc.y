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
%token <node> ADD SUB MUL DIV LT LTE GT GTE EQ NEQ AND OR NOT MOD ASSIGN SEMICOLON COMMA LPARENTHESE RPARENTHESE LBRACKET RBRACKET LBRACE RBRACE ELSE IF INT FLOAT RETURN VOID WHILE IDENTIFIER INTEGER FLOATPOINT LETTER EOL COMMENT BLANK ERROR CONTINUE BREAK CONST COMMENTONELINE GETINT GETCH GETFLOAT GETARRAY GETFARRAY PUTINT PUTCH PUTFLOAT PUTARRAY PUTFARRAY PUTF STARTTIME STOPTIME CONTROLSTRING
%type <node> program
%type <node> type_specifier relop addop mulop
%type <node> declaration_list declaration var_declaration fun_declaration const_declartion_assignment declartion_assignment_expression logic_or_expression logic_and_expression equal_expression relop_expression
%type <node> compound_stmt statement_list statement expression_stmt iteration_stmt selection_stmt return_stmt idenfier_list
%type <node> expression additive_expression logic_expression var term factor call calllib unary_ops_size unary_ops array_cell
%type <node> params param_list param args arg_list array_size init_val_size init_val_size_size declartion_assignment_size idenfier_size

%%

program : declaration_list {
        }
declaration_list : declaration_list declaration {
                    $$ = $1;
                    syntax_tree_add_child($$, $2);
                 }
                 | declaration {
                     $$ = new_syntax_tree_node("declarations");
                     gt->root = $$;
                     syntax_tree_add_child($$, $1);
                 }
declaration : var_declaration {
                $$ = $1;
            }
            |const_declartion_assignment{
                $$ = $1;
            }
            |fun_declaration {
                $$ = $1;
            }
idenfier_size : idenfier_size COMMA idenfier_list{
                $$ = $1;
                syntax_tree_add_child($$, $3);
              }
              | idenfier_list{
                $$ = new_syntax_tree_node("idenfiers");
                syntax_tree_add_child($$, $1);
              }
idenfier_list : IDENTIFIER{
                $$ = $1;
              }
              | IDENTIFIER ASSIGN init_val_size{
                $$ = $2;
                syntax_tree_add_child($$, $1);
                syntax_tree_add_child($$, $3);
              }
              | IDENTIFIER array_size{
                $$ = $1;
                syntax_tree_add_child($$, $2);
              }
              | IDENTIFIER array_size ASSIGN init_val_size{
                $$ = $3;
                syntax_tree_add_child($1, $2);
                syntax_tree_add_child($$, $1);
                syntax_tree_add_child($$, $4);
              }

var_declaration :type_specifier idenfier_size SEMICOLON {
                    $$ = node("var_declaration", 2, $1, $2);
                }

type_specifier : INT {
                    $$ = $1;
                }
                |FLOAT {
                    $$ = $1;
                }
                |VOID {
                    $$ = $1;
                }
array_size : array_size array_cell{
              $$ = $1;
              syntax_tree_add_child($$, $2);
           }
           | array_cell{
                $$ = new_syntax_tree_node("array_size");
                syntax_tree_add_child($$, $1);
           }

array_cell : LBRACKET additive_expression RBRACKET{
            $$ = $2;
          }
          | LBRACKET RBRACKET{
            $$ = new_syntax_tree_node("void");
          }

fun_declaration : type_specifier IDENTIFIER LPARENTHESE params RPARENTHESE compound_stmt {
                    $$ = node("func_declaration", 4, $1, $2, $4, $6);
                }
params : param_list {
            $$ = $1;
        }
        |VOID {
            $$ = new_syntax_tree_node("void");
        }
        | {
          $$ = new_syntax_tree_node("void");
        }
param_list : param_list COMMA param {
                $$ = $1;
                syntax_tree_add_child($$, $3);
            }
            |param {
                $$ = new_syntax_tree_node("params");
                syntax_tree_add_child($$, $1);
            }
param : type_specifier IDENTIFIER {
        $$ = node("param", 2, $1, $2);
      }
      |type_specifier IDENTIFIER array_size {
        $$ = node("param_array", 3, $1, $2, $3);
      }
compound_stmt : LBRACE statement_list RBRACE {
                    $$ = $2;
                }

statement_list : statement_list statement {
                    $$ = $1;
                    syntax_tree_add_child($$, $2);
                }
                | {
                    $$ = new_syntax_tree_node("stmts");
                }
statement : expression_stmt {
                $$ = $1;
            }
            |compound_stmt {
                $$ = $1;
            }
            |selection_stmt {
                $$ = $1;
            }
            |iteration_stmt {
                $$ = $1;
            }
            |return_stmt {
                $$ = $1;
            }
            |var_declaration{
                $$ = $1;
            }
            |const_declartion_assignment{
                $$ = $1;
            }
            |BREAK SEMICOLON {
              $$ = $1;
            }
            |CONTINUE SEMICOLON {
              $$ = $1;
            }
expression_stmt : expression SEMICOLON {
                    $$ = $1;
                }
                |SEMICOLON {

                }
selection_stmt : IF LPARENTHESE logic_expression RPARENTHESE statement {
                    syntax_tree_node* stn;
                    if(!strcmp($5->name, "stmts")){
                      stn = $5;
                    } else {
                     stn=new_syntax_tree_node("stmts");
                     syntax_tree_add_child(stn, $5);
                    }
                    $$ = node("if_stmt", 2, $3, stn);
                }
                |IF LPARENTHESE logic_expression RPARENTHESE statement ELSE statement {
                    syntax_tree_node* stn;
                    syntax_tree_node* stn7;
                    if(!strcmp($5->name, "stmts")){
                      stn = $5;
                    } else {
                     stn=new_syntax_tree_node("stmts");
                     syntax_tree_add_child(stn, $5);
                    }
                    if(!strcmp($7->name, "stmts")){
                      stn7=$7;
                    } else {
                      stn7=new_syntax_tree_node("stmts");
                      syntax_tree_add_child(stn7, $7);
                    }
                    $$ = node("if_else_stmt", 3, $3, stn, stn7);
                }
iteration_stmt : WHILE LPARENTHESE logic_expression RPARENTHESE statement {
                    syntax_tree_node* stn;
                    if(!strcmp($5->name, "stmts")){
                      stn = $5;
                    } else {
                     stn=new_syntax_tree_node("stmts");
                     syntax_tree_add_child(stn, $5);
                    }
                    $$ = node("while_stmt", 2, $3, stn);
                }
return_stmt : RETURN SEMICOLON {
                $$ = node("return_stmt", 0);
            }
            |RETURN expression SEMICOLON {
                $$ = node("return_stmt", 1, $2);
            }
const_declartion_assignment : CONST type_specifier declartion_assignment_size SEMICOLON{
                              $$ = node("const_declartion_assignment", 2, $2, $3);
                            }

init_val_size : expression{
                $$ = $1;
              }
              |LBRACE RBRACE{
                $$ = new_syntax_tree_node("unknow_size");
              }
              |LBRACE init_val_size_size RBRACE{
                $$ = $2;
              }

init_val_size_size : init_val_size_size COMMA init_val_size{
                      $$ = $1;
                      syntax_tree_add_child($$, $3);
                  }
                  |init_val_size{
                      $$ = new_syntax_tree_node("init_vals");
                      syntax_tree_add_child($$, $1);
                  }

declartion_assignment_size : declartion_assignment_size COMMA declartion_assignment_expression{
                            $$ = $1;
                            syntax_tree_add_child($$, $3);
                          }
                          |declartion_assignment_expression{
                            $$ = new_syntax_tree_node("declartion_assignments");
                            syntax_tree_add_child($$, $1);
                          }

declartion_assignment_expression : var ASSIGN init_val_size {
                                    $$ = $2;
                                    syntax_tree_add_child($$, $1);
                                    syntax_tree_add_child($$, $3);
                                  }

expression : var ASSIGN expression {
                $$ = $2;
                syntax_tree_add_child($$, $1);
                syntax_tree_add_child($$, $3);
            }
            |additive_expression {
                $$ = $1;
            }
var : IDENTIFIER {
        $$ = $1;
    }
    |IDENTIFIER array_size {
        $$ = $1;
        syntax_tree_add_child($$, $2);
    }

logic_expression : logic_or_expression{
                    $$ = $1;
                  }

logic_or_expression : logic_and_expression{
                      $$ = $1;
                    }
                    |logic_or_expression OR logic_and_expression{
                      $$ = $2;
                      syntax_tree_add_child($$, $1);
                      syntax_tree_add_child($$, $3);
                    }

logic_and_expression : equal_expression{
                        $$ = $1;
                      }
                      | logic_and_expression AND equal_expression{
                        $$ = $2;
                        syntax_tree_add_child($$, $1);
                        syntax_tree_add_child($$, $3);
                      }

equal_expression : relop_expression{
            $$ = $1;
          }
          | equal_expression EQ relop_expression{
            $$ = $2;
            syntax_tree_add_child($$, $1);
            syntax_tree_add_child($$, $3);
          }
          | equal_expression NEQ relop_expression{
            $$ = $2;
            syntax_tree_add_child($$, $1);
            syntax_tree_add_child($$, $3);
          }

relop_expression : additive_expression{
            $$ = $1;
          }
          |relop_expression relop additive_expression{
            $$ = $2;
            syntax_tree_add_child($$, $1);
            syntax_tree_add_child($$, $3);
          }

relop : LTE {
            $$ = $1;
        }
        |LT {
            $$ = $1;
        }
        |GT {
            $$ = $1;
        }
        |GTE {
            $$ = $1;
        }

additive_expression : additive_expression addop term {
                        $$ = $2;
                        syntax_tree_add_child($$, $1);
                        syntax_tree_add_child($$, $3);
                    }
                    |term {
                        $$ = $1;
                    }
addop : ADD {
            $$ = $1;
        }
        |SUB {
            $$ = $1;
        }
term : term mulop factor {
            $$ = $2;
            syntax_tree_add_child($$, $1);
            syntax_tree_add_child($$, $3);
        }
        |term mulop unary_ops_size factor{
          $$ = $2;
          syntax_tree_add_child($$, $1);
          syntax_tree_add_child($$, node("unary_ops_factor", 2, $3, $4));

          int temp=$$->children[1]->children[0]->children_num;
          if(temp%2==0){
            $$->children[1] = $4;
          } else {
            $$->children[1]->children[0]=new_syntax_tree_node("-");
          }
        }
        |factor {
            $$ = $1;
        }
        |unary_ops_size factor{
            $$ = node("unary_ops_factor", 2, $1, $2);
            int tempSub=0, tempNot=0;
            for(int i=0; i<$$->children[0]->children_num; i++){
              if($$->children[0]->children[i]->name[0]=='!'){
                tempNot++;
              }else if($$->children[0]->children[i]->name[0]=='-'){
                tempSub++;
              }
            }
            if(tempNot%2==0&&tempSub%2==0){
              $$ = $2;
            } else {
              if(tempNot%2==1&&tempSub%2==1){
                $$->children[0]=new_syntax_tree_node("!-");
              } else if(tempNot%2==0) {
                $$->children[0]=new_syntax_tree_node("-");
              } else if(tempSub%2==0) {
                $$->children[0]=new_syntax_tree_node("!");
              }
            }
        }
mulop : MUL {
            $$ = $1;
        }
        |DIV {
            $$ = $1;
        }
        |MOD {
            $$ = $1;
        }
factor : LPARENTHESE expression RPARENTHESE {
            $$ = $2;
        }
        |var {
            $$ = $1;
        }
        |call {
            $$ = $1;
        }
        |INTEGER {
            $$ = $1;
        }
        |FLOATPOINT {
            $$ = $1;
        }
        |calllib {
            $$ = $1;
        }

unary_ops_size : unary_ops_size unary_ops{
                  $$ = $1;
                  if($2->name[0]!='+'){
                    syntax_tree_add_child($$, $2);
                  }
                }
                |unary_ops{
                  $$ = new_syntax_tree_node("unary_ops");
                  if($1->name[0]!='+'){
                    syntax_tree_add_child($$, $1);
                  }
                }

unary_ops :ADD{
            $$ = $1;
          }
          |SUB{
            $$ = $1;
          }
          |NOT{
            $$ = $1;
          }

call : IDENTIFIER LPARENTHESE args RPARENTHESE {
        $$ = $1;
        syntax_tree_add_child($$, $3);
     }
calllib : GETINT LPARENTHESE RPARENTHESE {
        $$ = node("getint", 0);
    }
    | GETCH LPARENTHESE RPARENTHESE {
        $$ = node("getch", 0);
    }
    | GETFLOAT LPARENTHESE RPARENTHESE {
        $$ = node("getfloat", 0);
    }
    | GETARRAY LPARENTHESE expression RPARENTHESE {
        $$ = node("getarray", 1, $3);
    }
    | GETFARRAY LPARENTHESE expression RPARENTHESE {
        $$ = node("getfarray", 1, $3);
    }
    | PUTINT LPARENTHESE expression RPARENTHESE {
        $$ = node("putint", 1, $3);
    }
    | PUTCH LPARENTHESE expression RPARENTHESE{
        $$ = node("putch", 1, $3);
    }
    | PUTFLOAT LPARENTHESE expression RPARENTHESE{
        $$ = node("putfloat", 1, $3);
    }
    | PUTARRAY LPARENTHESE expression COMMA expression RPARENTHESE{
        $$ = node("putarray", 2, $3, $5);
    }
    | PUTFARRAY LPARENTHESE expression COMMA expression RPARENTHESE{
        $$ = node("putfarray", 2, $3, $5);
    }
    | PUTF LPARENTHESE CONTROLSTRING COMMA args RPARENTHESE{
        $$ = node("putf", 2, $3, $5);
    }
    | STARTTIME LPARENTHESE RPARENTHESE{
        $$ = node("starttime", 0);
    }
    | STOPTIME LPARENTHESE RPARENTHESE{
        $$ = node("stoptime", 0);
    }

args : arg_list {
        $$ = $1;
    }
    | {
        $$ = new_syntax_tree_node("epsilon");
    }
arg_list : arg_list COMMA expression {
            $$ = $1;
            syntax_tree_add_child($$, $3);
        }
        |expression {
            $$ = new_syntax_tree_node("args");
            syntax_tree_add_child($$, $1);
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
