#include "queue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//implementare cu tablouri simple

struct queue {
    int v;	//varf (inceput) coada
    int b;	//baza (sfarsit) coada
    int n;	//numar de elemente din coada
    int c;	//dimens. memorie alocata
    void **data;	//tablou elemente
};


Queue newQueue(int cap){
	Queue Q;
	Q=(Queue)malloc(sizeof(struct queue));
	Q->v = Q->b = Q->n = 0;
	Q->c = cap;
	Q->data = (void**)malloc(cap*sizeof(void*));
	return Q;
}
int isEmptyQueue(Queue Q) {
	return Q->n == 0;
}
int isFullQueue(Queue Q) {
	return Q->n == Q->c;
}

void enq(Queue Q, void *x){
	assert(!isFullQueue(Q));
	Q->data[Q->b++] = x;
	 if(Q->b == Q->c)
		Q->b = 0;
	Q->n++;
}

void *deq(Queue Q){
    assert(!isEmptyQueue(Q));
	void *x = Q->data[Q->v++];
	if(Q->v == Q->c)
	 	Q->v = 0;
	Q->n--;
	return x;
}
void *front(Queue Q){
	assert(!isEmptyQueue(Q));
	return Q->data[Q->v];
}

void *back(Queue Q){
	assert(!isEmptyQueue(Q));
	return Q->data[Q->b-1];
}

int sizeQueue(Queue Q){
	return Q->n;
}

void display(Queue Q) {
    assert(!isEmptyQueue(Q));
    int vv = Q->v;
    int bb = Q->b;
    while(vv != bb) {
        printf("%d\n", *(int*)Q->data[vv++]);
    }
}

void deleteQueue(Queue Q) {
	if(Q) {
		if(Q->n == 0) {
			free(Q);
		}
		else {
		    int vv = Q->v;
    		int bb = Q->b;
    		while(vv != bb) {
        		free(Q->data[vv++]);
    		}
			free(Q->data);
			free(Q);
		}
	}
}
Queue newQueue2(){return NULL;}
