#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//float *search(float(*p)[4], int n)//����ָ���ָ�뺯����д���Ͳ���һ�����ţ�������д��...
//{
//	float *pt;
//	pt = *(p + n);
//	return pt;//���ص��ǵ�ַ
//}
//int main()
//{
//	float score[][4] = { { 60, 70, 80, 90 },{ 56, 89, 67, 88 },{34, 78, 90, 66} };
//	int i, j;
//	float *search(float(*p)[4], int n);
//	float *q;
//	scanf("%d", &j);
//	q = search(score, j);//ע�⣺�ڵ���ָ�뺯��ʱ����Ҫһ��ͬ���͵�ָ���������亯���ķ���ֵ��
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
//int main()//����ĸĽ���
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

//int main()//�й�ָ�����ݱ��������⻰
//{
//	int a[3][3];
//	int i, j;
//	const int (*p)[3];//�˴���constʹ�ò�������ͨ�����ָ���޸�ָ���ֵ
//	p = a;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%d", *(p + i) + j);
//		}
//	}
//	//*(*(p + 0) + 0) = 10;//����д���Ǵ����
//	a[0][0] = 10;//����д����ȷ����Ϊ����a��û����const����
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

int *congxiaodaoda(int (*p)[4], int x)//��С��������(ָ�뺯��)
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
	return p[0];//����һ��ָ��
}
void congdadaoxiao(int(*p)[4], int x)//�Ӵ�С���򣨺���ָ�룩
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
int main()//��ά�������������
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
	printf("������1��0(1�Ǵ�С����0�ǴӴ�С)��");
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
		printf("�������\n");
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
