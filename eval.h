#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

// TOKENS
t_token    *new_token(char *literal, token_type type);
void    add_token(t_token **head, t_token *n);

// LEXER
t_token    *lexer(char *line);
#endif
