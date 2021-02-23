#include <stdio.h>
#include <string.h>
#include "stack_l.h"

int main(void)
{
  Stack S;
  char str[101];
  char *traverse;

  printf("Enter a string: ");
  gets(str);

  /*
   * Initialize the stack.  Make it at least
   * big enough to hold the string we read in.
   */
  newStack(S);

  /*
   * Traverse the string and put each
   * character on the stack.
   */

  for (traverse = str; *traverse != '\0'; traverse++) {
    push(S, (void*)traverse);
  }

  printf("\nStack size:%d\n", size(S));
  printf("\nTop element is:%c\n", *(char*)peek(S));
  /*
   * Pop each of the characters off of
   * the stack and print them out.
   */

  printf("\nPopped characters are: ");

  while (!isEmpty(S)) {
    printf("%c", *(char*)pop(S));
  }

  printf("\nStack size:%d\n", size(S));
  printf("\n");
  deleteStack(S);

  return 0;
}
