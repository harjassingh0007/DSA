#include "MergeSort.h"
#include <stdio.h>

void Merge(void** left,void** right, int length, void** base,compare cmp){
	int i = 0, j = 0, k = 0;
	 while(i < length && j < length){
	 	if(cmp(left[i],right[i]) < 0){
	 		base[k] = left[i];
	 		k++,i++;
	 	}
	 	else {
	 		base[k] = right[j];
	 		k++, j++;
	 	}
	}
 	while(i < length){
        base[k] = left[i];
 		k++, i++;	
 	}
    while(j < length){
        base[k] = left[i];
    	k++, i++;
    }
}

void Msort(void **base, size_t numberOfElements, compare cmp){
	int mid = (numberOfElements+1) / 2;
    void** left, **right;
	int i;
    left = calloc((mid+1), sizeof(void));
    right = calloc((mid+1), sizeof(void));
    if(numberOfElements > 1){
    	 for(i = 0; i < mid; i++){
        	left[i] = base[i];
        	right[i] = base[mid+i];
    	}
	    
	    Msort(left , mid, cmp);
	    Msort(right, (numberOfElements-mid), cmp);
	    Merge(left,right,numberOfElements, base, cmp);
	}
	free(left);
	free(right);

}