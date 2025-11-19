#include <stdio.h>
#include <string.h>

#include "tokenizer.h"

int main(int argc, char **argv) {
    // TODO(Ben): prevent buffer overruns in the REPL
    char buffer[128];

    while (1) {
        printf(">> ");
        fgets(buffer, 128, stdin);              

        buffer[strlen(buffer) - 1] = '\0'; // removes the trailing newline from input
        // printf("%s\n", buffer);
        
        if (!strcmp(buffer, "exit")) break;

        Tokenizer tokenizer;
        tokenizer.count = 0;
        tokenizer.capacity = 2048;
        tokenizer.start = 0;
        tokenizer.current = 0;

        tokenize(&tokenizer, buffer);
        for (int i = 0; i < tokenizer.count; i++) print_token(tokenizer.tokens[i]);
    }
}
