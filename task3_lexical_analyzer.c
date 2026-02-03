#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {"int", "float", "if", "else", "return", "char", "double", "for", "while", "do"};

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/=%<>";
    for (int i = 0; i < (int)strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp = fopen("input.c", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input.c file!\n");
        return 1;
    }

    char ch, word[50];
    int i = 0;

    printf("===== CODTECH TASK 3: LEXICAL ANALYZER =====\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            word[i++] = ch;
        } 
        else {
            if (i > 0) {
                word[i] = '\0';
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
                i = 0;
            }

            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
