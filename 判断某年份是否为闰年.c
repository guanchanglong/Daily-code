#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	unsigned int year;
	scanf("%d", &year);
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("�����Ϊ����\n");
		}
		else
		{
			printf("����ݲ�������\n");
		}
	return 0;
}