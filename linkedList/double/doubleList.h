typedef struct node {
        void* data;
        struct node* next;
        struct node* previous;
} Node;

typedef struct {
        int length;
        Node* head;
} LinkedList;

typedef char String[256];

LinkedList* createLinkedList();
int insertNode(LinkedList* list,void* element,int index);
void* removeNode(LinkedList* list,int index);
void dispose(LinkedList *list);