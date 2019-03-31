#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue *Queue;

//Queue new(int);

Queue new();

void delete(Queue *pQ);

int isEmpty(Queue Q);

int isFull(Queue Q);

void enq(Queue Q, void *x);

void* front(Queue Q);

void* back(Queue Q);

void* deq(Queue Q);

void display(Queue Q);

int size( Queue Q);

#endif // _QUEUE_H_
