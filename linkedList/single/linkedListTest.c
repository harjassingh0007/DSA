#include "testUtils.h"
#include "linkedList.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
List *list;

void test_1_create_linked_list(){
	list = create();
	ASSERT(list->start == NULL && list->length == 0);
}

void test_2_insert_a_node_in_the_linkedList(){
}
