#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>

typedef enum token_type {
    INTEGER,
    LPAREN,
    RPAREN,
    PLUS,
    MINUS,
    STAR,
    SLASH,
} token_type;

typedef struct t_token {
    char        *literal;
    token_type  type;
} t_token;

typedef struct node {
    t_token     token;
    struct node *next;
} node;

#endif
