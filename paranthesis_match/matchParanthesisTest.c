#include "testUtils.h"
#include "matchParanthesis.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_parentheses_having_no_character(){
    char text[256];
    int result;
    strcpy(text,"");
    result = doesParanthesisMatch(text);    
    ASSERT(result == 0);
}


void test_parentheses_having_no_paranthesis(){
    char text[256];
    int result;
    strcpy(text,"asdfgh");
    result = doesParanthesisMatch(text);    
    ASSERT(result == 0);
}

void test_parentheses_having_circle_paranthesis(){
    char text[256];
    int result;
    strcpy(text,"a()gh");
    result = doesParanthesisMatch(text);    
    ASSERT(result == 1);
}

void test_parentheses_having_curly_paranthesis(){
    char text[256];
    int result;
    strcpy(text,"a{f}gh");
    result = doesParanthesisMatch(text);    
    ASSERT(result == 1);
}
