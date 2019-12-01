#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//float *search(float(*p)[4], int n)//函数指针跟指针函数的写法就差了一个括号，很容易写错...
//{
//	float *pt;
//	pt = *(p + n);
//	return pt;//返回的是地址
//}
//int main()
//{
//	float score[][4] = { { 60, 70, 80, 90 },{ 56, 89, 67, 88 },{34, 78, 90, 66} };
//	int i, j;
//	float *search(float(*p)[4], int n);
//	float *q;
//	scanf("%d", &j);
//	q = search(score, j);//注意：在调用指针函数时，需要一个同类型的指针来接收其函数的返回值。
//	for (i = 0; i < 4; i++)
//	{
//		printf("%.5lf\t", *(q + i));
//	}
//	printf("\n");
//	return 0;
//}

//float *search(float(*p)[4])
//{
//	int i=0;
//	float *pt;
//	pt = NULL;
//	for (; i < 4; i++)
//	{
//		if (*(*p + i) < 60)
//			pt = *p;
//	}
//	return pt;
//}
//int main()//上面的改进版
//{
//	float score[][4] = { { 60, 70, 80, 90 }, { 56, 89, 67, 88 }, { 34, 78, 90, 66 } };
//	float *search(float(*p)[4]);
//	float *q;
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		q = search(score + i);
//		if (q == *(score + i))
//		{
//			printf("No.%d score:", i);
//			for (j = 0; j < 4; j++)
//			{
//				printf("%.2lf ", *(q + j));
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//int main()//有关指针数据保护的题外话
//{
//	int a[3][3];
//	int i, j;
//	const int (*p)[3];//此处的const使得不可以再通过这个指针修改指向的值
//	p = a;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%d", *(p + i) + j);
//		}
//	}
//	//*(*(p + 0) + 0) = 10;//这种写法是错误的
//	a[0][0] = 10;//这种写法正确，因为数组a并没有用const定义
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}

int *congxiaodaoda(int (*p)[4], int x)//从小到大排序(指针函数)
{
	int i, j,k,l;
	int temp;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < x; j++)
		{
			for (k = 0; k < x; k++)
			{
				for (l = 0; l < x; l++)
				{
					if (*(*(p + i) + j) < *(*(p + k) + l))
					{
						temp = *(*(p + i) + j);
						*(*(p + i) + j) = *(*(p + k) + l);
						*(*(p + k) + l) = temp;
					}
				}
			}
		}
	}
	return p[0];//返回一个指针
}
void congdadaoxiao(int(*p)[4], int x)//从大到小排序（函数指针）
{
	int i, j, k, l;
	int temp;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < x; j++)
		{
			for (k = 0; k < x; k++)
			{
				for (l = 0; l < x; l++)
				{
					if (*(*(p + i) + j) > *(*(p + k) + l))
					{
						temp = *(*(p + i) + j);
						*(*(p + i) + j) = *(*(p + k) + l);
						*(*(p + k) + l) = temp;
					}
				}
			}
		}
	}
}
int main()//二维数组的有序排序
{
	int *congxiaodaoda(int(*p)[4], int x);
	void congdadaoxiao(int(*p)[4], int x);
	int i, j;
	int a[4][4];
	int (*p)[4];
	p = a;
	int c;
	int *q;
	void (*fun)(int(*p)[4], int x);
	fun = congdadaoxiao;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%d", *(p + i) + j);
		}
	}
	printf("请输入1或0(1是从小到大，0是从大到小)：");
	scanf("%d", &c);
	if (c == 0)
	{
		fun(a, 4);
	}
	else if (c == 1)
	{
		q=congxiaodaoda(a, 4);
	}
	else
	{
		printf("输入错误\n");
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\t", *(*(p + i) + j));
		}
		printf("\n");
	}
	return 0;
}
