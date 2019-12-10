#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	int num;
	char name[10];
	char sex[10];
	struct student *next;
};
struct student *creat(void)
{
	struct student *head, *p1,*p2;
	head = (struct student*)malloc(LEN);
	scanf("%d%s%s", &head->num, &head->name, &head->sex);
	p1=p2= head;
	while (p1->num != 0)
	{
		p1 = (struct student*)malloc(LEN);
		scanf("%d%s%s", &p1->num, &p1->name, &p1->sex);
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	return head;
}
int main()
{
	struct student *pt;
	pt = creat();
	while (pt!= NULL)
	{
		printf("%d %s %s\n", pt->num, pt->name, pt->sex);
		pt = pt->next;//把next指向的下一个结构体的地址赋给pt，直至next赋的地址为空指针，循环自动停止
	}
	return 0;
}