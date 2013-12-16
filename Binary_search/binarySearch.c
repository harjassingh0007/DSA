#include "binarySearch.h"
#include <stdio.h>
#include <string.h>

void *bSearch(void *key, void *base, int length, int elementSize, int (*compar)(void *, void *)){
	int i;
	void* element;
	int start = 0;
	int midEle = ((start + length)/2)+1;
	for(i = 0; i < midEle; i++){
		int outputOfCmp = 0;
		midEle = (start+length)/2;
		if(midEle == 1){
			if(0 == compar(key,base))
				return base;
		}
		if(midEle == length-1){
			element = base + (length-1) * elementSize;
			outputOfCmp = compar(key,element);
			if(outputOfCmp==0)
				return element;
		}
		element = base+midEle*elementSize;
		outputOfCmp = compar(key,element);
		if(outputOfCmp==0)
			return element;
		(outputOfCmp<0) ? start=midEle : (length=midEle);
	}
	return NULL;
}