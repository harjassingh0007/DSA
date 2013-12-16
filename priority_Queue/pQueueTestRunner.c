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

	testStarted("test_create_a_job_of_int_type");
	setup();
		test_create_a_job_of_int_type();
	tearDown();
	testEnded();
	testStarted("test_create_a_job_of_char_type");
	setup();
		test_create_a_job_of_char_type();
	tearDown();
	testEnded();
	testStarted("test_create_a_job_of_string_type");
	setup();
		test_create_a_job_of_string_type();
	tearDown();
	testEnded();
	testStarted("test_enqueue_a_job_of_int_type");
	setup();
		test_enqueue_a_job_of_int_type();
	tearDown();
	testEnded();
	testStarted("test_enqueue_a_job_of_char_type");
	setup();
		test_enqueue_a_job_of_char_type();
	tearDown();
	testEnded();
	testStarted("test_enqueue_a_job_of_string_type");
	setup();
		test_enqueue_a_job_of_string_type();
	tearDown();
	testEnded();
	testStarted("test_isFull_returns_true");
	setup();
		test_isFull_returns_true();
	tearDown();
	testEnded();
	testStarted("test_isFull_returns_false");
	setup();
		test_isFull_returns_false();
	tearDown();
	testEnded();
	testStarted("test_enqueue_a_job_of_int_type_when_it_will_return_false");
	setup();
		test_enqueue_a_job_of_int_type_when_it_will_return_false();
	tearDown();
	testEnded();
	testStarted("test_enqueue_a_job_of_char_type_when_it_will_return_false");
	setup();
		test_enqueue_a_job_of_char_type_when_it_will_return_false();
	tearDown();
	testEnded();
	testStarted("test_enqueue_a_job_of_string_type_when_it_will_return_false");
	setup();
		test_enqueue_a_job_of_string_type_when_it_will_return_false();
	tearDown();
	testEnded();
	testStarted("test_dequeue_a_job_of_int_type");
	setup();
		test_dequeue_a_job_of_int_type();
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
