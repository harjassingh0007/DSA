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

	testStarted("test_push_element_of_int_type_into_a_stack");
	setup();
		test_push_element_of_int_type_into_a_stack();
	tearDown();
	testEnded();
	testStarted("test_push_element_of_char_type_into_a_stack");
	setup();
		test_push_element_of_char_type_into_a_stack();
	tearDown();
	testEnded();
	testStarted("test_push_element_of_double_type_into_a_stack");
	setup();
		test_push_element_of_double_type_into_a_stack();
	tearDown();
	testEnded();
	testStarted("test_isFull_will_tell_that_stack_is_full");
	setup();
		test_isFull_will_tell_that_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_isFull_will_tell_that_stack_is_not_full");
	setup();
		test_isFull_will_tell_that_stack_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_pop_an_element_from_int_type_stack");
	setup();
		test_pop_an_element_from_int_type_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_an_element_from_char_type_stack");
	setup();
		test_pop_an_element_from_char_type_stack();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_will_tell_that_stack_is_Empty");
	setup();
		test_isEmpty_will_tell_that_stack_is_Empty();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_will_tell_that_stack_is_not_Empty");
	setup();
		test_isEmpty_will_tell_that_stack_is_not_Empty();
	tearDown();
	testEnded();
	testStarted("test_top_function_will_give_element_at_top_of_stack");
	setup();
		test_top_function_will_give_element_at_top_of_stack();
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
