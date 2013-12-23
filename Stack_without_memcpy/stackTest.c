#include "testUtils.h"
#include "stack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_push_element_of_int_type_into_a_stack(){
	int element = 1, result;
	Stack *stack = create(sizeof(int), 5);
	result = push(stack, &element);
	ASSERT(result == 1);
}

void test_push_element_of_char_type_into_a_stack(){
	char element = '1';
	int result;
	Stack *stack = create(sizeof(char), 5);
	result = push(stack, &element);
	ASSERT(result == 1);
}

void test_push_element_of_double_type_into_a_stack(){
	double element = '1';
	int result;
	Stack *stack = create(sizeof(double), 5);
	result = push(stack, &element);
	ASSERT(result == 1);
}

void test_isFull_will_tell_that_stack_is_full(){
	Stack *stack = create(sizeof(int), 5);
	int result;
	result = isFull(stack);
	ASSERT(0 == result);
}

void test_isFull_will_tell_that_stack_is_not_full(){
	Stack *stack = create(sizeof(int), 5);
	int result;
	stack->top = 1;
	stack->total_elements = 1;
	result = isFull(stack);
	ASSERT(1 == result);
}

void test_pop_an_element_from_int_type_stack(){
	Stack *stack = create(sizeof(int), 3);
	void* result;
	int arr[] = {1,2,3};
	push(stack, &arr[0]);
	push(stack, &arr[1]);
	push(stack, &arr[2]);
	result = pop(stack);
	ASSERT(*(int*)result == 3);

	result = pop(stack);
	ASSERT(*(int*)result == 2);
}


void test_pop_an_element_from_char_type_stack(){
	Stack *stack = create(sizeof(char), 3);
	void* result;
	char arr[] = {'1','2','3'};
	push(stack, &arr[0]);
	push(stack, &arr[1]);
	push(stack, &arr[2]);
	result = pop(stack);
	ASSERT(*(char*)result == '3');

	result = pop(stack);
	ASSERT(*(char*)result == '2');
}

void test_isEmpty_will_tell_that_stack_is_Empty(){
	Stack *stack = create(sizeof(int), 5);
	int result;
	stack->top = 5;
	result = isFull(stack);
	ASSERT(1 == result);	
}


void test_isEmpty_will_tell_that_stack_is_not_Empty(){
	Stack *stack = create(sizeof(int), 5);
	int result;
	stack->top = 3;
	result = isFull(stack);
	ASSERT(0 == result);	
}

void test_top_function_will_give_element_at_top_of_stack(){
	Stack* stack = create(sizeof(int), 3);
	int arr[] = {1,2,3};
	void *result;
	push(stack, &arr[0]);
	push(stack, &arr[1]); 
	push(stack, &arr[2]); 
	result = top(stack);
	ASSERT(3 == *(int*)result);
}