#include "match.h"
#include <string.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>


Stack *createStack(int size,int length){
        Stack *stack = (Stack*)calloc(1, sizeof(Stack));
        stack->starting_address = calloc(size,length);
        stack->each_size = size;
        stack->total_elements = length;
        stack->top = -1;
        return stack;
}
int isStackFull(Stack *stack){
	if(stack->top == stack->total_elements-1){
		return 0; 
	}
	return 1;
}
int isStackEmpty(Stack *stack){
 	if(stack->top == -1)
 		return 0;
 	return 1;
 }

int push(Stack* data, void* element){
	void* topPtr;
	if(isStackFull(data) == 0)
		return 0; 
	data->top = (data->top) + 1;
	topPtr =  (data->starting_address) + ((data->top)*(data->each_size));
	memcpy(topPtr,element,data->each_size);
	return 1;
}	

void *pop(Stack *stack){
	if(isStackEmpty(stack) == 0)
		return 0;
	--stack->top;
	return (stack->starting_address) + ((stack->each_size)*(stack->top+1));
}

void *top(Stack *stack){
	return (stack->starting_address) + ((stack->each_size)*(stack->top));	
}
char closeBrackets(char character){
    if (character=='(') return ')';
    if (character=='{') return '}';
    if (character=='[') return ']';
    return 0;
}
char checkCloseBracket(char character){
    return (character == ')' || character == '}' || character == ']');
}

int matchBraces(char *string){
	int i,result = 0;
    char expected;
    Stack *stack = createStack(sizeof(char), strlen(string));
    for (i = 0; i < strlen(string); ++i){
        if(closeBrackets(string[i]))
        {
            push(stack, &string[i]);
            expected = closeBrackets(string[i]);
            continue;
        }
    }
    result = isStackEmpty(stack);
    return result;
}