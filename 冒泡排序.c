#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void bubblesort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				int b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
}
int main()
{
	int i = 0;
	int a[10];
	int sz = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &a[i]);
	}
	bubblesort(a, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}