#include <stdio.h>

struct stack_element {
    int item;
    struct stack_element *next;
};

typedef struct stack_element *stack;

int main() {
    printf("hello\n");
    return 0;
}