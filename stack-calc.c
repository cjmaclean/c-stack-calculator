#include <stdio.h>
#include <stdlib.h>

/* Stack type */

struct stack_element {
    int item;
    struct stack_element *next;
};

typedef struct stack_element *stack;


void push(stack *s, int value) {
    struct stack_element *new_stack_element;
    new_stack_element = malloc(sizeof(struct stack_element));
    if(!new_stack_element) {
        printf("failed to allocate");
        return;
    } else {
        new_stack_element->item = value;
        new_stack_element->next = *s;
        *s = new_stack_element;
    }
}

stack user_stack = NULL;

/* end stack type */

int main() {
    printf("starting\n");

    push(&user_stack, 5);
    push(&user_stack, 3);
    
    printf("done\n");
    return 0;
}