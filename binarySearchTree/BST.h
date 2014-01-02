typedef int (*compare)(void* first, void* second);

typedef struct node
{
	void *data;
	struct node *rightNode;
	struct node *leftNode;
	compare cmp;

} TreeNode;

TreeNode* createTree(compare cmp);
int insertNode(TreeNode* tree, void* parentData, void* childData);