/** short program to demonstrate use of stack
 *
 * @author Blake Nelson
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
    Stack *stack = create(size);

    char input[256];
    while (fgets(input, 256, stdin) != NULL) {
        // remove newline character from input
        input[strcspn(input, "\n")] = '\0';
        push(stack, input);
    }

    printf("Popping stack:\n");
    while (!isempty(stack)) {
        char *value = pop(stack);
        printf("%s\n", value);
        free(value);
    }

    destroy(stack);

    return 0;
}