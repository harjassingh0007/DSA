#include "testUtils.h"
#include "Bsort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first, void* second){
	return *(int*)first - *(int*)second;
}


void test_arr_contains_no_elements(){
	int arr[] = {};
    Bsort(arr, 0, sizeof(int), cmpInt);
}

void test_arr_contains_1_elements(){
	int arr[] = {1};
	int expected[] = {1};
    Bsort(arr, 1, sizeof(int), cmpInt);
    ASSERT(0 == memcmp(arr, expected, sizeof(expected)));
}
