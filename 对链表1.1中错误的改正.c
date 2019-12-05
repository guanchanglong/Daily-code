#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;
struct student *creat(void)
{
	struct student *head;
	struct student *p1, *p2;
	n = 0;
	p1 = p2 = (struct student*)malloc(LEN);
	scanf("%ld,%f", &(*p1).num, &(*p1).score);//%d=int,	%ld = long,	%lld = long long;
	head = NULL;
	while ((*p1).num != 0)
	{
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			(*p2).next = p1;
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf("%ld,%f", &(*p1).num, &(*p1).score);//%d=int,	%ld = long,	%lld = long long;
	}
	(*p2).next = NULL;
	return (head);
}
int main()
{
	struct student*pt;
	pt = creat();
	printf("\nnum:%ld\nscore:%5.1f\n", (*pt).num, (*pt).score);
	return 0;
}