#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int front, rear;
void * queue[MAX];

int initializeQueue(){
	
	front = rear = 0;
	int i;
	for(i = 0; i < MAX; i++){
		queue[i] = NULL;
	}
}

int isEmpty(){
	return front == rear && queue[front] == NULL;
}

int isFull(){
	return front == rear && queue[front] != NULL;
}
int enqueue(void *item){
	if(isFull()){
		fprintf(stderr, "The queue is full\n");
		return -1;
	}
	queue[rear] = item;
	rear = (rear + 1) % MAX;
	return 0;	
}

void * dequeue(){
	if(isEmpty()){
		fprintf(stderr, "The queue is empty\n");
		return NULL;
	}
	void * item = calloc(1, sizeof(int));
	memcpy(item, queue[front], sizeof(int));
	
	queue[front] = NULL;
	front = (front + 1) % MAX;
	
	return item;
}

int size(){
	return rear > front ? (rear - front) : (front - rear);
}

