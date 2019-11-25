#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void b(int x[], int n)
{
	int t,i;
	int j = 0;
	int m = (n - 1) / 2;
	for (i = 0; i <= m; i++)
	{
		j = n - 1 - i;
		t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
}
int main()
{
	int a[10];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	b(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
