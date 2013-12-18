#include "stack.h"
#include <stdlib.h>

void *create(int size, int length){
	Stack *stack = malloc(sizeof(Stack));
	stack->base = malloc(sizeof(void*));
	stack->each_size = size;
	stack->top = 0;
	stack->total_elements = length;
	return stack;
}