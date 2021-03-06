#include "testUtils.h"
#include "cqueue.h"
#include <memory.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue create_ints(int length, int *array){
	int i;
	Queue intData = *createQueue(sizeof(int), length);
	for (i = 0; i < intData.total_elements; ++i)
	{
		((int *)intData.starting_address)[i] = array[i];
	}
	return intData;
}

Queue create_chars(int length, char *array){
	int i;
	Queue charData = *createQueue(sizeof(char), length);
	for (i = 0; i < charData.total_elements; ++i)
	{
		((char *)charData.starting_address)[i] = array[i];
	}
	return charData;
}

typedef char string[100];
Queue create_strings(int length, string array){
	int i;
	Queue strData = *createQueue(sizeof(string), length);
	for (i = 0; i < strData.total_elements; i++)
	{
		(*(string *)strData.starting_address)[i] = *array+i*sizeof(string);
	}
	return strData;
}



int areSizesEqual(Queue u1, Queue u2) {
	return u1.each_size == u2.each_size;
}

int areNumElementsEqual(Queue u1, Queue u2){
	return u1.total_elements == u2.total_elements;
}
int areRearEqual(Queue u1, Queue u2){
	return u1.rear == u2.rear;
}
int areFrontEqual(Queue u1, Queue u2){
	return u1.front == u2.front;
}

int size_of_aryUtil(Queue a) {
	return a.each_size * a.total_elements;
}

int cmpArrays(Queue u1, Queue u2) {
	void *a1 = u1.starting_address;
	void *a2 = u2.starting_address;
	return memcmp(a1,a2,size_of_aryUtil(u1));
}

int areEqual(Queue u1,Queue u2){
	if(!(areSizesEqual(u1,u2) && areNumElementsEqual(u1,u2) && areRearEqual(u1,u2) && areFrontEqual(u1,u2)))
		return 0;
	return (0 == cmpArrays(u1,u2));
};

int areEqualStrings(Queue u1,Queue u2){
	int i, result;
	void *item1, *item2;
	for(i = 0; i < u1.total_elements; i++){
		item1 = u1.starting_address+(i*u1.each_size);
		item2 = u2.starting_address+(i*u2.each_size);
		result = strcmp(*(string*)item1,*(string*)item2);
		if(result == 1){
			return 0;
		}
	}
		return 1;
}


void test_create_a_queue_of_int_type(){
	Queue* data;
	int temp[] = {0,0,0,0,0};
	Queue expected = {temp,sizeof(int),5,0,-1};
	data = createQueue(sizeof(int), 5);
	ASSERT(1 == areEqual(*data, expected));
}

void test_create_a_queue_of_char_type(){
	Queue* data;
	char temp[] = {0,0,0,0,0};
	Queue expected = {temp,sizeof(char),5,0,-1};
	data = createQueue(sizeof(char), 5);
	ASSERT(1 == areEqual(*data, expected));
}

void test_create_a_queue_of_string_type(){
	Queue* data;
	string temp[] = {"","","","",""};
	Queue expected = {temp,sizeof(string),5,0,-1};
	data = createQueue(sizeof(string), 5);
	ASSERT(1 == areEqual(*data, expected));
}

void test_enqueue_an_item_into_int_type_queue(){
	Queue data;
	int result, element = 1;
	int arr[] = {0,0,0,0,0};
	int expArr[] = {1,0,0,0,0};
	Queue expected = {expArr,sizeof(int),5,0,-1};
	data = create_ints(5, arr);
	data.front = -1 , data.rear = 0;
	result = enqueue(&data, &element);
	ASSERT(1 == result && areEqual(expected, data));
}

void test_enqueue_an_item_into_char_type_queue(){
	Queue data;
	char result;
	int element = '1';
	char arr[] = {0,0,0,0,0};
	char expArr[] = {'1',0,0,0,0};
	Queue expected = {expArr,sizeof(char),5,0,-1};
	data = create_chars(5, arr);
	data.front = -1 , data.rear = 0;
	result = enqueue(&data, &element);
	ASSERT(1 == result && areEqual(expected, data));
}

void test_enqueue_an_item_into_string_type_queue(){
	Queue data;
	int result;
	string element = "a";
	string arr[] = {"c","b",0,0,0};
	string expArr[] = {"c","b","a",0,0};
	Queue expected = {expArr,sizeof(string),5,3,0};
	data = create_strings(5, arr);
	data.front = 0 , data.rear = 2;
	result = enqueue(&data, &element);
	ASSERT(1 == result && areEqualStrings(data, expected));
}

void test_enqueue_an_item_into_int_type_queue_when_it_is_full(){
	Queue data;
	int result, element = 1;
	int arr[] = {0,0,0,0,0};
	data = create_ints(5, arr);
	data.rear = 4;
	result = enqueue(&data, &element);
	ASSERT(0 == result);
}

void test_enqueue_an_item_into_char_type_queue_when_it_is_full(){
	Queue data;
	int result;
	char element = 1;
	char arr[] = {0,0,0,0,0};
	data = create_chars(5, arr);
	data.rear = 4;
	result = enqueue(&data, &element);
	ASSERT(0 == result);
}

void test_enqueue_an_item_into_string_type_queue_when_it_is_full(){
	Queue data;
	int result;
	string element = "a";
	string arr[] = {"","","","",""};
	data = create_strings(5, arr);
	data.rear = 4;
	result = enqueue(&data, &element);
	ASSERT(0 == result);
}

void test_dequeue_an_item_from_int_type_queue(){
	int arr[] = {4,5,1,3};
    void* result;
   	Queue queue = create_ints(5, arr);
   	queue.front = 0, queue.rear = 4;
    result = dequeue(&queue);
    ASSERT(*(int*)result == 4);
}

void test_dequeue_an_item_from_char_type_queue(){
	char arr[] = {'4','5','1','3'};
    void* result;
   	Queue queue = create_chars(5, arr);
   	queue.front = 0, queue.rear = 4;
    result = dequeue(&queue);
    ASSERT(*(char*)result == '4');
}

void test_dequeue_an_item_from_string_type_queue(){
	string arr[] = {"4","5","1","3"};
    void* result;
   	Queue queue = create_strings(5, arr);
   	queue.front = 0, queue.rear = 4;
    result = dequeue(&queue);
    ASSERT(strcmp(*(string*)result, "4"));
}

