##This file is the .c file to run on the IDE just put any function you want to try and see the ouput ##



##This is Assignment 2 in Lecture 3

void Ex_1_EvenOrOdd()
{
	int a;
	printf("enter a number you want to check: ");
	fflush(stdout);
	scanf("%d", &a);
	if(a % 2 == 0)
		printf("%d is even", a);
	else
		printf("%d is odd", a);
}

void Ex_2_VowelsOrConst()
{
	char c;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c", &c);
	if(c == 'a' || c == 'o' || c == 'e' || c == 'i')
		printf("%c is a vowel", c);
	else
		printf("%c is a constant", c);
}

void Ex_3_LargestNum()
{
	float a, b, c, max = 0;
	printf("Enter three numbers : ");
	fflush(stdout);
	scanf("%f %f %f", &a, &b, &c);
	if(a > b && a > c)
		max = a;
	else if(b > a && b > c)
		max = b;
	else
		max = c;
	printf("Largest number = %0.2f", max);
}
void Ex_4_PosOrNeg()
{
	 float a;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f", &a);
	if(a > 0)
		printf("%0.2f is positive", a);
	else if(a < 0)
		printf("%0.2f is negative", a);
	else
		printf("You entered Zero");
}

void Ex_5_IsAlpha()
{
	char c;
	printf("enter a character: ");
	fflush(stdout);
	scanf("%c", &c);
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		printf("%c is an alphabet", c);
	else
		printf("%c isn\'t an alphabet", c);
}


void Ex_6_SumOfNaturalNum()
{
	int a, sum = 0;
	x:
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &a);
	if(a <= 0)
	{
		printf("Wrong entry\n");
		goto x;
	}
	int i;
	for(i = 1; i <= a; i++)
	{
		sum += i;
	}
	printf("Sum = %d", sum);
}

void Ex_7_Factorial()
{
	int a, fact = 1;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &a);
	if(a > 0)
	{
		int i;
		for(i = 1; i <= a; i++)
			fact *= i;
		printf("Factorial = %d ", fact);
	}
	else if(a < 0)
		printf("Error!!! Factorial of negative number dosen\'t exist");
	else
		printf("Factorial = 1");
}

void Ex_8_SimpleCalculator()
{
	float a, b;
	char c;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdout);
	scanf("%c", &c);
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f %f", &a, &b);
	switch(c)
	{
	case '+':
		printf("%0.2f + %0.2f = %0.2f", a, b, a+b);
		break;
	case '-':
		printf("%0.2f - %0.2f = %0.2f", a, b, a-b);
		break;
	case '*':
		printf("%0.2f * %0.2f = %0.2f", a, b, a*b);
		break;
	case '/':
		printf("%0.2f / %0.2f = %0.2f", a, b, a/b);
		break;
	default:
		printf("Wrong Operator");
		break;
	}

}

int main(int argc, char** argv)
{
	 Ex_8_SimpleCalculator();

	 return 0;
}

