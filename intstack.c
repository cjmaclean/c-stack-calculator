#include <stdlib.h>
#include <stdio.h>
#include "intstack.h"

/* Stack type functions */


void push(stack *s, int value) {
    struct stack_element *new_stack_element;
    // malloc called here, corresponding free called in pop 
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
        // store data from top element of stack before freeing
        int value = (*s)->item;
        struct stack_element *next_stack_element;
        next_stack_element = (*s)->next;
        // free called here, corresponding
        // malloc called in push 
        free(*s);
        *s = next_stack_element;
        return value;
    }
}

/* end stack type functions */
