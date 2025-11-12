#include <stdio.h>

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

int main() {
}
