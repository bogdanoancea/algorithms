#ifndef _STACK_H
#define _STACK_H

// Type: stackElementT
 typedef char stackElementT;

// Type: stackT
typedef struct {
  stackElementT *contents;
  int maxSize;
  int top;
} stackT;

/*
 * Function: new
 * Usage: new(&stack, maxSize);
 */
void new(stackT *sp, int maxSize);

/* Function: destroy
 * Usage: destroy(&stack);
 */
void destroy(stackT* sp);

/*
 * Functions: push, pop
 * Usage:
 * push(&stack, element);
 * element = pop(&stack);
 */
void push(stackT* sp, stackElementT e);
stackElementT pop(stackT * sp);

/*
 * Functions: isEmpty, isFull
 */

int isEmpty(stackT* sp);
int isFull(stackT* sp);

#endif  /* not defined _STACK_H */
