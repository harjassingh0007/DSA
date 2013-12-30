#include "tree.h"
#include <stdlib.h>

Tree* createTree(CompareFunc* compare){
	Tree* tree = calloc(1,sizeof(Tree));
	tree->root = NULL;
	tree->compare = compare;
	return tree;
}

int insertTreeNode(Tree *tree, void *data, void *parentData){
	if(parentData == NULL){
		tree->root->data = data;
		// tree->root->parentNode = NULL;
		// tree->root->children = create(0);
		return 1;
	}
	return 0;
}