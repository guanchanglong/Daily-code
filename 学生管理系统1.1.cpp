#define _CRT_SECURE_NO_DEPRECATE 0
//创建链表
//打印里面的内容
//在面插入新的内容
//删除里面的内容
//搜索想要打印的节点
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	int num;
	char name[10];
	char sex[10];
	int score;
	struct student *next;
}stu;
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
stu *print(stu*head)//打印链表
{
	int a;
	printf("是否输出学生数据(1/0)：");
	scanf("%d", &a);
	if (a == 1)
	{
		while (head->num != 0)
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
stu*del(stu*head, int num)//删除链表节点
{
	stu *p1, *p2;
	p2 = NULL;
	if (head == NULL)//传入的是空链表
	{
		printf("空链表");
		return head;
	}
	p1 = head;
	while (p1->num != num&&p1->next != NULL)//遍历链表寻找目标值
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->num == num)
	{
		if (p1 == head)//目标节点为头节点
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
//stu*sort1(stu*head)//按成绩从小到大排序
//{
//	stu *p, *q,*n;
//	p = head;
//	if (head == NULL)
//	{
//		printf("空链表");
//	}
//	while (p->num!=0)
//	{
//		q = p;
//		p = p->next;
//		if (q->score>p->score && p->num!=0)
//		{
//			n = (stu*)malloc(sizeof(stu));
//			n->num = q->num;
//			strcpy(n->name, q->name);
//			strcpy(n->sex, q->sex);
//			n->score = q->score;
//			q->num = p->num;//
//			strcpy(q->name, p->name);
//			strcpy(q->sex, p->sex);
//			q->score = p->score;
//			p->num = n->num;//
//			strcpy(p->name, n->name);
//			strcpy(p->sex, n->sex);
//			p->score = n->score;
//		}
//	}
//	return head;
//}
stu*insert(stu*head, stu*t)//链表的插入
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
		while (p0->num > p1->num&&p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num < p1->num)
		{
			if (head == p1)
			{
				p0->next=head;
				return p0;
			}
			else
			{
				p2->next = p0;
				p0->next = p1;
			}
		}
		else
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	return (head);
}
stu *find(stu *head)//链表的查找
{
	int a, b;
	printf("是否进行查找？（1/0）:");
	scanf("%d", &a);
	if (a == 1)
	{
		int num;
		printf("请输入学号:\n");
		scanf("%d", &num);
		while (head->num != num)
		{
			head = head->next;
		}
		if (head->num == num)
		{
			printf("%d %s %s %d\n", head->num, head->name, head->sex, head->score);
		}
		else
		{
			printf("无此学号者\n");
		}
	}
	else if (a == 0)
	{
		printf("是否打印名单?(1/0):");
		scanf("%d", &b);
		if (b == 1)
		{
			print(head);
		}
		else if (a == 0)
		{
			printf("退出\n");
		}
		else
		{
			;
		}
	}
	return head;
}
int main()
{
	int a;
	stu *p;
	p = (stu*)malloc(sizeof(stu));
	stu*pt,*qt;
	pt = creat();
	print(pt);
	printf("请输入需要删除的学生学号：\n");
	scanf("%d", &a);
	pt = del(pt, a);
	print(pt);
	//pt=sort1(pt);
	//print(sort1(pt));
	printf("请输入需要插入的学生数据:\n");
	scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
	qt = insert(pt, p);
	print(qt);
	find(pt);
	return 0;
}

/*头插法后翻转链表输出
1.把链表头节点和第一个节点拆下来,
p=head->next;
t=p->next;
p->next=NULL;
2.然后用头插法把原链表的节点插入到新的头结点(拆下来的头结点)
*/
//stu *reverse(stu *head)													//有错误
//{
//	stu *t, *p, *q;
//	p = head->next;
//	t = p->next;				//p->断开前部的最后一个节点 
//	p->next = NULL;				//把头结点和第一个节点拆下来,并把第一个结点指针置空;    
//	while (t != NULL)
//	{							//循环头插  t->断开的后部第一个节点   
//		q = t->next;			//p保存t的后继节点,因为t要断开 
//		t->next = head->next;	//把t头插到新链表 
//		head->next = t;
//		t = q;					//让t继续指向后部第一个节点 	
//	}
//	return head;
//}
//stu *creat(void)
//{
//	stu *head, *p;
//	head = NULL;
//	p = (stu*)malloc(sizeof(stu));
//	scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
//	while (p->num != 0)
//	{
//		p->next = head;
//		head = p;
//		p = (stu*)malloc(sizeof(stu));
//		scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
//	}
//	return head;
//}
//stu *print(stu*head)//打印链表
//{
//	int a;
//	printf("是否输出学生数据(1/0)：");
//	scanf("%d", &a);
//	if (a == 1)
//	{
//		while (head->num != 0)
//		{
//			printf("%d%s%s%d\n", head->num, head->name, head->sex, head->score);
//			head = head->next;
//		}
//	}
//	else if (a == 0)
//	{
//		printf("是否进行其他操作\n");
//	}
//	else
//	{
//		printf("输入错误\n");
//	}
//	return head;
//}
//stu *find(stu *head)
//{
//	int a,b;
//	printf("是否进行查找？（1/0）:");
//	scanf("%d", &a);
//	if (a == 1)
//	{
//		int num;
//		printf("请输入学号:\n");
//		scanf("%d", &num);
//		while (head->num!=num)
//		{
//			head = head->next;
//		}
//		if (head->num == num)
//		{
//			printf("%d %s %s %d", head->num, head->name, head->sex, head->score);
//		}
//		else
//		{
//			printf("无此学号者\n");
//		}
//	}
//	else if (a == 0)
//	{
//		printf("是否打印名单?(1/0):");
//		scanf("%d", &b);
//		if (b == 1)
//		{
//			print(head);
//		}
//		else if (a == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			;
//		}
//	}
//	return head;
//}
//int main()
//{
//	stu*pt;
//	pt = creat();
//	find(pt);
//	return 0;
//}