#include "hashMap.h"
#include "../ArrayList/arrayList.h"
#include "D:/DSA/doublelist/doubleList.h"
#include <stdlib.h>

typedef struct hn {
        void* key;
        void* value;
} HashNode;

HashMap createHashMap(HashCodeGenerator getHashCode, cmpFunc cmp, int capacity){
	HashMap map;
	int i;
	DoubleList *listOfObjects;
    ArrayList listOfBuckets = createArrayList(capacity);
    map.buckets =  calloc(1, sizeof(ArrayList));
    *(ArrayList*)map.buckets = listOfBuckets;
    map.capacity = capacity;
    map.compare = cmp;
    map.getHashCode = getHashCode;
    for(i=0;i<capacity;i++)
       ArrayList_add(map.buckets,  malloc(sizeof(DoubleList)));
	return map;
}


void* getHashObject(HashMap *map,void *key){
    return NULL;
};

HashNode* createHashNode(void *key, void *value){
    HashNode *hash_node = malloc(sizeof(HashMap));
    hash_node->key = key;
    hash_node->value = value;
    return hash_node;
}

int put(HashMap *map, void *key, void *data){
	DoubleList *listOfObjects;
    HashNode* hash_node;
    int bucketIndex, hashCode;
    if(map == NULL || key == NULL) return 0;
        return 1;
    bucketIndex = (map->getHashCode(key)) % map->capacity;
    hash_node = createHashNode(key, data);
    listOfObjects = (DoubleList*)get(map->buckets, bucketIndex);
    insert(listOfObjects, listOfObjects->length, hash_node);
    return 1;
}

void* get_hashMap(HashMap *map, void *key){
    int bucket_index;
    DoubleList *list;
    HashNode *hash_node;
    bucket_index = (map->getHashCode(key)) % map->capacity;
    list = (DoubleList*)get(map->buckets, bucket_index);
    hash_node = getData(*list, key, map->compare);
    if(hash_node){
        return hash_node->key;
    }
    return NULL;
}











