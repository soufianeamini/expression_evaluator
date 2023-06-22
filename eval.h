#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <readline/readline.h>

typedef enum token_type {
    INTEGER,
    LPAREN,
    RPAREN,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    UNKNOWN,
} token_type;

typedef struct t_token {
    char            *literal;
    int             value;
    token_type      type;
    struct t_token  *next;
} t_token;

typedef struct t_tree {
    t_token *token;
    struct t_tree *left;
    struct t_tree *right;
} t_tree;

// This wrapper makes it easy to advance the tokens
// and get the previous token etc
typedef struct w_wrapper {
    t_token *token;
    t_token *previous;
    t_token *peek;
    bool    error;
} w_wrapper;

// TOKENS
t_token    *new_ltoken(char *literal, token_type type);
t_token    *new_itoken(int value, token_type type);
void    add_token(t_token **head, t_token *n);
char    *print_token(token_type type);
void    free_tokens(t_token *token);

// LEXER
t_token    *lexer(char *line);

// PARSER
t_tree  *parse(t_token *token);
t_tree  *expression(w_wrapper *o);

// TREE
t_tree *new_tree(t_tree *left, t_token *token, t_tree *right);
void    free_ast(t_tree *ast);

// EVALUATOR
double  evaluate(t_tree *ast);
#endif
