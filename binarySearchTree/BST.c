#include "BST.h"
#include <stdlib.h>

TreeNode* createTree(compare cmp){
	TreeNode* tree = calloc(1, sizeof(TreeNode));
	tree->cmp = cmp;
	tree->data = NULL;
	return tree;
}