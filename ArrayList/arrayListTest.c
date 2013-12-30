#include <stdlib.h>

#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = createArrayList(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	disposeList(internsPtr);	
}

void test_insertList_element(){
	int result = insertList(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insertList_multiple_elements() {
	insertList(internsPtr, 0, &prateek);
	insertList(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = createArrayList(noOfElements);
	ArrayList *listPtr = &list;

	insertList(listPtr, 0, &prateek);
	insertList(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	disposeList(listPtr);		
}

void test_should_not_insertList_at_index_beyond_length() {
	int result = FAILURE;
	result = insertList(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insertList_at_negative_index() {
	int result = FAILURE;
	result = insertList(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insertList_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insertList(internsPtr, 0, &prateek);
	insertList(internsPtr, 1, &ji);
	insertList(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insertList_when_list_is_null() {
	int result = insertList(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}


void test_remove_element_from_arrayList_from_last(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insertList(internsPtr, 0, &prateek);
	insertList(internsPtr, 1, &ji);
	insertList(internsPtr, 2, &tanbirka);
	result = remove(internsPtr, 2);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
	ASSERT(SUCCESS == result);
}

void test_remove_element_from_arrayList_from_middle(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insertList(internsPtr, 0, &prateek);
	insertList(internsPtr, 1, &ji);
	insertList(internsPtr, 2, &tanbirka);
	result = remove(internsPtr, 1);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(SUCCESS == result);
}

int compareInterns(void* first, void* second){
	Intern I_1 = *(Intern*)first ;
	Intern I_2 = *(Intern*)second ;
	return (I_1.id - I_2.id);
}

void test_search_element_from_arrayList(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insertList(internsPtr, 0, &prateek);
	insertList(internsPtr, 1, &ji);
	insertList(internsPtr, 2, &tanbirka);
	result = search(internsPtr, &tanbirka, compareInterns);
	ASSERT(2 == result);
}

void test_search_element_from_arrayList_from_starting_index(){
	int result;
	Intern tanbirka = {43343, "Tanbir Ka"};
	insertList(internsPtr, 0, &prateek);
	insertList(internsPtr, 1, &ji);
	insertList(internsPtr, 2, &tanbirka);
	result = search(internsPtr, &prateek, compareInterns);
	ASSERT(0 == result);
}

void test_check_hasNext_using_iterator(){
    Iterator it = getIterator(internsPtr);
    insertList(internsPtr, 0, &prateek);
    remove(internsPtr, 0);
    ASSERT(0 == it.hasNext(&it));
}

void test_check_getNext_using_iterator(){
    Iterator it = getIterator(internsPtr);
    insertList(internsPtr, 0, &prateek);
    insertList(internsPtr, 1, &ji);
    ASSERT(18 == (*(Intern*)(it.next(&it))).age);
    ASSERT(17 == (*(Intern*)(it.next(&it))).age);
}