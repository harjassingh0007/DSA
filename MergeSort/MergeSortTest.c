#include "testUtils.h"
#include "MergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* first, void* second){
	return *(int*)first - *(int*)second;
}

void test_sort_int_type_array(){
	int length = 5;
    int arr[] = {5,4,3,2,1};
    int expected[] = {1,2,3,4,5};
    int i;
    void* base[5] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]};
    Msort(base, 5 ,compareInt);
    for(i = 0; i < length ; i++)
        ASSERT(expected[i] == *(int*)base[i]);
}
