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

int main() {
    for (;;) {
        char *line = readline("> ");
        if (!line)
            break;
        t_token *token = lexer(line);
        free(line);
        if (!token)
            continue;
        // print_tokens(token);
        t_tree *ast = parse(token);
        // print_ast(ast, 0);
        double value = evaluate(ast);
        if ((int)value == value)
            printf("%d\n", (int)value);
        else
            printf("%.2f\n", value);
        free_tokens(token);
        free_ast(ast);
    }
    return 0;
}
