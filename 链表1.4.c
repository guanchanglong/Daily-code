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
		pt = pt->next;//��nextָ�����һ���ṹ��ĵ�ַ����pt��ֱ��next���ĵ�ַΪ��ָ�룬ѭ���Զ�ֹͣ
	}
	return 0;
}