#ifndef __INCLUDE_YACC_H_
#define __INCLUDE_YACC_H_

#include <stdio.h>

#define SYNTAX_TREE_NODE_NAME_MAX 30
#define SYNTAX_TREE_NODE_CHILDREN_NUM_MAX 100005

typedef struct __syntax_tree_node_ {
	struct __syntax_tree_node_* parent;
	struct __syntax_tree_node_* children[SYNTAX_TREE_NODE_CHILDREN_NUM_MAX];
	int children_num;
	char name[SYNTAX_TREE_NODE_NAME_MAX];
} syntax_tree_node ;

syntax_tree_node* new_syntax_tree_node(const char * name);
int syntax_tree_add_child(syntax_tree_node* parent, syntax_tree_node* child);
void del_syntax_tree_node(syntax_tree_node * node, int recursive);

typedef struct __syntax_tree_ {
	syntax_tree_node * root;
}syntax_tree;

syntax_tree* new_syntax_tree();
void del_syntax_tree(syntax_tree * tree);
void print_syntax_tree(FILE * fout, syntax_tree * tree);

#endif
