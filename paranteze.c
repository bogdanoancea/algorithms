#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int isOpenParanthesis(char c) {
    int result = 0;

    if( c == '(' || c == '{' || c == '[' || c == '<')
        result = 1;

    return result;
}

int isClosedParanthesis(char c) {
    int result = 0;

    if( c == ')' || c == '}' || c == ']' || c == '>')
        result = 1;

    return result;
}

int isPair(char c1, char c2) {
    int result = 0;
    if ( c1 == '(' && c2 ==')')
        result = 1;
    if ( c1 == '{' && c2 =='}')
        result = 1;
    if ( c1 == '[' && c2 ==']')
        result = 1;
    if ( c1 == '<' && c2 =='>')
        result = 1;

    return result;
}


int main () {
    char* expr1 = "{A[B<C><D>(E)F](G)}";
    char* expr2 = "{A[B}]";
    stackType s;
    char c;
    int i, result = 0;

	char sir[81];
	scanf("%s", sir);
	while(strcmp(sir, ".")!=0) {
		result = 0;
		newStack(&s, strlen(sir));
		for(i = 0; i < strlen(sir); i++) {
			if (isOpenParanthesis(sir[i]))
				push(&s, sir[i]);
			else
			if (isClosedParanthesis(sir[i])) {
			   c = pop(&s);
			   if (!isPair(c, sir[i])) {
					result = 0;
					break;
			   }
				else
					result = 1;
			}
		}
		if (!isEmpty(&s))
			result = 0;
		
		deleteStack(&s);

		if(result == 0)
			printf("parantezele sunt puse incorect\n");
		else
			printf("parantezele sunt puse corect\n");
		
		scanf("%s", sir);
		
	}
    return 0;
}
