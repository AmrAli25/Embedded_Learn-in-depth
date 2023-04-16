#include "stdio.h"


int NumOfOnes(int num)
{
	int ones = 0;
	while(num > 0)
	{
		if(num % 2 == 1)
			ones++;
		num /= 2;
	}
	return ones;

}

int main(int argc, char** argv){

	printf("%d", NumOfOnes(15));
	return 0;
}