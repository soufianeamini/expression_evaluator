#include "../eval.h"

t_token    *new_token(char *literal, token_type type) {
    t_token *token = calloc(sizeof(t_token), 1);
    if (!token)
        return NULL;
    token->literal = literal;
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
