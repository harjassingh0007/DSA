#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInteger(void* first,void* second){
	return *(int*)first - *(int*)second;
}

void test_insert_data_at_root(){
	Tree * tree = createTree(compareInteger);
	int element = 10;
	ASSERT(insertTreeNode(tree, &element, NULL));
}