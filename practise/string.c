#include <memory.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	typedef char string[10];
	string a = "asd";
	string b = "asd";
	printf("%d\n",strncmp(a, b, 10));
	return 0;
}