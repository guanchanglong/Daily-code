#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)
//struct
//{
//	int num;
//	char name[10];
//	char sex;
//	char job;
//	union//������
//	{
//		int clas;
//		char position[10];
//	}a;
//}person[2];
//int main()
//{
//	int i;
//	for (i = 0; i < 2; i++)
//	{
//		printf("������ѧ�š��������Ա�ְҵ��\n");
//		scanf("%d%s%c%c", &person[i].num, &person[i].name, &person[i].sex, &person[i].job);//�д���
//		if (person[i].job == 's')
//		{
//			scanf("%d", &person[i].a.clas);
//		}
//		else if (person[i].job == 't')
//		{
//			scanf("%s", &person[i].a.position);
//		}
//		else
//		{
//			printf("\n�������\n");
//		}
//	}
//	printf("\n");
//	for (i = 0; i < 2; i++)
//	{
//		if (person[i].job == 's')
//		{
//			printf("%-6d%-10s%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].a.clas);
//		}
//		else
//		{
//			printf("%-6d%-10s%-4c%-4c%-10d\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].a.position);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	enum color{red,yellow,blue,white,black};
//	enum color i, j, k, l;
//	int n, loop;
//	n = 0;
//	for (i = red; i <= black; i++)
//	{
//		for (j = red; j <= black; j++)
//		{
//			if (i != j)
//			{
//				for (k = red; k <= black; k++)
//				{
//					if (k != i && k!=j)
//					{
//						n = n + 1;
//						printf("%-4d", n);
//						for (loop = 1; loop <= 3; loop++)
//						{
//							switch (loop)
//							{
//								case 1:l = i; break;
//								case 2:l = j; break;
//								case 3:l = k; break;
//								default:break;
//							}
//							switch (i)
//							{
//							case red:printf("%-10s", "red"); break;
//							case yellow:printf("%-10s", "yellow"); break;
//							case blue:printf("%-10s", "blue"); break;
//							case white:printf("%-10s", "white"); break;
//							case black:printf("%-10s", "black"); break;
//							default:break;
//							}
//						}
//						printf("\n");
//					}
//				}
//			}
//		}
//	}
//	printf("\ntotal:%5d\n", n);
//	return 0;
//}

//struct student
//{
//	int num;
//	char name[10];
//	char sex[10];
//	struct student *next;
//}stu[10];
//int main()
//{
//	struct student *head,a, b, c, d,*p;
//	a.num = 1;
//	b.num = 2;
//	c.num = 3;
//	d.num = 4;
//	head = &a;
//	a.next = &b;
//	b.next = &c;
//	c.next = &d;
//	d.next = NULL;
//	p = head;
//	while (p != NULL)
//	{
//		printf("%d\n", (*p).num);
//		p = (*p).next;
//	}
//	return 0;
//}

struct student
{
	int num;
	char name[10];
	char sex[10];
	float score;
	struct student *next;
};
int n;
struct student *creat(void)//��������
{
	struct student *head;//����һ��ͷ��ַ
	head = NULL;//�Ƚ�����ʼ������Ȼ�������ᱨ��
	struct student *p1, *p2;
	n = 0;
	p1 = p2 = (struct student *)malloc(LEN);//����һ����̬�洢�ռ�
	scanf("%d%s%s%f", &(*p1).num, &(*p1).name, &(*p1).sex, &(*p1).score);//���ô洢�ռ���������
	head = p1;//��p1�ĵ�ַ����ͷ��ַ
	while ((*p1).num != 0)//ѭ������p1���ŵ�����
	{
		n = n + 1;
		//if (n == 1)
		//{
			//head = p1;
		//}
		//else
		//{
		(*p2).next = p1;//
		//}
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf("%d%s%s%f", &(*p1).num, &(*p1).name, &(*p1).sex, &(*p1).score);
	}
	(*p2).next = NULL;
	return head;
}
void print(struct student *head)
{
	struct student *p;
	printf("\nNow,These %d record are:\n", n);
	p = head;
	if (head != NULL)
	{
		while (p != NULL)
		{
			printf("%d %s %s %.2f\n", (*p).num, (*p).name, (*p).sex, (*p).score);
			p = (*p).next;
		}
	}
}
struct student *del(struct student*head, int num)//ɾ�������е�ĳһ���
{
	struct student *p1, *p2;
	p2 = NULL;
	if (head == NULL)
	{
		printf("\nlist null!\n");
		return head;
	}
	p1 = head;
	while (num != (*p1).num && (*p1).next != NULL)
	{
		p2 = p1;
		p1 = (*p1).next;
	}
	if (num == (*p1).num)
	{
		if (p1 == head)
		{
			head = (*p1).next;
		}
		else
			(*p2).next = (*p1).next;
		printf("delete:%d\n", num);
		n = n - 1;
	}
	else
	{
		printf("%d not been found!\n", num);
	}
	return head;
}
int main()
{
	int m;
	struct student *pt;
	pt = creat();//��������һ�����ĵ�ַ����
	scanf("%d", &m);
	pt=del(pt, m);
	print(pt);
	return 0;
}

