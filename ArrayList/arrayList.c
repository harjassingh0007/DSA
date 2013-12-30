#include "arrayList.h"
#include <stdlib.h>

ArrayList createArrayList(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int insertList(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) 
		return 0;

	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) 
		return NULL;

	return list->base[index];
}

void shiftElementsLeftIfNeeded(ArrayList *list, int index) {
        int i;
        for(i = index;i < list->length-1;i++){
        list->base[i] = list->base[i+1];
    }
}

int ArrayList_add(ArrayList *list,void *data){
    return insertList(list, list->length, data);
}

int remove(ArrayList *list, int index){
	if (index < 0 || index >= list->length) 
		return 0;
	shiftElementsLeftIfNeeded(list, index);
	list->length--;
	return 1;
}

int search(ArrayList *list, void *element, compareFunc cmpFunc){
	int i;
    for(i = 0;i < list->length;i++){
        if(0 == cmpFunc(element,list->base[i]))
            return i;
    }
	return -1;
}

int has_next(Iterator* it){
    ArrayList *list = it->list;
    if(list->length <= it->position) return 0;
    return 1;
}
void* get_next(Iterator* it){
        ArrayList* list = it->list;
    if(!has_next(it)) return NULL;
    return list->base[it->position++];
}
Iterator getIterator(ArrayList* list){
    Iterator it;
    it.list = list;
    it.position = 0;
    it.hasNext = &has_next;
    it.next = &get_next;
    return it;
}

void disposeList(ArrayList *list) {
	free(list->base);
}

