#include <stdlib.h>
typedef int (*compare)(void* first, void* second);

void Msort(void** base, size_t numberOfElements, compare cmp); 