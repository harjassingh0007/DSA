#include "linkedList.h"

List *create(){
	List* head = (List*)calloc(sizeof(List),1);
	head->start =NULL;
	head->length = 0;
	return head;
}
