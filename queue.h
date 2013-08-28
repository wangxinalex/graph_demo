#ifndef QUEUE_H
#define QUEUE_H
#define MAX 100

int initializeQueue();
int isEmpty();
int isFull();
int enqueue(void *item);
void * dequeue();


#endif