#include "../iterator/iterator.h"

typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int (*compareFunc)(void* first,void *second);

ArrayList createArrayList(int capacity);

int insertList(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

int ArrayList_add(ArrayList *list,void *data);

int remove(ArrayList *list, int index);

int search(ArrayList *list, void *element,compareFunc cmpFunc);

Iterator getIterator(ArrayList* list);

void disposeList(ArrayList *list);