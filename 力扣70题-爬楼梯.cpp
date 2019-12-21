#define _CRT_SECURE_NO_DEPRECATE 0
#define MAX_SIZE (100)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int climbStairs(int n)
{
	/*int y;					//公式法（耗内存太多）
	double a = pow(5, 0.5);
	double b = pow(((1 + a) / 2), (n+1)) - pow(((1 - a) / 2), (n+1));
	y = (1 / a)*b;
	return y;*/

	//if (n <= 2)				//递归法（超时） 
	//	return n;
	//else 
	//	return climbStairs(n - 1) + climbStairs(n - 2);

/*
		int i;					//动态规划(没有循环好）
		int a[100];
		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		for (i = 3; i <= n; i++)
		{
			a[i] = a[i - 1] + a[i - 2];
		}
		return a[n];*/

	//int i = 0, j = 1, y;		//循环法（时间和空间复杂度高）
	//while (n--)
	//{
	//	y = i + j;
	//	i = j;
	//	j = y;
	//}
	//return y;
}
int main()
{
	int n,y;
	printf("输入楼梯的层数：\n");
	scanf("%d", &n);
	y=climbStairs(n);
	printf("%d", y);
	return 0;
}