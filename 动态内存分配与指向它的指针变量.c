#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//	int a=3;
//	int *p1 = &a;
//	char*p2;
//	void *p3;//定义一个无类型指针
//	p3 = (void*)p1;
//	p2 = (char*)p3;
//	printf("%d\n", *p1);
//	return 0;
//}

void check(int *p)
{
	int i;
	printf("They are fail:");
	for (i = 0; i < 5; i++)
	{
		if (p[i] < 60)
			printf("%d", p[i]);
		printf("\n");
	}
}
int main()
{
	void check(int *);
	int *p1, i;
	p1 = malloc(5 * sizeof(int));//此处开辟了5*4个字节的动态内存空间。sizeof测定了整型在本系统中的字节数
	//该编译器不用进行强制类型转换，编译器自动帮你转换好了
	//p1=(int *)malloc(5*sizeof(int));//也可以进行强制类型转换（malloc是void*型，把它转换为int*型）
	for (i = 0; i < 5; i++)
	{
		scanf("%d", p1 + i);
	}
	check(p1);
	return 0;
}