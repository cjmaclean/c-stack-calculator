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
        printf("failed to allocate\n");
        return;
    } else {
        new_stack_element->item = value;
        new_stack_element->next = *s;
        *s = new_stack_element;
    }
}

int empty(stack s) {
    return !s;
}

int pop(stack *s) {
    if (empty(*s)) {
        printf("failed to pop\n");
        return 0;
    } else {
        int value = (*s)->item;
        struct stack_element *next_stack_element;
        next_stack_element = (*s)->next;
        free(*s);
        *s = next_stack_element;
        return value;
    }
}

/* end stack type */

stack user_stack = NULL;

void user_pop(stack *s) {
    if (empty(*s)) {
        printf("Stack is empty, cannot pop value\n");
        return;
    } else {
        int value = pop(s);
        printf("Popped value: %d\n",value);
    }
}

int main() {
    printf("starting\n\n");

    push(&user_stack, 5);
    push(&user_stack, 3);
    
    user_pop(&user_stack);
    user_pop(&user_stack);
    user_pop(&user_stack);
    user_pop(&user_stack);

    push(&user_stack, 8);

    user_pop(&user_stack);
    user_pop(&user_stack);

    printf("\ndone\n");
    return 0;
}