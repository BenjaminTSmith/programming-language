#include <stdio.h>

#define true 1 

typedef enum {
    NUMBER,
    OPEN_PAREN,
    CLOSE_PAREN,
    PLUS,
    TIMES,
    MINUS,
    DIVIDE
} TokenType;

typedef struct {
    TokenType type;
    float number;
} Token;

typedef struct {
    int start;
    int current;
} Tokenizer;

Token tokens[2048];

int tokenize(Tokenizer *tokenizer, char *str) {
    
}

int main(int argc, char **argv) {
    Tokenizer tokenizer;

    char buffer[128];

    while (true) {
        fgets(buffer, 128, stdin);              


        
    }
}
