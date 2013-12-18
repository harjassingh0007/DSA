#include "matchParanthesis.h"
#include "../Stack/stack.c"

int doesParanthesisMatch(char *text){
	 int length = strlen(text);
	 int i;
	 Stack *paranthesis = createStack(length, 1);
	 for(i = 0; i < length; i++){
	 	switch(text[i]){
	 		case '{':
	 		case '(':
	 		case '[':
	 		case '<':
	 			push(paranthesis, &text[i]);
	 			break;
	 		case ')' :
                if(!(*(char*)top(paranthesis)) == '(')
                    return 1;
                pop(paranthesis);
                break;
        case ']' :
                if(!(*(char*)top(paranthesis)) == '[')
                    return 1;
                pop(paranthesis);
                break;
        case '}' :
                if(!(*(char*)top(paranthesis)) == '{')
                    return 1;
                pop(paranthesis);
                break;
        case '>' :
        	if(!(*(char*)top(paranthesis)) == '>')
                    return 1;
                pop(paranthesis);
                break;
	 	}
	 }
	return 0;
}