#include "../eval.h"
#include <stdbool.h>

void    init_wrapper(w_wrapper *o, t_token *token) {
    o->previous = NULL;
    o->token = token;
    o->token = token->next;
}

void    advance(w_wrapper *o) {
    o->previous = o->token;
    o->token = o->token->next;
    o->peek = o->token->next;
}

bool    check(w_wrapper *o, token_type type) {
    if (o->token->type == type)
        return true;
    return false;
}

t_token    *peek(w_wrapper *o) {
    return o->peek;
}

t_token     *previous(w_wrapper *o) {
    return o->previous;
}

bool    match(w_wrapper *o, token_type type) {
    if (check(o, type)) {
        advance(o);
        return true;
    }

    return false;
}

bool    consume(w_wrapper *o, token_type type) {
    if (match(o, type)) return true;
    fprintf(stderr, "Error: Expected token %s after expression.\n", "test");
    return false;
}

t_tree  *parse(t_token *token) {
    w_wrapper local;
    w_wrapper *o;
    init_wrapper(o, token);
    //return expression;
    return NULL;
}

