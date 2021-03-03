#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int isNumber(char c) {
	int result = 0;
	if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
		result = 1;

	return result;
}

int toNumber(char c) {
	int result = 0;
	if(c == '0')
		result = 0;
	if(c == '1')
		result = 1;
	if(c == '2')
		result = 2;
	if(c == '3')
		result = 3;
	if(c == '4')
		result = 4;
	if(c == '5')
		result = 5;
	if(c == '6')
		result = 6;
	if(c == '7')
		result = 7;
	if(c == '8')
		result = 8;
	if(c == '9')
		result = 9;

	return result;
}

// aduna numere formate dintr-o singura cifra
int main () {
    stackType s;
    char c;
    int result = 0;

    newStack(&s, 80);
	scanf("%c", &c);

	while(c != 's') {
		result = 0;
		if(isNumber(c)) {
			push(&s, c);
		}
		if(c == ',') {
			pop(&s);
		}
		if(c == '.') {
			while(!isEmpty(&s))
				pop(&s);
		}
		if(c == '+') {
			while(!isEmpty(&s) )
				result += toNumber(pop(&s));

			printf("Suma:%d\n", result);

		}
		scanf("%c", &c);
	}
    return 0;
}
