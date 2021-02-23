#ifndef _STACK_H
#define _STACK_H


struct node {
    void *data;
    struct node *next;
};

struct stack{
    struct node *v;
    int length;
};

typedef struct stack *Stack;

Stack newStack();

/* Function: destroy
 * Usage: destroy(&stack);
 */
void deleteStack(Stack S);

/*
 * Functions: push, pop
 * Usage:
 * push(&stack, element);
 * element = pop(&stack);
 */
void push(Stack S, void *elem);
void* pop(Stack S);

/*
 * Functions: isEmpty, isFull
 */

int isEmpty(Stack S);
int isFull(Stack S);


#endif