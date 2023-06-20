#include "eval.h"

int main() {
    char *line = readline("> ");
    t_token *token = lexer(line);
    for (t_token *temp = token; temp; temp = temp->next) {
        if (temp->type == INTEGER)
            printf("Token: Int, Value: %d\n", temp->value);
        else
            printf("Token: Spec, Literal: %s\n", temp->literal);
    }
    return 0;
}
