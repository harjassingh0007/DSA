#include <stdio.h>
#include <stdlib.h>
struct Node
{
	void *data;
	struct Node *link;	
};

typedef struct 
{
	struct Node *start;
	int length;
}List;

List *create();
List *insert(List* list, int index, void* data);