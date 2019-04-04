#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct queue *Queue;

//Queue new(int);

Queue newQueue();

void deleteQueue(Queue Q);

int isEmptyQueue(Queue Q);

int isFullQueue(Queue Q);

void enq(Queue Q, void *x);

void* front(Queue Q);

void* back(Queue Q);

void* deq(Queue Q);

void display(Queue Q);

int sizeQueue( Queue Q);

#endif // _QUEUE_H_
