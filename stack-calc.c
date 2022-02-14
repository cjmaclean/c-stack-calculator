#include <stdio.h>
#include "intstack.h"

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

void cmd_add(stack *s) {
    if (empty(*s)) {
        printf("Stack is empty, cannot add values\n");
        return;
    }
    int value1 = pop(s);
    if (empty(*s)) {
        printf("Stack insufficient, cannot add values\n");
        return;
    }
    int value2 = pop(s);
    push(s, value1+value2);
}

int main() {
    printf("starting\n\n");

    push(&user_stack, 2);
    push(&user_stack, 15);
    push(&user_stack, 3);

    cmd_add(&user_stack);
    
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