#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_create_double_linkedList");
	setup();
		test_create_double_linkedList();
	tearDown();
	testEnded();
	testStarted("test_insert_node__in_linked_list_at_starting");
	setup();
		test_insert_node__in_linked_list_at_starting();
	tearDown();
	testEnded();
	testStarted("test_insert_node_in_linked_list_at_end");
	setup();
		test_insert_node_in_linked_list_at_end();
	tearDown();
	testEnded();
	testStarted("test_insert_node_in_linked_list_at_end_having_many_nodes");
	setup();
		test_insert_node_in_linked_list_at_end_having_many_nodes();
	tearDown();
	testEnded();
	testStarted("test_insert_node_in_linked_list_in_middle");
	setup();
		test_insert_node_in_linked_list_in_middle();
	tearDown();
	testEnded();
	testStarted("test_delete_node_from_starting_in_linkedList");
	setup();
		test_delete_node_from_starting_in_linkedList();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
