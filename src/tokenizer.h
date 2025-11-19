#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum TokenType {
    TOKEN_NUMBER,
    TOKEN_OPEN_PAREN,
    TOKEN_CLOSE_PAREN,
    TOKEN_PLUS,
    TOKEN_TIMES,
    TOKEN_MINUS,
    TOKEN_DIVIDE,
    TOKEN_EOF
} TokenType;

typedef struct Token {
    TokenType type;
    float number;
} Token;

typedef struct Tokenizer {
    // TODO(Ben): implement dynamic arrays for tokens
    Token tokens[2048];
    int count;
    int capacity;
    int start;
    int current;
} Tokenizer;

extern Tokenizer tokenizer;

void print_token(Token token);
void tokenize(Tokenizer *tokenizer, const char *str);

#endif // TOKENIZER_H
