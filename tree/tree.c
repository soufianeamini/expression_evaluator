#include "../eval.h"

t_tree *new_tree( t_tree *left, t_token *token, t_tree *right) {
    t_tree *t = calloc(sizeof(t_tree), 1);
    if (!t)
        return NULL;
    t->token = token;
    t->left = left;
    t->right = right;
    return t;
}
