#include <stdlib.h>
#include <stdio.h>
#include "intstack.h"

/* Stack type functions */

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

/* end stack type functions */