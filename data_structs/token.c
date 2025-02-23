#include "../eval.h"

void    free_tokens(t_token *token) {
    if (token->next)
        free_tokens(token->next);
    free(token);
}

t_token    *new_ltoken(char *literal, token_type type) {
    t_token *token = calloc(1, sizeof(t_token));
    if (!token)
        return NULL;
    token->literal = literal;
    token->type = type;
    token->next = NULL;
    return token;
}

t_token    *new_itoken(int value, token_type type) {
    t_token *token = calloc(1, sizeof(t_token));
    if (!token)
        return NULL;
    token->value = value;
    token->type = type;
    token->next = NULL;
    return token;
}

void    add_token(t_token **head, t_token *n) {
    if (!head)
        return;
    if (!*head) {
        *head = n;
        return;
    }
    t_token *temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

char    *print_token(token_type type) {
    switch (type) {
        case INTEGER: return "INTEGER";
        case LPAREN: return "(";
        case RPAREN: return ")";
        case PLUS: return "+";
        case MINUS: return "-";
        case STAR: return "*";
        case SLASH: return "/";
        default: return "";
    }
}
