#include "pQueue.h"
#include <stdlib.h>
#include <memory.h>

Process* createProcess(int priority,int size, int totalElements){
	Process *process = (Process*)calloc(1, sizeof(Process));
	process->job.starting_address = calloc(size, totalElements);
	process->job.each_size = size;
	process->job.total_elements = totalElements;
	process->job.front = 0;
	process->job.rear = 0;
	process->priority = priority;
	return process;
}

int isJobFull(Process *process){
	if(process->job.rear == process->job.total_elements-1){
		return 0; 
	}
	return 1;
}

int enqueue(Process *process, void *element){
	void* lastElement;
	if(isJobFull(process) == 0)
		return 0;
	if(process->job.rear > 0){
		process->job.rear = (process->job.rear) + 1;
	}
	lastElement = (process->job.starting_address) + ((process->job.rear)*(process->job.each_size));
	memcpy(lastElement,element,process->job.each_size);
	return 1;
}