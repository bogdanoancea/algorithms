#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(void)
{
  stackType stack;
  char str[101];
  char *traverse;

  printf("Enter a string: ");
  gets(str);

  /*
   * Initialize the stack.  Make it at least
   * big enough to hold the string we read in.
   */
  newStack(&stack, strlen(str));

  /*
   * Traverse the string and put each
   * character on the stack.
   */

  for (traverse = str; *traverse != '\0'; traverse++) {
    push(&stack, *traverse);
  }

  printf("\nStack size:%d\n", size(&stack));
  printf("\nTop element is:%c\n", peek(&stack));
  /*
   * Pop each of the characters off of
   * the stack and print them out.
   */

  printf("\nPopped characters are: ");

  while (!isEmpty(&stack)) {
    printf("%c", pop(&stack));
  }

  printf("\nStack size:%d\n", size(&stack));
  printf("\n");
  deleteStack(&stack);

  return 0;
}
