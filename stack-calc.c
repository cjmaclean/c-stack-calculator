#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    push(s, value1 + value2);
}

void cmd_subtract(stack *s) {
    if (empty(*s)) {
        printf("Stack is empty, cannot subtract values\n");
        return;
    }
    int value1 = pop(s);
    if (empty(*s)) {
        printf("Stack insufficient, cannot subtract values\n");
        return;
    }
    int value2 = pop(s);
    push(s, value1 - value2);
}

void cmd_multiply(stack *s) {
    if (empty(*s)) {
        printf("Stack is empty, cannot multiply values\n");
        return;
    }
    int value1 = pop(s);
    if (empty(*s)) {
        printf("Stack insufficient, cannot multiply values\n");
        return;
    }
    int value2 = pop(s);
    push(s, value1 * value2);
}

void demo() {
    push(&user_stack, 2);
    push(&user_stack, 15);
    push(&user_stack, 3);

    cmd_add(&user_stack);
    cmd_add(&user_stack);

    push(&user_stack, 15);
    push(&user_stack, 3);

    cmd_subtract(&user_stack);

    push(&user_stack, 15);
    push(&user_stack, 3);

    cmd_multiply(&user_stack);

    user_pop(&user_stack);
    user_pop(&user_stack);
    user_pop(&user_stack);
    user_pop(&user_stack);

    push(&user_stack, 8);

    user_pop(&user_stack);
    user_pop(&user_stack);
}

void run_user_command(char *cmd) {
    if(strlen(cmd) == 0) return;

    if (cmd[0] == '+') {
        cmd_add(&user_stack);
    } else if (cmd[0] == '-') {
        cmd_subtract(&user_stack);
    } else if ((cmd[0] == '*') || (cmd[0] == 'x')) {
        cmd_multiply(&user_stack);
    } else if (cmd[0] == 'p') {
        user_pop(&user_stack);
    } else {
        push(&user_stack, atoi(cmd));
    }
}

int main(int argc, char *argv[]) {
    printf("starting\n\n");
    // demo();

    for(int i = 1; i < argc; i++) {
        printf("command: %s\n",argv[i]);
        run_user_command(argv[i]);
    }

    printf("\ndone\n");
    return 0;
}