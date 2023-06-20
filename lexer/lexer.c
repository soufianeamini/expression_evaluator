#include "../eval.h"

t_token    *lexer(char *line) {
    t_token *tokens = NULL;
    for (int i = 0; line[i]; i++) {
        switch (line[i]) {
            case '+': add_token(&tokens, new_ltoken("+", PLUS));
                break;
            case '-': add_token(&tokens, new_ltoken("-", MINUS));
                break;
            case '*': add_token(&tokens, new_ltoken("*", STAR));
                break;
            case '/': add_token(&tokens, new_ltoken("/", SLASH));
                break;
            case '(': add_token(&tokens, new_ltoken("(", LPAREN));
                break;
            case ')': add_token(&tokens, new_ltoken(")", LPAREN));
                break;
            case ' ': continue;
            default:
                if (isdigit(line[i])) {
                    int value = atoi(line +i);
                    t_token *token = new_itoken(value, INTEGER);
                    add_token(&tokens, token);
                    while(isdigit(line[i + 1]))
                        i++;
                }
                break;
        }
    }
    return tokens;
}
