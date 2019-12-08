#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
int main()
{
	int a, b, c;
	for (a = 1; a < 60; a++)
	{
		for (b = 1; b < 60 - a; b++)
		{
			c = 60 - a - b;
			if (100 == 5 * c + 2 * b + a && 60 == a + b + c)
			{
				printf("%d %d %d\n", a, b, c);
			}
		}
	}
	return 0;
}
