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
		p = (*p).next;//����������һ���
	} while (p != NULL);//��ָ���ָ�벻Ϊ��ָ�������ѭ��
}
struct student *creat(void)
{
	struct student*head;//����һ��ͷ��ַ
	struct student *p1, *p2;
	p1 = p2 = (struct student *)malloc(L);//����һ����̬�洢�����ô洢��ֻ�ܴ��һ��struct studebt���͵�����
	scanf("%d%s%s", &(*p1).num, &(*p1).name, &(*p1).sex);//����̬�洢����������
	n = 0;
	head = NULL;
	while ((*p1).num != 0)
	{
		n = n + 1;
		if (n == 1)
			head = p1;
		else
			(*p2).next = p1;
		p2 = p1;//��������޽Կ�
		//��Ϊp2=p1�������濪�ٵĴ洢����ͬʱ������p1��p2�Ĵ洢�������ܲ��ϲ����µ�(*p2).nextָ����һ��p1���
		p1 = (struct student*)malloc(L);//��ѭ�����ٴδ�����̬�洢������ַΪp1���׵�ַ����ѭ���˶��ٴξʹ����˶��ٸ���̬�洢��
		scanf("%d%s%s", &(*p1).num, &(*p1).name, &(*p1).sex);//����̬�洢����������
	}
	(*p2).next = NULL;//ʹ��ĩβ��ָ��Ϊ��ָ�룬�Ӷ��ﵽʹ����ֹͣ���е�Ч��
	return (head);
}
int main()
{
	struct student *pt;
	pt = creat();//��ͷ��ַ����pt
	print(pt);
	printf("\nnum:%d\nname:%s\nsex:%s\n", (*pt).num, (*pt).name, (*pt).sex);
	return 0;
}

