#include "stdio.h"


void Prime(int a, int b)
{
	printf("prime numbers between %d and %d are: ", a, b);
	int prime = 1;
	for(int i = a; i <= b; i++)
	{
		prime = 1;
		for(int j = 2; j <= 10; j++)
		{
			if(i % j == 0)
			{
				prime = 0;
				break;
			}
		}
		if(prime == 1)
			printf("%d ", i);
	}
}