#define _CRT_SECURE_NO_DEPRECATE 0
#define MAX_SIZE (100)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int climbStairs(int n)
{
	/*int y;					//��ʽ�������ڴ�̫�ࣩ
	double a = pow(5, 0.5);
	double b = pow(((1 + a) / 2), (n+1)) - pow(((1 - a) / 2), (n+1));
	y = (1 / a)*b;
	return y;*/

	//if (n <= 2)				//�ݹ鷨����ʱ�� 
	//	return n;
	//else 
	//	return climbStairs(n - 1) + climbStairs(n - 2);

/*
		int i;					//��̬�滮(û��ѭ���ã�
		int a[100];
		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		for (i = 3; i <= n; i++)
		{
			a[i] = a[i - 1] + a[i - 2];
		}
		return a[n];*/

	//int i = 0, j = 1, y;		//ѭ������ʱ��Ϳռ临�Ӷȸߣ�
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
	printf("����¥�ݵĲ�����\n");
	scanf("%d", &n);
	y=climbStairs(n);
	printf("%d", y);
	return 0;
}