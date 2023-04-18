// Example 1 in Structure Assignment 


#include "stdio.h"
#include "string.h"


typedef struct Sstudent
{
	char name[50];
	int roll;
	float mark;
}Sstudent;

int main(int argc, char** argv){

	printf("Enter information of students:\n");
	Sstudent std;
	printf("Enter name:");
	fflush(stdout);
	gets(std.name);
	printf("Enter roll:");
	fflush(stdout);
	scanf("%d", &std.roll);
	printf("Enter marks:");
	fflush(stdout);
	scanf("%f",&std.mark);
	printf("\nDisplaying information\nName: %s\nRoll: %d\nMarks: %0.2f", std.name, std.roll, std.mark);
	return 0;
}


// Example 2 


typedef struct Sdistance
{
	int feet;
	float inch;
}Sdistance;

int main(int argc, char** argv){

	printf("Enter information of 1st distance:\n");
	Sdistance dis1,dis2;
	printf("Enter feet:");
	fflush(stdout);
	scanf("%d",&dis1.feet);
	printf("Enter inch:");
	fflush(stdout);
	scanf("%f", &dis1.inch);
	printf("\nEnter information of 2nd distance:\n");
	printf("Enter feet:");
	fflush(stdout);
	scanf("%d",&dis2.feet);
	printf("Enter inch:");
	fflush(stdout);
	scanf("%f", &dis2.inch);
	if(dis2.inch + dis1.inch >= 12)
		printf("Sum of distances=%d\'-%0.2f\"",dis1.feet+dis2.feet+1, dis1.inch+dis2.inch-12);
	else
		printf("Sum of distances=%d\'-%0.2f\"",dis1.feet+dis2.feet, dis1.inch+dis2.inch);
	return 0;
}
// Example 3

typedef struct Scomplex
{
	float real,img;
}Scomplex;

Scomplex Complex_Sum(Scomplex num1, Scomplex num2)
{
	Scomplex sum;
	sum.real = num1.real + num2.real;
	sum.img = num1.img + num2. img;
	return sum;
}
int main(int argc, char** argv){

	printf("For 1st complex number:\n");
	Scomplex num1,num2,sum;
	printf("Enter real and imaginary respectively:");
	fflush(stdout);
	scanf("%f %f", &num1.real, &num1.img);
	printf("For 2nd complex number:\n");
	printf("Enter real and imaginary respectively:");
	fflush(stdout);
	scanf("%f %f", &num2.real, &num2.img);
	sum = Complex_Sum(num1, num2);
	printf("Sum=%0.2f + %0.2fi", sum.real, sum.img);
	return 0;
}

// Example 4 

typedef struct Sstudent
{
	char name[10];
	int roll;
	float mark;
}Sstudent;

int main(int argc, char** argv){

	printf("Enter information of students:");
	Sstudent std[10];
	for(int i = 0;  i < 10; i++)
	{
		printf("\nFor roll number:");
		fflush(stdout);
		scanf("%d", &std[i].roll);
		printf("Enter name: ");
		fflush(stdin);fflush(stdout);
		gets(std[i].name);
		printf("Enter marks:");
		fflush(stdout);
		scanf("%f", &std[i].mark);
	}
	printf("\nDisplaying information of students:");
	for(int i = 0;  i < 10; i++)
		{
			printf("\nInformation for roll number %d:\n", std[i].roll);
			printf("Name: %s\n", std[i].name);
			printf("Marks:%0.2f\n", std[i].mark);
		}

	return 0;
}

// Example 5

#define Area (3.14*r*r)

int main(int argc, char** argv){
	int r;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%d", &r);
	printf("Area = %0.2f", Area);


	return 0;
}


// Example 6 Find the output

// size of union = 32
// size of structure = 40


