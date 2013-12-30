#include "Bsort.h"
#include <stdio.h>

void Bsort(void **base, size_t numberOfElements, size_t elementSize, compare *comp){
    int i, j;
    void *temp;
    if(numberOfElements <=1)    return;
    for (i = 1; i < numberOfElements; ++i) {
        for (j = 0; j < (numberOfElements-i) ; j++){
            if(comp(base[j],base[j+1]) > 0){
		       temp = base[j];
		       base[j] = &base[j+1];
		       base[j+1] = temp;
			}
   		}
    }
    return;
}