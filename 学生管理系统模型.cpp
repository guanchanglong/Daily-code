#define _CRT_SECURE_NO_DEPRECATE 0
//创建链表
//打印里面的内容
//在面插入新的内容
//删除里面的内容
//搜索想要打印的节点
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	char name[10];
	char sex[10];
	int score;
	struct student *next;
}stu;
stu *creat(void)
{
	stu *head, *p,*q;
	p = q = (stu*)malloc(sizeof(stu));
	scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
	head = p;
	while (p->num != 0)
	{
		p = (stu*)malloc(sizeof(stu));
		scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
		q->next = p;
		q = p;
	}
	q ->next= NULL;
	return head;
}
stu *print(stu*head)
{
	int a;
	printf("是否输出学生数据(1/0)：");
	scanf("%d", &a);
	if (a == 1)
	{
		while (head->num!=0)
		{
			printf("%d %s %s %d\n", head->num, head->name, head->sex, head->score);
			head = head->next;
		}
	}
	else if (a == 0)
	{
		printf("是否进行其他操作");
	}
	else
	{
		printf("输入错误");
	}
	return head;
}
stu*del(stu*head,int num)
{
	stu *p1, *p2;
	p2 = NULL;
	if (head == NULL)
	{
		printf("空链表");
		return head;
	}
	p1 = head;
	while (p1->num != num&&p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->num == num)
	{
		if (p1 == head)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
	}
	else
	{
		printf("无该学号的学生");
	}
	return head;
}
//stu*sort1(stu*head)//从大到小排序
//{
//	stu *p, *q;
//	p = head;
//	while (head != NULL)
//	{
//		q = p;
//		p = p->next;
//		if (q == head)
//		{
//			if (q->score >= p->score)
//			{
//				;
//			}
//			else
//			{
//				head = p;
//				q->next = p->next;
//				p->next = q;
//			}
//		}
//		else
//		{
//			if (q->score > p->score)
//			{
//
//			}
//			else
//			{
//				q->next = p;
//				q->next = p->next;
//				p->next = q;
//			}
//		}
//	}
//	return head;
//}
stu*insert(stu*head, stu*t)
{
	stu*p0, *p1, *p2;
	p2 = NULL;
	p1 = head;
	p0 = t;
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while (p0->score > p1->score&&p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->score < p1->score)
		{
			if (head == p1)
			{
				head = p0;
			}
			else
			{
				p2->next = p0;
				p0->next = p1;
			}
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	return head;
}
int main()
{
	int a;
	stu *p;
	p = (stu*)malloc(sizeof(stu));
	stu*pt;
	pt = creat();
	print(pt);
	printf("请输入需要删除的学生学号：\n");
	scanf("%d", &a);
	pt = del(pt, a);
	print(pt);
	/*pt=sort1(pt);*/
	//print(pt);
	printf("请输入需要插入的学生数据:\n");
	scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
	pt=insert(pt, p);//还有问题未解决
	print(pt);
	return 0;
}