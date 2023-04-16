#include "stdio.h"



int SumOf_Digit(int num)
{
	static int sum = 0, rem = 0;
	rem = num%10;
	sum += rem;
	num = num/10;

	if(num >=1 && num <=9)
		sum += num;
	else
		SumOf_Digit(num);
	return sum;
}