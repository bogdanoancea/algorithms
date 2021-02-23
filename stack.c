#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void newStack(stackType* sp, int maxSize) {
  stackElementType* newContents;

  /* Allocate a new array to hold the contents. */
  newContents = (stackElementType *) malloc(sizeof(stackElementType) * maxSize);

  if (newContents == NULL) {
    fprintf(stderr, "Insufficient memory to initialize stack.\n");
    exit(1);
}
  sp->contents = newContents;
  sp->maxSize = maxSize;
  sp->top = -1;  /* empty stack*/
}

void deleteStack(stackType *sp) {
  free(sp->contents);
  sp->contents = NULL;
  sp->maxSize = 0;
  sp->top = -1;
}

int size(stackType* sp) {
  return (sp->top) + 1;
}

void push(stackType* sp, stackElementType e) {
  if (isFull(sp)) {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);
  }
  sp->contents[++sp->top] = e;
}

stackElementType pop(stackType* sp) {
  if (isEmpty(sp)) {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);
  }
  return sp->contents[sp->top--];
}

stackElementType peek(stackType* sp) {
  if (isEmpty(sp)) {
    fprintf(stderr, "Can't peek element from stack: stack is empty.\n");
    exit(1);
  }
  return sp->contents[sp->top];
}


int isEmpty(stackType* sp) {
  return sp->top < 0;
}

int isFull(stackType* sp) {
  return sp->top == sp->maxSize - 1;
}

