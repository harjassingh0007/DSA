#include "testUtils.h"
#include "pQueue.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "../insertionSort/isort.h"


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Process *data;
Process *expected;

Process create_ints(int length, int *array,int priority){
	int i;
	Process intData = *createProcess(priority, sizeof(int), length);
	for (i = 0; i < intData.job.total_elements; ++i)
	{
		((int *)intData.job.starting_address)[i] = array[i];
	}
	return intData;
}

Process create_chars(int length, char *array, int priority){
	int i;
	Process charData = *createProcess(priority, sizeof(char), length);
	for (i = 0; i < charData.job.total_elements; ++i)
	{
		((char *)charData.job.starting_address)[i] = array[i];
	}
	return charData;
}

typedef char string[100];
Process create_strings(int length, string array, int priority){
	int i;
	Process strData = *createProcess(priority, sizeof(string), length);
	for (i = 0; i < strData.job.total_elements; i++)
	{
		(*(string *)strData.job.starting_address)[i] = *array+i*sizeof(string);
	}
	return strData;
}



int areSizesEqual(Process u1, Process u2) {
	return u1.job.each_size == u2.job.each_size;
}

int areNumElementsEqual(Process u1, Process u2){
	return u1.job.total_elements == u2.job.total_elements;
}
int areRearEqual(Process u1, Process u2){
	return u1.job.rear == u2.job.rear;
}

int areFrontEqual(Process u1, Process u2){
	return u1.job.front == u2.job.front;
}

int arePriorityEqual(Process u1, Process u2){
	return u2.priority == u2.priority;
}

int size_of_aryUtil(Process a) {
	return a.job.each_size * a.job.total_elements;
}

int cmpArrays(Process u1, Process u2) {
	void *a1 = u1.job.starting_address;
	void *a2 = u2.job.starting_address;
	return memcmp(a1,a2,size_of_aryUtil(u1));
}

int areEqual(Process u1,Process u2){
    if(!(areSizesEqual(u1,u2) && areNumElementsEqual(u1,u2) && areRearEqual(u1,u2)
    	&& areFrontEqual(u1,u2)&&arePriorityEqual(u1,u2)))
		return 0;
	return (0 == cmpArrays(u1,u2));
};

int areEqualStrings(Process u1,Process u2){
	int i, result;
	void *item1, *item2;
	for(i = 0; i < u1.job.total_elements; i++){
		item1 = u1.job.starting_address+(i*u1.job.each_size);
		item2 = u2.job.starting_address+(i*u2.job.each_size);
		result = strcmp(*(string*)item1,*(string*)item2);
		if(result == 1){
			return 0;
		}
	}
		return 1;
}

int sortArray(void *first, void *second){
	Process* a = (Process*)first;
	Process* b = (Process*)second;
	return a->priority - b->priority;
}

void test_create_a_job_of_int_type(){
	int temp[] = {0,0,0,0,0};
	Process expected = {1,temp,sizeof(int),5,0,0};
	data = createProcess(1,sizeof(int), 5);
	ASSERT(1 == areEqual(*data, expected));
}

void test_create_a_job_of_char_type(){
	char temp[] = {0,0,0,0,0};
	Process expected = {1,temp,sizeof(char),5,0,0};
	data = createProcess(1,sizeof(char), 5);
	ASSERT(1 == areEqual(*data, expected));
}

void test_create_a_job_of_string_type(){
	string temp[] = {"","","","",""};
	Process expected = {1,temp,sizeof(string),5,0,0};
	data = createProcess(1,sizeof(string), 5);
	ASSERT(1 == areEqual(*data, expected));
}

void test_enqueue_a_job_of_int_type(){
	Process data;
	int arr[] = {1,0,0,0,0};
	int inputArr[] = {0,0,0,0,0};
	int result, element = 1;
	Process expected = {2, arr, sizeof(int), 5 , 0, 0};
	data = create_ints(5, inputArr, 2);
	result = enqueue(&data, &element);
	ASSERT(1 == result && areEqual(data, expected));
}


void test_enqueue_a_job_of_char_type(){
	Process data;
	char arr[] = {'1',0,0,0,0};
	char inputArr[] = {0,0,0,0,0};
	int result;
	char element = '1';
	Process expected = {2, arr, sizeof(char), 5 , 0, 0};
	data = create_chars(5, inputArr, 2);
	result = enqueue(&data, &element);
	ASSERT(1 == result && areEqual(data, expected));
}

void test_enqueue_a_job_of_string_type(){
	Process data;
	string arr[] = {"1",0,0,0,0};
	string inputArr[] = {0,0,0,0,0};
	int result;
	string element = "1";
	Process expected = {2, arr, sizeof(string), 5 , 0, 0};
	data = create_strings(5, inputArr, 2);
	result = enqueue(&data, &element);
	ASSERT(1 == result && areEqualStrings(data, expected));
}

void test_isFull_returns_true(){
	int result;
	int arr[] = {1,2,3,4,5}; 
	Process data = create_ints(5, arr, 1);
	data.job.rear = 4;
	result = isJobFull(&data);
	ASSERT(0 == result);
}

void test_isFull_returns_false(){
	int result;
	int arr[] = {1,2,3,0,0}; 
	Process data = create_ints(5, arr, 1);
	data.job.rear = 2;
	result = isJobFull(&data);
	ASSERT(1 == result);
}

void test_enqueue_a_job_of_int_type_when_it_will_return_false(){
	Process data;
	int inputArr[] = {1,2,3,4,5};
	int result, element = 1;
	data = create_ints(5, inputArr, 2);
	data.job.rear = 4;
	result = enqueue(&data, &element);
	ASSERT(0 == result);
}

void test_enqueue_a_job_of_char_type_when_it_will_return_false(){
	Process data;
	char inputArr[] = {'1','2','3','4','5'};
	int result;
	char element = '1';
	data = create_chars(5, inputArr, 2);
	data.job.rear = 4;
	result = enqueue(&data, &element);
	ASSERT(0 == result);
}

void test_enqueue_a_job_of_string_type_when_it_will_return_false(){
	Process data;
	string inputArr[] = {"1","2","3","4","5"};
	int result;
	string element = "1";
	data = create_strings(5, inputArr, 2);
	data.job.rear = 4;
	result = enqueue(&data, &element);
	ASSERT(0 == result);
}

void test_dequeue_a_job_of_int_type(){
	Process process[3];
	void* result;
	int arr[] = {1,2,3,4,5};
	Process expected = create_ints(5, arr, 1);
	process[0] = create_ints(5, arr , 2);
	process[1] = create_ints(5, arr , 3); 
	process[2] = create_ints(5, arr , 1);
	isort(process, 3, sizeof(Process), sortArray);
	result = dequeue(process);
	ASSERT(areEqual(expected, *(Process*)result));
}


