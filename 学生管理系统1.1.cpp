#define _CRT_SECURE_NO_DEPRECATE 0
//��������
//��ӡ���������
//��������µ�����
//ɾ�����������
//������Ҫ��ӡ�Ľڵ�
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
stu *creat(void)//��������
{
	printf("����������ѧ��ѧ�š��������Ա𡢳ɼ�:\n");
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
stu *print(stu*head)//��ӡ����
{
	int a;
	printf("�Ƿ����ѧ������(1/0)��");
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
		printf("�Ƿ������������");
	}
	else
	{
		printf("�������");
	}
	return head;
}
stu*del(stu*head, int num)//ɾ������ڵ�
{
	stu *p1, *p2;
	p2 = NULL;
	if (head == NULL)//������ǿ�����
	{
		printf("������");
		return head;
	}
	p1 = head;
	while (p1->num != num&&p1->next != NULL)//��������Ѱ��Ŀ��ֵ
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->num == num)
	{
		if (p1 == head)//Ŀ��ڵ�Ϊͷ�ڵ�
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
		printf("�޸�ѧ�ŵ�ѧ��");
	}
	return head;
}
//stu*sort1(stu*head)//���ɼ���С��������
//{
//	stu *p, *q,*n;
//	p = head;
//	if (head == NULL)
//	{
//		printf("������");
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
stu*insert(stu*head, stu*t)//����Ĳ���
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
stu *find(stu *head)//����Ĳ���
{
	int a, b;
	printf("�Ƿ���в��ң���1/0��:");
	scanf("%d", &a);
	if (a == 1)
	{
		int num;
		printf("������ѧ��:\n");
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
			printf("�޴�ѧ����\n");
		}
	}
	else if (a == 0)
	{
		printf("�Ƿ��ӡ����?(1/0):");
		scanf("%d", &b);
		if (b == 1)
		{
			print(head);
		}
		else if (a == 0)
		{
			printf("�˳�\n");
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
	printf("��������Ҫɾ����ѧ��ѧ�ţ�\n");
	scanf("%d", &a);
	pt = del(pt, a);
	print(pt);
	//pt=sort1(pt);
	//print(sort1(pt));
	printf("��������Ҫ�����ѧ������:\n");
	scanf("%d%s%s%d", &p->num, &p->name, &p->sex, &p->score);
	qt = insert(pt, p);
	print(qt);
	find(pt);
	return 0;
}

/*ͷ�巨��ת�������
1.������ͷ�ڵ�͵�һ���ڵ������,
p=head->next;
t=p->next;
p->next=NULL;
2.Ȼ����ͷ�巨��ԭ����Ľڵ���뵽�µ�ͷ���(��������ͷ���)
*/
//stu *reverse(stu *head)													//�д���
//{
//	stu *t, *p, *q;
//	p = head->next;
//	t = p->next;				//p->�Ͽ�ǰ�������һ���ڵ� 
//	p->next = NULL;				//��ͷ���͵�һ���ڵ������,���ѵ�һ�����ָ���ÿ�;    
//	while (t != NULL)
//	{							//ѭ��ͷ��  t->�Ͽ��ĺ󲿵�һ���ڵ�   
//		q = t->next;			//p����t�ĺ�̽ڵ�,��ΪtҪ�Ͽ� 
//		t->next = head->next;	//��tͷ�嵽������ 
//		head->next = t;
//		t = q;					//��t����ָ��󲿵�һ���ڵ� 	
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
//stu *print(stu*head)//��ӡ����
//{
//	int a;
//	printf("�Ƿ����ѧ������(1/0)��");
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
//		printf("�Ƿ������������\n");
//	}
//	else
//	{
//		printf("�������\n");
//	}
//	return head;
//}
//stu *find(stu *head)
//{
//	int a,b;
//	printf("�Ƿ���в��ң���1/0��:");
//	scanf("%d", &a);
//	if (a == 1)
//	{
//		int num;
//		printf("������ѧ��:\n");
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
//			printf("�޴�ѧ����\n");
//		}
//	}
//	else if (a == 0)
//	{
//		printf("�Ƿ��ӡ����?(1/0):");
//		scanf("%d", &b);
//		if (b == 1)
//		{
//			print(head);
//		}
//		else if (a == 0)
//		{
//			printf("�˳�\n");
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