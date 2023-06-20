#include "../eval.h"

double  evaluate(t_tree *ast) {
    if (!ast)
        return 0;
    token_type type = ast->token->type;
    switch (type) {
        case LPAREN:
        case RPAREN: return 0;
        case INTEGER: return (double)ast->token->value;
        case PLUS: return evaluate(ast->left) + evaluate(ast->right);
        case MINUS: return evaluate(ast->left) - evaluate(ast->right);
        case STAR: return evaluate(ast->left) * evaluate(ast->right);
        case SLASH: return evaluate(ast->left) / evaluate(ast->right);
        default: return 0;
    }
}
