#include "doubleList.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList* createLinkedList() {
    LinkedList* linkedList = (LinkedList*)calloc(1,sizeof(linkedList));
    linkedList->length = 0;
    linkedList->head = NULL;
    return linkedList;
};

void insertNodeInBetween(LinkedList* linkedList,int index){

}


int insertNode(LinkedList* linkedList,void* element,int index){
    int i = 0;
    Node* nodeToInsert = calloc(1,sizeof(Node));
    nodeToInsert->data = element;
    if(index == 0){
        linkedList->head = nodeToInsert;
        linkedList->head->previous = NULL;
        linkedList->head->data = element;
        linkedList->head->next = NULL;
        linkedList->length++;
        return 1;
    }
    if(index == linkedList->length){
        linkedList->head->previous = nodeToInsert;
        linkedList->head->data = element;
        linkedList->head->next = NULL;
        linkedList->length++;
       return 1;
    }
    if(index > 0 && index < linkedList->length){
        insertNodeInBetween(linkedList,index);      
        return 1;
    }
    return 0;
}

void *removeNode(LinkedList *list, int index){
    Node* temp = calloc(1, sizeof(Node));
    temp = list->head->next;
    if(index == 0){
        list->head = temp;
        return list->head->data;
    }
    // return NULL;
}