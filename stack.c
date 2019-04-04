#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void newStack(stackT* sp, int maxSize) {
  stackElementT* newContents;

  /* Allocate a new array to hold the contents. */
  newContents = (stackElementT *) malloc(sizeof(stackElementT) * maxSize);

  if (newContents == NULL) {
    fprintf(stderr, "Insufficient memory to initialize stack.\n");
    exit(1);
}
  sp->contents = newContents;
  sp->maxSize = maxSize;
  sp->top = -1;  /* empty stack*/
}

void deleteStack(stackT *stackP) {
  free(stackP->contents);
  stackP->contents = NULL;
  stackP->maxSize = 0;
  stackP->top = -1;
}

void push(stackT* sp, stackElementT e) {
  if (isFullStack(sp)) {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);
  }
  sp->contents[++sp->top] = e;
}

stackElementT pop(stackT* sp) {
  if (isEmptyStack(sp)) {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);
  }
  return sp->contents[sp->top--];
}

int isEmptyStack(stackT* sp) {
  return sp->top < 0;
}

int isFullStack(stackT* sp) {
  return sp->top == sp->maxSize - 1;
}

