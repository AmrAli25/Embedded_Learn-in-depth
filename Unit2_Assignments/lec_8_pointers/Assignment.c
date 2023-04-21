// this is the solution for pointers assignment //
//
//
//
//
// Examle 1

#include "stdio.h"



int main(int argc, char** argv){

	int x = 8;
	int *px = &x;
	printf("Address of x: 0x%p\nValue of x: %d ", &x, x);
	printf("\n\nNow px is assigned with x address\n");
	printf("Address of pointer px: 0x%p\nValue of pointer px: %d ", &px, *px);
	x=44;
	printf("\n\nthe value of x = 44 now\n");
	printf("Address of pointer px: 0x%p\nValue of pointer px: %d ", &px, *px);
	*px=7;
	printf("\n\nNow px is assigned with value 7\n");
	printf("Address of x: 0x%p\nValue of x: %d ", &x, x);

	return 0;
}


// Example 2

#include "stdio.h"



int main(int argc, char** argv){

	char a[27];
	char* ptr = a;
	printf("The Alphabets are :\n");
	for(int i =0; i<26; i++)
	{
		*ptr=i+'A';
		printf("%c\t", *ptr);
		ptr++;

	}
	return 0;
}

// Example 3
//

#include "stdio.h"
#include "string.h"


int main(int argc, char** argv){

	char a[50], b[50];
	char* ptr = a;
	printf("Enter a string: ");
	fflush(stdout);
	gets(ptr);
	printf("Pointer: print a string in reverse order\n");
	printf("------------------------------------------\n");
	printf("input string is : %s\n",ptr);
	printf("Reverse of the string is : ");
	for(int i =strlen(ptr)-1; i>=0; i-- )
	{
		printf("%c",*(ptr+i));
	}
	return 0;
}

// Example 4
//

#include "stdio.h"
#include "string.h"


int main(int argc, char** argv){

	int a[15], size;
	int* ptr = a;
	printf("Enter a number of elements to store in array max 15 num: ");
	fflush(stdout);
	scanf("%d", &size);
	printf("Enter %d numbers of elements in the array:\n", size);
	for(int i =0; i<size; i++ )
	{
		printf("element - %d:",i+1);
		fflush(stdout);
		scanf("%d", ptr+i);
	}
	printf("the element of array in reverse order are:\n");
	for(int i =size-1; i>=0; i-- )
		printf("element - %d: %d\n", i+1, *(ptr+i));
	return 0;
}


// Example 5
//

#include "stdio.h"

typedef struct Semployee{
	char name[15];
	int id;
}Semployee;


int main(int argc, char** argv){

	Semployee data1= {"Amr",1}, data2={"Ali",2}, data3={"Ahmed",3};
	Semployee *arr[]= {&data1, &data2, &data3};
	Semployee (*(*ptr)[3]) = &arr;
	for(int i = 0; i<3; i++)
	printf("Employee name is : %s\nEmployee ID: %d\n", (*(*ptr+i))->name,(*(*ptr+i))->id);


	return 0;
}

