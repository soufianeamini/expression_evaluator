#include "eval.h"

void    print_tokens(t_token *token) {
    for (t_token *temp = token; temp; temp = temp->next) {
        if (temp->type == INTEGER)
            printf("Token: Int, Value: %d\n", temp->value);
        else
            printf("Token: Spec, Literal: %s\n", temp->literal);
    }
}

int main() {
    char *line = readline("> ");
    t_token *token = lexer(line);
    print_tokens(token);
    t_tree *ast = parse(token);
    return 0;
}
