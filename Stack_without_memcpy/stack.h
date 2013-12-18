typedef struct 
{
	void **base;
	int total_elements;
	int each_size;
	int top;
}Stack;

void* create(int size, int length);
int push();