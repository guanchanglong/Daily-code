#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	unsigned int year;
	scanf("%d", &year);
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("该年份为闰年\n");
		}
		else
		{
			printf("该年份不是闰年\n");
		}
	return 0;
}