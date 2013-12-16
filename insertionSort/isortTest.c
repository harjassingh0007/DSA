#include <stdio.h>
#include "testUtils.h"
#include "isort.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char string[256];

int compareInts(void* element1, void* element2){
	return *(int*)element1 - *(int*)element2;
}

int compareChars(void* element1, void* element2){
	return *(char*)element1 - *(char*)element2;
}

int compareString(void* first, void* second){
	return strcmp(*(string*)first,*(string*)second);
}

int compareDoubles(void* first, void* second){
	return *(double*)first - *(double*)second;
}

void test_sort_int_type_data(){
	int arr[5] = {4,5,2,1,3};
	int i, length = 4;
	isort(arr, 5, sizeof(int), compareInts);
	for (i = 0; i < 5; ++i){
		ASSERT(i+1 == *(arr + i));	
	}
}

void test_sort_char_type_data(){
	char arr[] = {'d','e','b','a','c'};
	char expArr[] = {'a','b','c','d','e'};
	int i, length = 4;
	isort(arr, 5, sizeof(char), compareChars);
	for (i = 0; i < 5; ++i){
		ASSERT(*(expArr + i) == *(arr + i));	
	}
}

void test_sort_string_type_data(){
	string arr[] = {"d","e","b","a","c"};
	string expArr[] = {"a","b","c","d","e"};
	int i, length = 4;
	isort(arr, 5, sizeof(string), compareString);
	for (i = 0; i < 5; ++i){
		ASSERT(0 == strcmp(*(expArr + i), *(arr + i)));	
	}
}

void test_sort_double_type_data(){
	double arr[5] = {4.0,5.0,2.0,1.0,3.0};
	int i, length = 4;
	isort(arr, 5, sizeof(double), compareDoubles);
	for (i = 0; i < 5; ++i){
		ASSERT(i+1 == *(arr + i));	
	}
}

