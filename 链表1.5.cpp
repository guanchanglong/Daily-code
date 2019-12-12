#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	char name[10];
	char sex[10];
	struct student *next;
}stu;
stu *creat(void)
{
	stu *head, *p;
	head = NULL;
	p = (stu*)malloc(sizeof(stu));
	scanf("%d%s%s", &p->num, &p->name, &p->sex);
	while (p->num != 0)
	{
		p->next = head;
		head = p;
		p = (stu*)malloc(sizeof(stu));
		scanf("%d%s%s", &p->num, &p->name, &p->sex);
	}
	return head;
}
stu *del(stu *p)//此函数还有错误，未修正
{
	int a;
	printf("请输入需要修改的学号：");
	scanf("%d", &a);
	stu*p1, *p2;
	if (p == NULL)
	{
		printf("空链表");
		return p;
	}
	p1 = p;
	p2 = NULL;
	while (a != p->num&&p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (a == p1->num)
	{
		if (p1->next == p)
		{
			p = p1->next;
		}
		else
			p2->next = p1->next;
	}
	else
		printf("无该学号的学生");
	return p;
}
int main()
{
	stu *pt;
	stu *pt1=NULL;
	stu *pt2 = NULL;
	pt=pt1= creat();
	int a;
	while (pt != NULL)//倒序输出，因为自己作死弄了个头插
	{
		printf("%d %s %s\n", pt->num, pt->name, pt->sex);
		pt = pt->next;
	}
	printf("是否进行修改？1/0\n");
	scanf("%d", &a);
	if (a ==1)
	{
		pt2=del(pt1);
		while (pt2 != NULL)
		{
			printf("%d %s %s\n", pt2->num, pt2->name, pt2->sex);
			pt2 = pt2->next;
		}
	}
	else
	{
		while (pt1 != NULL)
		{
			printf("%d %s %s\n", pt1->num, pt1->name, pt1->sex);
			pt1 = pt2->next;
		}
	}
	return 0;
}