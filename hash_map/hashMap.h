#include "D:\DSA\iterator/iterator.h"


typedef int (*HashCodeGenerator)(void *key);
typedef int (*cmpFunc)(void *first,void *second);

#ifndef _HASHMAP_
#define _HASHMAP_
typedef struct {
    void *buckets;
    int capacity;
    HashCodeGenerator getHashCode;
    cmpFunc compare;
} HashMap;

HashMap createHashMap(HashCodeGenerator getHashCode,cmpFunc cmp,int capacity);
int put(HashMap *mapCode, void *key, void *data);
void* get_hashMap(HashMap* map, void* key);
int remove_hashMap(HashMap* map, void* key);
Iterator HashMap_keys(HashMap *map);
void rehash(HashMap* map);
#endif