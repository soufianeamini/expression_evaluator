#include "../eval.h"
#include <stdbool.h>

void    init_wrapper(w_wrapper *o, t_token *token) {
    o->previous = NULL;
    o->token = token;
    o->peek = token->next;
    o->error = false;
}

void    advance(w_wrapper *o) {
    o->previous = o->token;
    o->token = o->token->next;
    if (o->token)
        o->peek = o->token->next;
}

bool    check(w_wrapper *o, token_type type) {
    if (!o->token)
        return false;
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
    fprintf(stderr, "Error: Expected token '%s' after expression.\n", print_token(type));
    o->error = true;
    return false;
}

t_tree  *primary(w_wrapper *o) {
    if (match(o, INTEGER)) return new_tree(NULL, previous(o), NULL);
    if (match(o, LPAREN)) {
        t_tree *expr = expression(o);
        consume(o, RPAREN);
        return expr;
    }
    if (!previous(o))
        fprintf(stderr, "Unexpected token: %s\n", o->token->literal);
    else
        fprintf(stderr, "Error: Expected expression after token: '%s'\n", previous(o)->literal);
    o->error = true;
    return NULL;
}

t_tree  *factor(w_wrapper *o) {
    t_tree *expr = primary(o);

    while (match(o, STAR) || match(o, SLASH)) {
        t_token *token = previous(o);
        t_tree *right = primary(o);
        expr = new_tree(expr, token, right);
    }

    return expr;
}

t_tree  *rfactor(w_wrapper *o) {
    t_tree *expr = primary(o);

    if (match(o, STAR) || match(o, SLASH)) {
        t_token *token = previous(o);
        t_tree *right = rfactor(o);
        expr = new_tree(expr, token, right);
    }

    return expr;
}

t_tree  *expression(w_wrapper *o) {
    t_tree *expr = factor(o);

    while (match(o, PLUS) || match(o, MINUS)) {
        t_token *token = previous(o);
        t_tree *right = factor(o);
        expr = new_tree(expr, token, right);
    }

    return expr;
}

t_tree  *rexpression(w_wrapper *o) {
    t_tree *expr = rfactor(o);

    if (match(o, PLUS) || match(o, MINUS)) {
        t_token *token = previous(o);
        t_tree *right = rexpression(o);
        expr = new_tree(expr, token, right);
    }

    return expr;
}

t_tree  *rparse(t_token *token) {
    w_wrapper local;
    w_wrapper *o = &local;
    init_wrapper(o, token);
    t_tree  *expr = rexpression(o);
    if (o->token) {
        printf("Error: Unexpected token: %s\n", print_token(o->token->type));
        o->error = true;
    }
    if (o->error)
        return (free_ast(expr), NULL);
    return expr;
}

t_tree  *parse(t_token *token) {
    w_wrapper local;
    w_wrapper *o = &local;
    init_wrapper(o, token);
    t_tree  *expr = expression(o);
    if (o->token) {
        printf("Error: Unexpected token: %s\n", print_token(o->token->type));
        o->error = true;
    }
    if (o->error)
        return (free_ast(expr), NULL);
    return expr;
}

