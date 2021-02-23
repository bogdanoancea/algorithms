#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack_l.h"

Stack newStack (){
    Stack S = (Stack)malloc(sizeof(struct stack));
    S->v = 0;
    S->length = 0;
    return S;
}

int isEmpty(Stack S) { 
    return S->length==0; 
}

int size(Stack S) { 
    return S->length; 
}

void *peek(Stack S){
    assert(! isEmpty(S));
    return ((struct node*)(S->v))->data;
}

void push(Stack S, void *x){

    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data = x;
    n->next = S->v;
    S->v = n;
    S->length++;
}

void *pop(Stack S){
    assert(!isEmpty(S));
    struct node *s = S->v;
    void *x = s->data;
    S->v = s->next; 
    free(s);
    S->length--; 
    return x;
}

void deleteStack(Stack S) {
    if(isEmpty(S))
        free(S);
    else {
        while(!isEmpty(S)) {
            pop(S);
        }
        free(S);
    }
}
