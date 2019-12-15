#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	int num;
	char name[10];
	char sex[5];
	int score;
	struct student *next;
}stu;
stu *sort(stu*head)//从小到大排序(又一次失败）
{
	stu *p, *q,*q1,*n;
	q = head;
	q1 = NULL;
	if (q == NULL)
	{
		printf("空链表");
	}
	p = head;
	while (p->next != NULL)
	{
		q1 = q;
		q = q->next;
		p = q->next;
		if (q->score >= p->score)
		{
			if (q1 == head)//在开头
			{
				n = (stu*)malloc(sizeof(stu));
				n->num = q1->num;
				strcpy(n->name, q1->name);
				strcpy(n->sex, q1->sex);
				n->score = q1->score;
				q1->num = q->num;//
				strcpy(q1->name, q->name);
				strcpy(q1->sex, q->sex);
				q1->score = q->score;
				q->num = n->num;//
				strcpy(q->name, n->name);
				strcpy(q->sex, n->sex);
				q->score = n->score;
			}
			else if (p->next == NULL)//在结尾
			{
				q->next = NULL;
				q1->next = p;
				p->next = q;
			}
			else
			{
				q->next = p->next;
				p->next = q;
				q1->next = p;
			}
		}
	}
	return head;
}


//stu *creat(void)
//{
//	stu*head, *p;
//	p = (stu*)malloc(sizeof(stu));
//	scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
//	head = NULL;
//	while (p->num != 0)
//	{
//		p->next = head;
//		head = p;
//		p = (stu*)malloc(sizeof(stu));
//		scanf("%d%s%s%d", &p->num, &p->name, &p->sex,&p->score);
//
//	}
//	return head;
//}
stu *creat(void)//创建链表
{
	printf("请依次输入学生学号、姓名、性别、成绩:\n");
	stu *head, *p, *q;
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
	q->next = NULL;
	return head;
}
stu*print(stu *head)
{
	while (head != NULL)
	{
		printf("%d %s %s %d\n", head->num, head->name, head->sex, head->score);
		head = head->next;
	}
	return head;
}
int main()
{
	stu *pt;
	pt = creat();
	print(pt);
	pt=sort(pt);
	printf("\n");
	print(pt);
	return 0;
}