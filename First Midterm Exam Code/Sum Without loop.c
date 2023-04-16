#include "stdio.h"
#include "string.h"

int Sum()
{
	static int i = 0, sum = 0;
	i++;
	if(i <= 100)
	{
		sum += i;
		Sum();
	}

	return sum;
}

int main(int argc, char** argv){

	printf("%d", Sum());
	return 0;
}
