#include "testUtils.h"
#include "doubleList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_double_linkedList(){
	LinkedList *list;
	list = createLinkedList(); 
    ASSERT(list->length == 0 && list->head == NULL);
    free(list);
};

void test_insert_node_of_int_type_in_linked_list(){
	LinkedList *list;
    int result , _1 = 1;
    void *element = calloc(1, sizeof(int));
    memcpy(element, &_1, sizeof(int));
    result = insertNode(list,&element,0);
    ASSERT(1 == result);
    ASSERT(NULL == list->head->next);
    ASSERT(NULL == list->head->previous);
    ASSERT(_1 == *(int*)list->head->data);
};
