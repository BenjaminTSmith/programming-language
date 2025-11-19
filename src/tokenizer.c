#include <stdio.h>
#include <string.h>

#include "tokenizer.h"

void print_token(Token token) {
    switch (token.type) {
        case TOKEN_NUMBER:
            printf("number(%f)\n", token.number);
            break;
        case TOKEN_OPEN_PAREN:
            printf("(\n");
            break;
        case TOKEN_CLOSE_PAREN:
            printf(")\n");
            break;
        case TOKEN_PLUS:
            printf("+\n");
            break;
        case TOKEN_TIMES:
            printf("*\n");
            break;
        case TOKEN_MINUS:
            printf("-\n");
            break;
        case TOKEN_DIVIDE:
            printf("/\n");
            break;
        case TOKEN_EOF:
            printf("EOF\n");
            break;
    }
}

int is_number(char c) {
    return '0' <= c && c <= '9';
}

void tokenize(Tokenizer *tokenizer, const char *str) {
    size_t len = strlen(str);

    // tokenizer->start signals the beggining of a token in the string
    while (tokenizer->start <= len) { 
        // tokenizer->current signifies the current character in the token being tokenized
        char c = str[tokenizer->current++];
        switch (c) {
            case '(':
                tokenizer->tokens[tokenizer->count++].type = TOKEN_OPEN_PAREN;
                break;
            case ')':
                tokenizer->tokens[tokenizer->count++].type = TOKEN_CLOSE_PAREN;
                break;
            case '+':
                tokenizer->tokens[tokenizer->count++].type = TOKEN_PLUS;
                break;
            case '*':
                tokenizer->tokens[tokenizer->count++].type = TOKEN_TIMES;
                break;
            case '-':
                tokenizer->tokens[tokenizer->count++].type = TOKEN_MINUS;
                break;
            case '/':
                tokenizer->tokens[tokenizer->count++].type = TOKEN_DIVIDE;
                break;
            case '\0':
                tokenizer->tokens[tokenizer->count++].type = TOKEN_EOF;
                break;
            // ignore white space
            case ' ':
            case '\n':
            case '\r':
            case '\t':
                break;
            default:
                if (is_number(c)) {
                    // TODO: implement number tokenization
                } else {
                    printf("error: unrecognized token %c\n", c);
                }
                break;
        }

        tokenizer->start = tokenizer->current;
    }
}
