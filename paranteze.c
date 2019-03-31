#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int isOpenParathesis(char c) {
    int result = 0;

    if( c == '(' || c == '{' || c == '[' || c == '<')
        result = 1;

    return result;
}

int isClosedParathesis(char c) {
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
    stackT s;
    char c;
    int i, result = 0;

    new(&s, strlen(expr1));
    for(i = 0; i < strlen(expr1); i++) {
        if (isOpenParathesis(expr1[i]))
            push(&s, expr1[i]);
        else
        if (isClosedParathesis(expr1[i])) {
           c = pop(&s);
           if (!isPair(c, expr1[i])) {
                result = 0;
                break;
           }
            else
                result = 1;
        }
    }
    if (!isEmpty(&s))
        result = 0;

    if(result == 0)
        printf("parantezele sunt puse incorect");
    else
        printf("parantezele sunt puse corect");
    return 0;
}