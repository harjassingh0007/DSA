typedef struct 
{
	void **base;
	int total_elements;
	int each_size;
	int top;
}Stack;

Stack* create(int size, int length);
int push(Stack *stack,void *element);
void *pop(Stack *stack);
void *top(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);