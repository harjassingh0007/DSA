
typedef int (*HashCodeGenerator)(void *key);
typedef int (*cmpFunc)(void *first,void *second);

typedef struct {
    void *buckets;
    int capacity;
    HashCodeGenerator getHashCode;
    cmpFunc compare;
} HashMap;

HashMap createHashMap(HashCodeGenerator getHashCode,cmpFunc cmp,int capacity);

int put(HashMap *mapCode, void *key, void *data);

void* get_hashMap(HashMap* map, void* key);