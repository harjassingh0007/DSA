#include "MergeSort.h"
#include <stdio.h>

void Merge(void** left,void** right, int leftSide, int rightSide, int length, void** base,compare cmp){
	void **temp = malloc(length*2*sizeof(void));
	int i, j, k;
	for(i = 0; i < length; i++){
		if(j > leftSide-1){
       		 temp[i] = right[k];
	printf("%s\n","helloooo");
       	}
        else if(k > (rightSide-1)){
            temp[i] = left[j];
        }
        else if(cmp(left[j], right[k]) > 0){
            temp[i] = right[k];
            k++;
        }
        else{
            temp[i] = left[j];
            j++;
        }
	}
	for(i=0;i<length;i++)
        base[i] = temp[i];
    free(temp);
}

void Msort(void **base, size_t numberOfElements, compare cmp){
	int mid = numberOfElements / 2;
    void** left, **right;
	int i;
    left = calloc((mid+1), sizeof(void));
    right = calloc((mid+1), sizeof(void));
    if(numberOfElements > 1){
    	 for(i = 0; i < mid; i++){
        	left[i] = base[i];
        	right[i] = base[mid+(i)];
    	}
	    
	    Msort(left , mid, cmp);
	    Msort(right, (numberOfElements-mid), cmp);
	    Merge(left,right, mid, numberOfElements-mid,numberOfElements, base, cmp);
	}
	free(left);
	free(right);

}