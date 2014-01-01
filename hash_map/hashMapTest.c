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

void test_remove_data_from_list(){
	Student harjas = {10,"harjas"};
	Student taj = {20,"Taj"};
	int id_1 = 10;
	int id_2 = 20;
	HashMap map = createHashMap(getHashCode, cmpInts, 10);
	ASSERT(put(&map, &id_1, &harjas.name));
	ASSERT(put(&map, &id_2, &taj.name));
	ASSERT(0 == remove_hashMap(&map, &id_2));
}

void test_remove_data_from_list_(){
	Student harjas = {10,"harjas"};
	Student taj = {20,"Taj"};
	Student tanbir = {30,"Tanbir"};
	int id_1 = 10;
	int id_2 = 20;
	int id_3 = 30;
	HashMap map = createHashMap(getHashCode, cmpInts, 10);
	ASSERT(put(&map, &id_1, &harjas.name));
	ASSERT(put(&map, &id_2, &taj.name));
	ASSERT(put(&map, &id_3, &tanbir.name));
	ASSERT(1 == remove_hashMap(&map, &id_3));
	ASSERT(1 == remove_hashMap(&map, &id_2));	
}


void test_remove_data_from_list_when_not_found(){
	Student harjas = {10,"harjas"};
	int id_1 = 10;
	int id_2 = 20;
	HashMap map = createHashMap(getHashCode, cmpInts, 10);
	ASSERT(put(&map, &id_1, &harjas.name));
	ASSERT(0 == remove_hashMap(&map, &id_2));
}

int hashFun(void *key){
        return *(int*)key;
};
int areKeyEqual(void* key1 , void* key2 ){
        return *(int*)key1 - *(int*)key2;
}
void get_keys_from_list(){
    HashMap map = createHashMap(hashFun, areKeyEqual,4);
    Iterator it;
    Student harjas = {10,"harjas"};
	Student taj = {20,"Taj"};
	Student tanbir = {30,"Tanbir"};
	ASSERT(put(&map, &harjas.id, &harjas.name));
    ASSERT(put(&map, &taj.id, &taj.name));
    ASSERT(put(&map, &tanbir.id, &tanbir.name));
    it = HashMap_keys(&map);
    ASSERT(10 == *(int*)it.next(&it));
    ASSERT(20 == *(int*)it.next(&it));
    ASSERT(30 == *(int*)it.next(&it));
}


