#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct student
{
	int num;
	float score;
	struct student *next;//该指针继续指向该结构体
};
int main()//静态链表
{
	struct student a, b, c, *head, *p;
	a.num = 1;
	a.score = 11;
	b.num = 2;
	b.score = 22;
	c.num = 3;
	c.score = 33;
	head = &a;//将结点a的起始地址赋给头指针head
	a.next = &b;//将结点b的起始地址赋给a结点的next成员
	b.next = &c;
	c.next = NULL;//空指针
	p = head;
	do
	{
		printf("%ld\t%.2lf\n", (*p).num, (*p).score);
		p = (*p).next;//使p指向下一结点
	} while (p != NULL);
	return 0;
}