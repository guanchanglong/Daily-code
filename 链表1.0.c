#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct student
{
	int num;
	float score;
	struct student *next;//��ָ�����ָ��ýṹ��
};
int main()//��̬����
{
	struct student a, b, c, *head, *p;
	a.num = 1;
	a.score = 11;
	b.num = 2;
	b.score = 22;
	c.num = 3;
	c.score = 33;
	head = &a;//�����a����ʼ��ַ����ͷָ��head
	a.next = &b;//�����b����ʼ��ַ����a����next��Ա
	b.next = &c;
	c.next = NULL;//��ָ��
	p = head;
	do
	{
		printf("%ld\t%.2lf\n", (*p).num, (*p).score);
		p = (*p).next;//ʹpָ����һ���
	} while (p != NULL);
	return 0;
}