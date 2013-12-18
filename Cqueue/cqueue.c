#include "cqueue.h"
#include <stdlib.h>
#include <memory.h>

Queue* createQueue(int size, int totalElements){
	Queue *queue = (Queue*)calloc(1, sizeof(Queue));
	queue->starting_address = calloc(size, totalElements);
	queue->each_size = size;
	queue->total_elements = totalElements;
	queue->front = -1;
	queue->rear = 0;	
	return queue;
}

int isQueueFull(Queue *queue){
	if(queue->rear == queue->total_elements-1){
		return 0; 
	}
	return 1;
}

int enqueue(Queue* queue, void* element){
	void* lastElement;
	if(isQueueFull(queue) == 0)
		return 0;
	if(queue->rear > 0){
		queue->rear = (queue->rear) + 1;
	}
	lastElement = (queue->starting_address) + ((queue->rear)*(queue->each_size));
	memcpy(lastElement,element,queue->each_size);
	return 1;
}

void* dequeue(Queue *queue){
    if(queue->front == queue->rear)
            return NULL;
	queue->front = (queue->front + 1) % queue->total_elements;
	if(queue->front == queue->rear){
		queue->front = -1;
		queue->rear = 0;
	}
	return queue->starting_address;
}