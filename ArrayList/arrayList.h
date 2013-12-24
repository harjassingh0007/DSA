typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int (*compare)(void* first,void *second);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

int remove(ArrayList *list, int index);

int search(ArrayList *list, void *element,compare cmpFunc);

void dispose(ArrayList *list);