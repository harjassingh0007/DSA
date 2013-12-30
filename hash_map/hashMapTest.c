#include "testUtils.h"
#include "hashMap.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct
{
	int id;
	char* name;
}Student;

int getHashCode(void *key){
	return *(int*)key;
}

int cmpInts(void* first, void* second){
	return *(int*)first == *(int*)second;
}

void test_add_record_when_mapCode_is_Null_in_list(){
    Student harjas  = {10,"harjas"};
    int id = 10;
    ASSERT(0 == put(NULL, &id, &harjas.name));
};

void test_add_record_in_the_list(){
	Student harjas = {10,"harjas"};
	int id = 10;
	HashMap map = createHashMap(getHashCode, cmpInts, 10);
	put(&map, &id, &harjas.name);
}

void test_add_2_records_in_the_list(){
	Student harjas = {10,"harjas"};
	Student taj = {20,"Taj"};
	int id_1 = 10;
	int id_2 = 20;
	HashMap map = createHashMap(getHashCode, cmpInts, 10);
	ASSERT(put(&map, &id_1, &harjas.name));
	ASSERT(put(&map, &id_2, &taj.name));
}


void test_add_3_records_in_the_list(){
	Student harjas = {10,"harjas"};
	Student taj = {20,"Taj"};
	Student tanbir = {30,"tanbir"};
	int id_1 = 10;
	int id_2 = 20;
	int id_3 = 30;
	HashMap map = createHashMap(getHashCode, cmpInts, 10);
	ASSERT(put(&map, &id_1, &harjas.name));
	ASSERT(put(&map, &id_2, &taj.name));
	ASSERT(put(&map, &id_3, &tanbir.name));

}

void test_get_data_from_list(){
	Student harjas = {10,"harjas"};
	Student taj = {20,"Taj"};
	int id_1 = 10;
	int id_2 = 20;
	HashMap map = createHashMap(getHashCode, cmpInts, 10);
	ASSERT(put(&map, &id_1, &harjas.name));
	ASSERT(put(&map, &id_2, &taj.name));
	ASSERT(0 == get_hashMap(&map, &harjas.id));
}
