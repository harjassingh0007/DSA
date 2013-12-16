#include "testUtils.h"
#include "binarySearch.h"
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* key, void* element){
	return *(int*)element - *(int*)key;
}

int compareChar(void* key, void* element){
	return *(char*)element - *(char*)key;
}

void test_1_search_an_int_from_mid_of_arr(){
	int arr[5] = {1,2,3,4,5};
	int element = 3;
	void* result;
	result = bSearch(&element, arr, 5, sizeof(int), compareInt);
	ASSERT(*(int*)result == 3);
}

void test_2_search_an_int_from_rightSide_of_arr(){
	int arr[5] = {1,2,3,4,5};
	int element = 2;
	void* result;
	result = bSearch(&element, arr, 5, sizeof(int), compareInt);
	ASSERT(*(int*)result == 2);
}

void test_3_search_an_int_from_leftSide_of_arr(){
	int arr[5] = {1,2,3,4,5};
	int element = 5;
	void* result;
	result = bSearch(&element, arr, 5, sizeof(int), compareInt);
	ASSERT(*(int*)result == 5);
}

void test_4_search_an_int_from_arr_when_it_is_not_present(){
	int arr[5] = {1,2,3,4,5};
	int element = 7;
	void* result;
	result = bSearch(&element, arr, 5, sizeof(int), compareInt);
	ASSERT(NULL == result);
}

void test_5_search_an_char_from_mid_of_arr(){
	char arr[5] = {'1','2','3','4','5'};
	char element = '3';
	void* result;
	result = bSearch(&element, arr, 5, sizeof(char), compareChar);
	ASSERT(*(char*)result == '3');
}

void test_6_search_an_char_from_leftSide_of_arr(){
	char arr[5] = {'1','2','3','4','5'};
	char element = '1';
	void* result;
	result = bSearch(&element, arr, 5, sizeof(char), compareChar);
	ASSERT(*(char*)result == '1');
}

void test_7_search_an_char_from_leftSide_of_arr(){
	char arr[5] = {'1','2','3','4','5'};
	char element = '4';
	void* result;
	result = bSearch(&element, arr, 5, sizeof(char), compareChar);
	ASSERT(*(char*)result == '4');
}