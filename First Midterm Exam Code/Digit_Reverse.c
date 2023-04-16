#include "stdio.h"


void Digit_Reverse(int num)
{
	char arr[100];  // buffer
	itoa(num, arr, 10); // Function to convert the number to string
	int len = strlen(arr)-1;
	for(int i=len; i>=0; i--)
		printf("%c", arr[i]);
}

int main(int argc, char** argv){

	Digit_Reverse(123456);
	return 0;
}
