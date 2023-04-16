#include "stdio.h"
#include "string.h"

void Reverse_Array(int arr[], int size)
{
	for(int i = size - 1; i>=0; i--)
	{
		printf("%d ", arr[i]);
	}
}

int main(int argc, char** argv){
	int a[7]={1,2,3,4,5,6,7};
	Reverse_Array(a,7);
	return 0;
}
