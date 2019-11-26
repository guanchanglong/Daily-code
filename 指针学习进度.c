#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//#define NUM 10
//void sort(int x[], int n)
//{
//	int i, j;
//	int *p = x;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			if (*(p+i) <= *(p+j))
//			{
//				int temp = *(p+i);
//				*(p+i) = *(p+j);
//				*(p+j) = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int a[NUM];
//	int i;
//	int *p = a;
//	for (i = 0; i < NUM; i++);
//	{
//		scanf("%d", a[i]);//有错误（未解决）
//	}
//	p = a;
//	sort(p, NUM);
//	for (i = 0,p=a; i < NUM; i++)
//	{
//		printf("%d", *(p++));
//	}
//	system("pause");
//	return 0;
//}

//二维数组的指针应用
//int main()
//{
//	int a[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
//	printf("%d\n", a[1][1]);
//	printf("%d\n",*(*(a+1)+1) );//a+1为行指针，*（a+1）为列指针
//	printf("%d\n", *(*&a[1]+1));//&a[1]是行指针，*&a[1]是列指针，*重新将&a[1]转化为列指针，相当于*和&相抵消
//	printf("%p\n", a);//二维数组名
//	printf("%p\n", a[0]);//二维数组第0行第0列的地址
//	printf("%p\n", &a[0]);//二维数组第0行的行地址
//	printf("%p\n", *&a[0]);//二维数组第0行第0列的地址(虽然这几个打印出来的地址都相同，但他们代表的含义是不一样的)
//	printf("%p\n", a+1);//二维数组第1行第行地址
//	printf("%p\n", *(a+1));//二维数组第1行第0列的地址
//	printf("%p\n", &*(a+1));//二维数组第1行第行地址
//	printf("%p\n", a[1]);//二维数组第1行第0列的地址
//	printf("%p\n", &a[1]); //二维数组第1行第行地址
//	printf("%p\n", *&a[1]);//二维数组第1行第0列的地址
//	return 0;
//}

//int main()(未解决)
//{
//	int a[3][4];
//	int i, j;
//	int **p;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", *(p + i) + j);
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//	}
//}

//int main()
//{
//	int a[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int *p;
//	for (p = *(a+0); p < a[0] + 12; p++)//此处p=a[0]或p=*(a+0)都可以
//	{
//		printf("%d ", *p);
//	}
//	return 0;
//}

int  main()//输出已知二维数组任一一行任一一列元素的值
{
	int a[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	int(*p)[4];
	p = a;
	int i = 0, j = 0;
	printf("请依次输入行标、列标");
	scanf("%d %d", &i, &j);
	if (i < 3 && j < 4)
	{
		printf("a[%d][%d]=%d\n", i,j,*(*(p+i)+j) );//*(p+i)[j]的写法是错误的
	}
	else
	{
		printf("输入错误\n");
	}
	return 0;
}
