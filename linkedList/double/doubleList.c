#include "doubleList.h"
#include <stdlib.h>

LinkedList* createLinkedList() {
    LinkedList* linkedList = (LinkedList*)calloc(1,sizeof(linkedList));
    linkedList->length = 0;
    linkedList->head = NULL;
    return linkedList;
};

int insertNode(LinkedList* linkedList,void* element,int index){
 	int i;
    Node* nodeToInsert = calloc(1,sizeof(Node));
    Node* node = linkedList->head;
    Node* nextNode;
    nodeToInsert->data = element;
    if(index < 0 || index > (linkedList->length+1) )  
    	return 0 ;
    linkedList->length++;
    if(linkedList->head == NULL){
        linkedList->head = nodeToInsert;
        return 1;
    }
    for(i=1;i<index;i++)
        node = node->next;
    if(index == 0 ){
     	nodeToInsert->next = node;
        node->previous = nodeToInsert;
        linkedList->head = nodeToInsert;
     	return 1;
    }
    nodeToInsert->previous = node;
    nodeToInsert->next = node->next;
    node->next = nodeToInsert;
    if(nodeToInsert->next!=NULL)
            node->next->previous = nodeToInsert;
    return 1;

}