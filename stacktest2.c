/**
 * @file stacktest.c
 * @brief A program that demonstrates the use of a stack data structure to reverse strings and characters in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <stack size>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    Stack *string_stack = create(size); // stack for reversing the order of strings
    Stack *char_stack = create(size);   // stack for reversing the order of characters in each string

    char input[256];
    while (fgets(input, 256, stdin) != NULL) {
        // remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // push the input string onto the string stack
        push(string_stack, input);

        // push each character of the input string onto the char stack
        int i;
        for (i = 0; i < strlen(input); i++) {
            char *c = malloc(sizeof(char));
            *c = input[i];
            push(char_stack, c);
        }
    }

    printf("Popping string stack:\n");
    while (!isempty(string_stack)) {
        char *string_value = pop(string_stack);

        // push each character of the string onto a new char stack
        Stack *reverse_char_stack = create(size);
        int i;
        for (i = 0; i < strlen(string_value); i++) {
            char *c = malloc(sizeof(char));
            *c = string_value[i];
            push(reverse_char_stack, c);
        }

        // pop each character from the new char stack to reverse the order of characters in the string
        char *char_value = pop(reverse_char_stack);
        while (char_value != NULL) {
            printf("%c", *char_value);
            free(char_value);
            char_value = pop(reverse_char_stack);
        }
        printf("\n");
        destroy(reverse_char_stack);
        free(char_value);
        free(string_value);
    }

    printf("\n");

    destroy(string_stack);
    destroy(char_stack);

    return 0;
}