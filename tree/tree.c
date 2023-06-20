#include "../eval.h"

void    free_ast(t_tree *ast) {
    if (ast->left)
        free_ast(ast->left);
    if (ast->right)
        free_ast(ast->right);
    free(ast);
}

t_tree *new_tree(t_tree *left, t_token *token, t_tree *right) {
    t_tree *t = calloc(sizeof(t_tree), 1);
    if (!t)
        return NULL;
    t->token = token;
    t->left = left;
    t->right = right;
    return t;
}
