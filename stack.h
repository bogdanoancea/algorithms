#ifndef _STACK_H
#define _STACK_H

// Type: stackElementT
 typedef char stackElementType;

// Type: stack
typedef struct {
  stackElementType *contents;
  int maxSize;
  int top;
} stackType;


/*
 * Function: new
 * Usage: new(&stack, maxSize);
 */
void newStack(stackType *sp, int maxSize);

/* Function: destroy
 * Usage: destroy(&stack);
 */
void deleteStack(stackType* sp);

/*
 * Functions: push, pop
 * Usage:
 * push(&stack, element);
 * element = pop(&stack);
 */
void push(stackType* sp, stackElementType e);
stackElementType pop(stackType * sp);

/*
 * Function: peek
 * Usage:
 * element = peek(&stack);
 */
stackElementType peek(stackType * sp);


/*
* Function size
* Usage:
* n = size(stackT* sp)
*/
int size(stackType* sp);


/*
 * Functions: isEmpty, isFull
 */

int isEmpty(stackType* sp);
int isFull(stackType* sp);

#endif  /* not defined _STACK_H */
