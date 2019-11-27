#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define NUM 10
sort(int x[], int n)
{
	int i, j, t;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (x[i]>x[j])
			{
				t = x[i];
				x[i] = x[j];
				x[j] = t;
			}
		}
	}
}
int main()
{
	int i, a[NUM];
	int*p = a;
	for (i = 0; i < NUM; i++)
	{
		scanf("%d", p++);
	}
	p = a;
	sort(a, NUM);
	for (i = 0,p=a; i < NUM; i++)
	{
		printf("%d ", *p++);
	}
	return 0;
}