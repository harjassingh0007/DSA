#include "stack.h"
#include <stdlib.h>

Stack *create(int size, int length){
	Stack *stack = malloc(sizeof(Stack));
	stack->base = malloc(sizeof(void*));
	stack->each_size = size;
	stack->top = 0;
	stack->total_elements = length;
	return stack;
}

void** getElement(Stack* stack,int top){
        return stack->base + top * sizeof(void*);
};

int isFull(Stack *stack){
	return stack->top == stack->total_elements;
}

int push(Stack *stack, void *element){
	void *temp;
	if(isFull(stack)){
            temp = realloc(stack->base, stack->total_elements * 2 * sizeof(void*));
            stack->base = temp;
            stack->total_elements *= 2;
        }
    *(getElement(stack, stack->top++)) = element;
    return 1;
}

int isEmpty(Stack* stack){
    return stack->top == 0;
}

void* pop(Stack *stack){
  if(isEmpty(stack)) return NULL;
    return *(getElement(stack,--(stack->top)));
}

void* top(Stack* stack){
    if(isEmpty(stack)) return NULL;
    return *(getElement(stack, (stack->top-1)));
}
