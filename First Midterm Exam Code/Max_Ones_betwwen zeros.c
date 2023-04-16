#include "stdio.h" 
#include "string.h"

int MaxOnes(int num)
{
	int max = 0, ones = 0;
	while(num > 0)
	{
		if(num % 2 == 1)
			ones++;
		else
			ones = 0;
		num /= 2;
		if(max < ones)
			max = ones;
	}
	return max;

}

int main(int argc, char** argv){

	printf("%d",MaxOnes(110));
	return 0;
}
