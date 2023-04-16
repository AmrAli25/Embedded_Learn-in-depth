#include "stdio.h"


int UniqeNum(int nums[],int size)
{
	int Unum;

	for(int i = 0; i < size; i=i+2)
	{
		Unum = nums[i];
		if(Unum != nums[i+1] && i+1 < size )
			Unum = nums[i+1];
		else
			Unum = nums[i-1];
	}
	return Unum;

}

int main(int argc, char** argv){
	int a[14] = {4,2,4,2,5,5,10,5,5,4,3,5,10,11};
	printf("%d", UniqeNum(a,14));
	return 0;
}