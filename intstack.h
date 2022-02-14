/* Stack type */

struct stack_element {
    int item;
    struct stack_element *next;
};

typedef struct stack_element *stack;

void push(stack *s, int value);
int empty(stack s);
int pop(stack *s);

/* end stack type */
