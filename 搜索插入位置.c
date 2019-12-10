#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target)
{
	int i = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (*(nums + i) >= target)
		{
			return i;
		}
		else
			continue;
	}
	return i;
}
int main()
{
	int b;
	int a[4] = {1,3,5,6};
	scanf("%d", &b);
	int c=searchInsert(a, 4, b);
	printf("%d", c);
	return 0;
}