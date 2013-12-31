#include "testUtils.h"
#include "Bsort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first, void* second){
	return *(int*)first - *(int*)second;
}

int cmpchar(void* first, void* second){
	return *(char*)first - *(char*)second;
}

void test_arr_contains_1_elements(){
	int i;
	int arr[] = {1};
	int expected[] = {1};
	void *data = &arr[0];
    Bsort(data, 1, sizeof(int), cmpInt);
    for(i = 0; i < 1; i++){
	    ASSERT(arr[i] == expected[i]);
    }
}

void test_arr_contains_more_than_1_elements(){
	int i;
	int arr[] = {2,3,1,5,4};
	void *data[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]};
	int expected[] = {1,2,3,4,5};
    Bsort(data, 5, sizeof(int), cmpInt);
    for(i = 0; i < 5; i++){
	    ASSERT(*(int*)data[i] == expected[i]);
    }
}


void test_arr_contains_more_than_1_elements_of_char_type(){
	int i;
	char arr[] = {2,3,1,5,4};
	void *data[] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]};
	char expected[] = {1,2,3,4,5};
    Bsort(data, 5, sizeof(char), cmpchar);
    for(i = 0; i < 5; i++){
	    ASSERT(*(char*)data[i] == expected[i]);
    }
}