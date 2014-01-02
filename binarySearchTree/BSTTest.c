#include "testUtils.h"
#include "BST.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInts(void* first, void* second){
	return *(int*)first - *(int*)second;
}
void test_insert_data_in_root_node(){
	TreeNode *tree;
	int result;
	tree = createTree(cmpInts);
}
