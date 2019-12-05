#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define L sizeof(struct student)
struct student
{
	int num;
	char name[100];
	char sex[10];
	struct student*next;
};
int n;
void print(struct student*head)
{
	struct student *p;
	printf("\nNow,These %d students are:\n", n);
	p = head;
	do
	{
		printf("%d %s %s\n", (*p).num, (*p).name,(*p).sex);
		p = (*p).next;//继续进入下一结点
	} while (p != NULL);//当指向的指针不为空指针则继续循环
}
struct student *creat(void)
{
	struct student*head;//创建一个头地址
	struct student *p1, *p2;
	p1 = p2 = (struct student *)malloc(L);//创建一个动态存储区，该存储区只能存放一组struct studebt类型的数据
	scanf("%d%s%s", &(*p1).num, &(*p1).name, &(*p1).sex);//往动态存储区输入数据
	n = 0;
	head = NULL;
	while ((*p1).num != 0)
	{
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			(*p2).next = p1;
		p2 = p1;//此语句有无皆可
		//因为p2=p1所以下面开辟的存储区中同时开辟了p1和p2的存储区，故能不断产生新的(*p2).next指向上一个p1结点
		p1 = (struct student*)malloc(L);//在循环中再次创建动态存储区（地址为p1的首地址），循环了多少次就创建了多少个动态存储区
		scanf("%d%s%s", &(*p1).num, &(*p1).name, &(*p1).sex);//往动态存储区输入数据
	}
	(*p2).next = NULL;//使最末尾的指针为空指针，从而达到使程序停止运行的效果
	return (head);
}
int main()
{
	struct student *pt;
	pt = creat();//将头地址传给pt
	print(pt);
	printf("\nnum:%d\nname:%s\nsex:%s\n", (*pt).num, (*pt).name, (*pt).sex);
	return 0;
}

