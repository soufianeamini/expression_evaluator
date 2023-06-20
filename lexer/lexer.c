#include "../eval.h"

t_token    *lexer(char *line) {
    t_token *tokens = NULL;
    for (int i = 0; line[i]; i++) {
        switch (line[i]) {
            case '+': add_token(&tokens, new_token("+", PLUS));
                break;
            case '-': add_token(&tokens, new_token("-", MINUS));
                break;
            case '*': add_token(&tokens, new_token("*", STAR));
                break;
            case '/': add_token(&tokens, new_token("/", SLASH));
                break;
            case '(': add_token(&tokens, new_token("(", LPAREN));
                break;
            case ')': add_token(&tokens, new_token(")", LPAREN));
                break;
            case ' ': continue;
            default:
                if (isdigit(line[i])) {
                    int value = atoi(line +i);
                    t_token *token = new_token("", INTEGER);
                    token->value = value;
                    add_token(&tokens, token);
                    while(isdigit(line[i + 1]))
                        i++;
                }
                break;
        }
    }
    return tokens;
}
