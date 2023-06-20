#include "eval.h"

void    print_tokens(t_token *token) {
    for (t_token *temp = token; temp; temp = temp->next) {
        if (temp->type == INTEGER)
            printf("Token: Int, Value: %d\n", temp->value);
        else
            printf("Token: Spec, Literal: %s\n", temp->literal);
    }
}

void    print_ast(t_tree *ast, int space) {
    if (!ast)
        return;

    space += 3;
    print_ast(ast->right, space);

    printf("\n");
    for (int i = 3; i < space; i++)
        printf(" ");
    if (ast->token->type == INTEGER)
        printf("%d\n", ast->token->value);
    else
        printf("%s\n", ast->token->literal);

    print_ast(ast->left, space);
}

// void    print_ast(t_tree *ast, int depth) {
//     for (int i = 0; i < depth; i++)
//         printf("    ");
//     if (ast->token->type == INTEGER)
//         printf("%d", ast->token->value);
//     else
//         printf("%s", ast->token->literal);
//     if (ast->left)
//         print_ast(ast->left, depth + 1);
//     if (ast->right)
//         print_ast(ast->right, depth + 1);
//     printf("\n");
// }

int main() {
    char *line = readline("> ");
    t_token *token = lexer(line);
    // print_tokens(token);
    t_tree *ast = parse(token);
    print_ast(ast, 0);
    return 0;
}
