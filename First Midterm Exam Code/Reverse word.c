#include "stdio.h"
#include "string.h"


void Reverse_Word(char arr[])
{
	char first[100], second[100];
	int len = strlen(arr);
	static int i;
	for(i = 0; i<len; i++)
	{
		if(arr[i] == ' ')
		{
			first[i] = '\0';
			break;
		}
		first[i] = arr[i];
	}
	for(int j = 0; j<len-strlen(first); j++)
	{
		i++;
		second[j] = arr[i];
		if(i == 13)
			second[j+1] = '\0';
	}
	printf("%s %s",second, first);
}

int main(int argc, char** argv){
	char a[]="mohammed gamal";
	Reverse_Word(a);
	return 0;
}
