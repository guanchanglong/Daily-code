#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//#define N 100
//int n;
//struct student
//{
//	int num;
//	char name[20];
//	float score[3];
//	float aver;
//};
//int main()//�ṹ�庯��
//{
//	printf("������ѧ����\n");
//	scanf("%d", &n);
//	void input(struct student s[]);
//	struct student max(struct student s[]);
//	void show(struct student res);
//	struct student s[N], *p = s;
//	input(p);
//	show(max(p));
//}
//void input(struct student s[])
//{
//	int i;
//	printf("������ѧ����ѧ��,����,���ųɼ���(�Դ˸�ʽ:ѧ�� ���� �ɼ�һ �ɼ��� �ɼ���)\n");
//	for (i = 0; i<n; i++)
//	{
//		scanf("%d %s %f %f %f", &s[i].num, &s[i].name, &s[i].score[0], &s[i].score[1], &s[i].score[2]);
//		s[i].aver = (s[i].score[1] + s[i].score[2] + s[i].score[0]) / 3.0;
//	}
//}
//struct student max(struct student s[])
//{
//	int i, m = 0;
//	for (i = 0; i<n; i++)
//	if (s[i].aver>s[m].aver)
//		m = i;
//	return s[m];
//}
//void show(struct student res)
//{
//	printf("�ɼ���ߵ�ͬѧ�ǣ�\n");
//	printf("ѧ��Ϊ:%d\n����Ϊ:%s\n �ɼ�Ϊ:\n %.2lf \n %.2lf \n %.2lf\n ƽ���ɼ�Ϊ��:%.2lf\n", res.num, res.name, res.score[0], res.score[1], res.score[2], res.aver);
//}
//
//int main()//������
//{
//	int a[3][2];
//	int i, j;
//	int b[2][3];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			b[j][i] = a[i][j];
//			printf("%5d", b[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

void sort(int a[10], int x)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = i + 1; j < x; j++)
		{
			int temp = 0;
			if (a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()//ѡ������
{
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, 10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}