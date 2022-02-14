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