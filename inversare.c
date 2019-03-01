#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(void)
{
  stackT stack;
  char str[101];
  char *traverse;

  printf("Enter a string: ");
  gets(str);

  /*
   * Initialize the stack.  Make it at least
   * big enough to hold the string we read in.
   */
  new(&stack, strlen(str));

  /*
   * Traverse the string and put each
   * character on the stack.
   */

  for (traverse = str; *traverse != '\0'; traverse++) {
    push(&stack, *traverse);
  }

  /*
   * Pop each of the characters off of
   * the stack and print them out.
   */

  printf("\nPopped characters are: ");

  while (!isEmpty(&stack)) {
    printf("%c", pop(&stack));
  }

  printf("\n");
  destroy(&stack);
  return 0;
}
