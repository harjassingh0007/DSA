#include "arrayList.h"
#include "stack.h"

typedef struct treeNode{
	struct treeNode* parentNode;
	void *data;
	ArrayList children;
} TreeNode;

typedef int CompareFunc(void* first,void* second);

typedef struct{
	TreeNode* root;
	CompareFunc* compare;
} Tree;

Tree* createTree(CompareFunc* compare);
int insertTreeNode(Tree* tree,void* data,void* parentData);
Iterator getChildren(Tree* tree, void* parentData);

void disposeTree(Tree* tree);