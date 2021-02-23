#ifndef _STACKL_H
#define _STACKL_H


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

/* Function: deleteStack
 * Usage: deleteStack(S);
 */
void deleteStack(Stack S);

/*
 * Functions: push, pop
 * Usage:
 * push(S, element);
 * element = pop(S);
 */
void push(Stack S, void *elem);
void* pop(Stack S);

/*
 * Function: peek
 * Usage:
 * element = peek(S);
 */
void* peek(Stack S);


/*
* Function size
* Usage:
* n = size(S)
*/
int size(Stack S);

/*
 * Function: isEmpty
 */
int isEmpty(Stack S);



#endif