#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_int.h"


int isNumber(char* c) {
	int result = 0;
	int i;
	for( i = 0; i < strlen(c); i++) {
		if(c[i] == '0' || c[i] == '1' || c[i] == '2' || c[i] == '3' || c[i] == '4' || c[i] == '5' || c[i] == '6' || c[i] == '7' || c[i] == '8' || c[i] == '9')
			result = 1;
		else {
			result = 0;
			break;
		}
	}	
	return result;
}

// aduna numere intregi pozitive
int main () {
    stackType s;
    char cuvant[100];
    int result = 0;
	int num;
	scanf("%s", cuvant);
	newStack(&s, 800);
	while(strcmp(cuvant, "s") !=0) {
		result = 0;
		if(isNumber(cuvant)) {
			num = atoi(cuvant);
			push(&s, num);
		}
		if(strcmp(cuvant,",") == 0) {
			pop(&s);
		}
		if(strcmp(cuvant, ".") == 0) {
			while(!isEmpty(&s))
				pop(&s);
		}
		if(strcmp(cuvant, "+") == 0) {
			while(!isEmpty(&s) )
				result += pop(&s);
			printf("Suma:%d\n", result);

		}
		scanf("%s", cuvant);
	}
    return 0;
}
