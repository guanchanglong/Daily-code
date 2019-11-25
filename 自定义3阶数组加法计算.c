#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a[3][3];
	int b[3][3];
	int c[3][3];
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			printf("%2d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}