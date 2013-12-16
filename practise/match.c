#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int i,j;
	char a[5] = {'{','(','[','\0'};
	char b[5] = {']',')'};
	for(i=strlen(a);i>=0;i--){
		for(j=0;j<=3;j++){
			printf("%c,,,,%c\n",b[j],a[i]);
			if(a[i] == b[j]){
				printf("%c\n",a[i]);
			}
		}
	}
	return 0;
}