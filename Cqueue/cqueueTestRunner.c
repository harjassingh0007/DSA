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

	testStarted("test_create_a_queue_of_int_type");
	setup();
		test_create_a_queue_of_int_type();
	tearDown();
	testEnded();
	testStarted("test_create_a_queue_of_char_type");
	setup();
		test_create_a_queue_of_char_type();
	tearDown();
	testEnded();
	testStarted("test_create_a_queue_of_string_type");
	setup();
		test_create_a_queue_of_string_type();
	tearDown();
	testEnded();
	testStarted("test_enqueue_an_item_into_int_type_queue");
	setup();
		test_enqueue_an_item_into_int_type_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_an_item_into_char_type_queue");
	setup();
		test_enqueue_an_item_into_char_type_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_an_item_into_string_type_queue");
	setup();
		test_enqueue_an_item_into_string_type_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_an_item_into_int_type_queue_when_it_is_full");
	setup();
		test_enqueue_an_item_into_int_type_queue_when_it_is_full();
	tearDown();
	testEnded();
	testStarted("test_enqueue_an_item_into_char_type_queue_when_it_is_full");
	setup();
		test_enqueue_an_item_into_char_type_queue_when_it_is_full();
	tearDown();
	testEnded();
	testStarted("test_enqueue_an_item_into_string_type_queue_when_it_is_full");
	setup();
		test_enqueue_an_item_into_string_type_queue_when_it_is_full();
	tearDown();
	testEnded();
	testStarted("test_dequeue_an_item_from_int_type_queue");
	setup();
		test_dequeue_an_item_from_int_type_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_an_item_from_char_type_queue");
	setup();
		test_dequeue_an_item_from_char_type_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_an_item_from_string_type_queue");
	setup();
		test_dequeue_an_item_from_string_type_queue();
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
