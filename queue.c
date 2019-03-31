#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node{
	void	*data;
 	struct	node *next;
};

struct queue{
	int length;
	struct node *first;
	struct node *last;
};

Queue new (){
	Queue Q=(Queue)malloc(sizeof(struct queue));
	Q->length=0;
	Q->first = Q->last = 0;
	return Q;
}

int size(Queue Q){
	return Q->length;
}

int isEmpty(Queue Q){
	return Q->length==0;
}

void *front(Queue Q){
	assert(!isEmpty(Q));
	return Q->first->data;
}

void *back(Queue Q){
	assert(!isEmpty(Q));
	return Q->last->data;
}

void enq(Queue Q, void *x){
	struct node *nou = (struct node*)malloc(sizeof(struct node));
	nou->data = x;
	nou->next = 0;
	if(Q->last==0)
	    Q->first = nou;
	else
	    Q->last->next = nou;
	Q->last = nou;
	Q->length++;
}

void *deq(Queue Q){
    assert(!isEmpty(Q));
     void *x = Q->first->data;
     struct node *del = Q->first;
     Q->first = Q->first->next;
     if(Q->first == 0)
        Q->last = 0;
     free(del);
     Q->length--;
     return x;
}

void display(Queue Q) {
    assert(!isEmpty(Q));
    struct node* p = Q->first;
    printf("%d\n", *(int*)p->data);
    while(p->next != NULL) {
        p = p->next;
        printf("%d\n", *(int*)p->data);
    }
}