typedef struct
{
	void* starting_address;
	int each_size;
	int total_elements;
	int rear;
	int front;
}Queue;

typedef struct
{
	int priority;
	Queue job;
}Process;

Process* createProcess(int priority, int size, int totalElements);
int enqueue(Process *process, void* element);
int isJobFull(Process *process);
void *dequeue(void* process);
