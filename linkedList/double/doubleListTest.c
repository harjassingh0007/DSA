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

void test_insert_node__in_linked_list_at_starting(){
	LinkedList *list = createLinkedList();
    int result , _1 = 1;
    result = insertNode(list,&_1,0);
    ASSERT(1 == result);
    free(list);
};


void test_insert_node_in_linked_list_at_end(){
    LinkedList *list = createLinkedList();
    int result , _1 = 1, _2 = 2;
    insertNode(list, &_1, 0);
    result = insertNode(list, &_2, 1);
    ASSERT(1 == result);
    free(list);
};

void test_insert_node_in_linked_list_at_end_having_many_nodes(){
    LinkedList *list = createLinkedList();
    int result , _1 = 1, _2 = 2;
    insertNode(list, &_1, 0);
    insertNode(list, &_1, 1);
    insertNode(list, &_1, 2);
    result = insertNode(list, &_2, 3);
    ASSERT(1 == result);
    free(list);
};

void test_insert_node_in_linked_list_in_middle(){
    LinkedList *list = createLinkedList();
    int result , _1 = 1;
    insertNode(list, &_1, 0);
    insertNode(list, &_1, 1);           // Not Completed//
    insertNode(list, &_1, 2);
    insertNode(list, &_1, 3);
    result = insertNode(list, &_1, 2);
    ASSERT(1 == result);
    free(list);
};

void test_delete_node_from_starting_in_linkedList(){
    LinkedList *list = createLinkedList();
    int _1 = 1,_2 = 2,_3 = 3;
    void* result;
    insertNode(list, &_1, 0);
    insertNode(list, &_2, 1);
    insertNode(list, &_3, 2);
    result = removeNode(list, 0);    
    ASSERT(1 == *(int*)result);
}




