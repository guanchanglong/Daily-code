#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#define	_CRT_NONSTDC_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<time.h>
#include<string.h>
#include<conio.h>
void gotoxy(int x, int y);
void menu1();
void menu2();
void menu3();
void menu4();
void menu5();
void menu6();
void menu7();
void caozuo();
void teawritefile();
void teareadfile();
void stuwritefile();
void stureadfile();
void sign_up();
void sign_in();

typedef struct teacher
{
	char num[20];
	char name[10];
	char sex[5];
	char password[12];
	struct teacher *next;
}tea;
typedef struct student
{
	char num[20];
	char name[10];
	char sex[5];
	int yu;
	int shu;
	int ying;
	int zongfen;
	char password[12];
	struct student *next;
}stu;

FILE *fp1,*fp2,*fp3;
char filename1[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\��ʦע������.txt";
char filename2[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\ѧ��ע������.txt";
char filename3[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\ѧ���ɼ�.txt";

stu student11;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void menu1()
{
	gotoxy(53, 8);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 10);
	printf("******************�˵�*********************");
	gotoxy(40, 11);
	printf("*               1 ��¼                    *");
	gotoxy(40, 12);
	printf("*               2 ע��                    *");
	gotoxy(40, 13);
	printf("*               0 �˳�                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu2()//��ʦ��¼��˵�
{
	gotoxy(53, 7);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 9);
	printf("******************�˵�*********************");
	gotoxy(40, 10);
	printf("* 1 ���				2 ɾ�� *");
	gotoxy(40, 11);
	printf("* 3 �޸�				4 ���� *");
	gotoxy(40, 12);
	printf("* 5 �鿴				6 ͳ�� *");
	gotoxy(40, 13);
	printf("* 7 ����				0 �˳� *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu3()//ѧ����¼��˵�
{
	gotoxy(53, 7);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 9);
	printf("******************�˵�*********************");
	gotoxy(40, 10);
	printf("*                1 ����                   *");
	gotoxy(40, 11);
	printf("*                2 ͳ��                   *");
	gotoxy(40, 12);
	printf("*                0 �˳�                   *");
	gotoxy(40, 13);
	printf("*******************************************");
}
void menu4()//��¼�˵�
{
	gotoxy(53, 8);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 10);
	printf("******************�˵�*********************");
	gotoxy(40, 11);
	printf("*             1 ��ʦ��¼                  *");
	gotoxy(40, 12);
	printf("*             2 ѧ����¼                  *");
	gotoxy(40, 13);
	printf("*               0 �˳�                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu5()//ע��˵�
{
	gotoxy(53, 8);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 10);
	printf("******************�˵�*********************");
	gotoxy(40, 11);
	printf("*             1 ��ʦע��                  *");
	gotoxy(40, 12);
	printf("*             2 ѧ��ע��                  *");
	gotoxy(40, 13);
	printf("*               0 �˳�                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu6()//ע��ɹ���ĵ�¼�˵�
{
	gotoxy(53, 8);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 10);
	printf("******************�˵�*********************");
	gotoxy(40, 11);
	printf("*               1 ��¼                    *");
	gotoxy(40, 12);
	printf("*                                         *");
	gotoxy(40, 13);
	printf("*               0 �˳�                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu7()
{
	gotoxy(53, 6);
	printf(" ѧ������ϵͳ");
	gotoxy(35, 9);
	printf("������ѧ��ѧ�ţ�");
	gotoxy(35, 10);
	printf("������ѧ��������");
	gotoxy(35, 11);
	printf("������ѧ���Ա�");
	gotoxy(35, 12);
	printf("������ѧ���ɼ�:");
	gotoxy(35, 14);
	printf("���ģ�	��ѧ��		Ӣ�");
}
void menu8()
{
	gotoxy(53, 8);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 10);
	printf("******************�˵�*********************");
	gotoxy(40, 11);
	printf("*            1 ��ѧ�Ų���                 *");
	gotoxy(40, 12);
	printf("*            2 ����������                 *");
	gotoxy(40, 13);
	printf("*            3 ���Ա����                 *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu9()
{
	gotoxy(53, 8);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 10);
	printf("******************�˵�*********************");
	gotoxy(40, 11);
	printf("*            1 ����ƽ����                 *");
	gotoxy(40, 12);
	printf("*            2 ��ѧƽ����                 *");
	gotoxy(40, 13);
	printf("*            3 Ӣ��ƽ����                 *");
	gotoxy(40, 14);
	printf("*        4 ȫ��ѧ������ƽ����             *");
	gotoxy(40, 15);
	printf("*               0 �˳�                    *");
	gotoxy(40, 16);
	printf("*******************************************");
}

stu *createlink(void)								//���ļ������Ϣת����������
{
	fp3 = fopen(filename3, "a+");
	stu *p, *q, *head;
	stu student;
	p = q = (stu*)malloc(sizeof(stu));
	head = p;
	while (fscanf(fp3, "%s %s %s %d %d %d", student.num, student.name, student.sex, &student.yu, &student.shu, &student.ying) != EOF)
	{
		p = (stu*)malloc(sizeof(stu));
		strcpy(p->num, student.num);			//strcpy�������Ը���һ���ַ�����������ݵ���һ���ַ�������
		strcpy(p->name, student.name);
		strcpy(p->sex, student.sex);
		p->yu = student.yu;
		p->shu = student.shu;
		p->ying = student.ying;
		q->next = p;
		q = p;
	}
	fclose(fp3);
	q->next = NULL;
	return head;
}

stu *del(stu*head, char num[], char name[])//ɾ������ڵ�
{
	stu *p1, *p2;
	p2 = NULL;
	if (head == NULL)//������ǿ�����
	{
		gotoxy(56, 15);
		printf("���ݿ�����ѧ������");
		return head;
	}
	p1 = head;
	while (strcmp(p1->num, num) != 0 && strcmp(p1->name, name) != 0 && p1->next != NULL)//��������Ѱ��Ŀ��ֵ
	{
		p2 = p1;
		p1 = p2->next;
	}
	if (strcmp(p1->num, num) == 0 && strcmp(p1->name, name) == 0)
	{
		if (p1 == head)//Ŀ��ڵ�Ϊͷ�ڵ�
		{
			head = p1->next;
			gotoxy(48, 15);
			printf("ɾ���ɹ�����");
			gotoxy(50, 17);
		}
		else
		{
			p2->next = p1->next;
			gotoxy(53, 15);
			printf("ɾ���ɹ�");
			gotoxy(50, 17);
		}
	}
	else
	{
		gotoxy(51, 15);
		printf("�޸�ѧ��");
		gotoxy(53, 16);
	}
	return head;
}

stu *save(stu*head)																//����ı���
{
	fp3 = fopen(filename3, "w+");												//��w+�ķ�ʽ���ļ������ļ���ԭ����������գ�д���µ�����
	while (head->next != NULL)
	{
		head = head->next;
		fprintf(fp3, "%s %s %s %d %d %d\n", head->num, head->name, head->sex, head->yu, head->shu, head->ying);//���������ļ���
	}
	fclose(fp3);
	return head;
}

stu *create(void)		//����ѧ����Ϣ
{	
	fp3 = fopen(filename3, "a+");
	if (fp3 == NULL)
	{
		system("cls");
		gotoxy(56, 17);
		printf("����ʧ��");
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
	int i;
	stu student,student1,*head1;
	system("cls");
	menu7();
	stu *head, *p, *q;
	p = q = (stu*)malloc(sizeof(stu));
	gotoxy(52, 9);
	scanf("%s", p->num);
	gotoxy(52, 10);
	scanf("%s", p->name);
	gotoxy(52, 11);
	scanf("%s", p->sex);
	gotoxy(40, 14);
	scanf("%d", &p->yu);
	gotoxy(55, 14);
	scanf("%d", &p->shu);
	gotoxy(72, 14);
	scanf("%d", &p->ying);
	head = p;
	while (fscanf(fp3, "%s %s %s\n", student.num, student.name, student.sex) != EOF)
	{
		if (strcmp(student.name, p->name) == 0 && strcmp(p->num, student.num) == 0 && strcmp(p->sex, student.sex) == 0)//�ж��Ƿ��ظ�����ѧ����Ϣ
		{
			gotoxy(50, 15);
			printf("��ѧ���Ѵ��ڣ�");
			gotoxy(50, 16);
			printf("��������ȷ��ѧ����Ϣ��");
			Sleep(2000);
			system("cls");
			gotoxy(48, 15);
			exit(0);
		}
	}
	if (strcmp(student.name, p->name) != 0 && strcmp(p->num, student.num) != 0 && strcmp(p->sex, student.sex) != 0)
	{
		fprintf(fp3, "%s %s %s %d %d %d\n", p->num,p->name,p->sex,p->yu,p->shu,p->ying);
		fclose(fp3);
		head1 = createlink();
		head1=del(head1, "000", "000");
		save(head1);
		strcpy(student1.num, "000");
		strcpy(student1.name, "000");
		strcpy(student1.sex, "000");
		student1.yu = 0;
		student1.shu = 0;
		student1.ying = 0;
		fp3 = fopen(filename3, "a+");
		fprintf(fp3, "%s %s %s %d %d %d\n", student1.num,student1.name,student1.sex,student1.yu,student1.shu,student1.ying);
		system("cls");
		gotoxy(48, 15);
		Sleep(2000);
		gotoxy(48, 15);
		printf("����ɹ�!");
		Sleep(2000);
	}
	system("cls");
	gotoxy(35, 13);
	printf("�Ƿ�������ѧ����Ϣ(��1/��0)��");
	gotoxy(65, 13);
	scanf("%d", &i);
	system("cls");
	switch (i)
	{
	case 1:
		while (strcmp("000", p->num) != 0 && strcmp("000",p->name)!=0)
		{
			p = (stu*)malloc(sizeof(stu));
			system("cls");
			gotoxy(46, 8);
			printf("��ѧ�ź�����Ϊ000����");
			menu7();
			gotoxy(52, 9);
			scanf("%s", p->num);
			gotoxy(52, 10);
			scanf("%s", p->name);
			gotoxy(52, 11);
			scanf("%s", p->sex);
			gotoxy(42, 14);
			scanf("%d", &p->yu);
			gotoxy(58, 14);
			scanf("%d", &p->shu);
			gotoxy(70, 14);
			scanf("%d", &p->ying);
			rewind(fp3);
				while (fscanf(fp3, "%s %s %s\n", student.num, student.name, student.sex) != EOF)
				{
					if (strcmp(student.name, p->name) == 0 && strcmp(p->num, student.num) == 0 && strcmp(p->sex, student.sex) == 0)//�ж��Ƿ��ظ�����ѧ����Ϣ
					{
						gotoxy(53, 15);
						printf("��ѧ���Ѵ��ڣ�");
						gotoxy(50, 16);
						printf("��������ȷ��ѧ����Ϣ��");
						Sleep(2000);
						system("cls");
						gotoxy(48, 15);
						exit(0);
					}
				}
				if (strcmp(student.name, p->name) != 0 && strcmp(p->num, student.num) != 0 && strcmp(p->sex, student.sex) != 0)
				{
					fprintf(fp3, "%s %s %s %d %d %d\n", p->num, p->name, p->sex, p->yu, p->shu, p->ying);
				}
				q->next = p;
				q = p;
			}
			q->next = NULL;
			return head;
		break;
	case 0:
		fclose(fp3);
		gotoxy(48, 15);
		exit(0);
	default:
		gotoxy(56, 17);
		printf("�������");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
	fclose(fp3);
	return head;
}

stu *change(stu*head,char num[],char name[])					//������޸�
{
		stu student,*p;
		p = head;
		while (strcmp(num,head->num)!=0&&strcmp(head->name,name)!=0)
		{
			head = head->next;
		}
		if (strcmp(num, head->num) == 0 && strcmp(head->name, name) == 0)
		{
			gotoxy(35, 10);
			printf("�������޸ĵ�ѧ��ѧ�ţ�");
			gotoxy(35, 11);
			printf("�������޸ĵ�ѧ��������");
			gotoxy(35, 12);
			printf("�������޸ĵ�ѧ���Ա�");
			gotoxy(35, 13);
			printf("�������޸ĵ�ѧ�����ĳɼ���");
			gotoxy(35, 14);
			printf("�������޸ĵ�ѧ����ѧ�ɼ���");
			gotoxy(35, 15);
			printf("�������޸ĵ�ѧ��Ӣ��ɼ���");
			gotoxy(62, 10);
			scanf("%s", student.num);
			gotoxy(62, 11);
			scanf("%s", student.name);
			gotoxy(62, 12);
			scanf("%s", student.sex);
			gotoxy(62, 13);
			scanf("%d", &student.yu);
			gotoxy(62, 14);
			scanf("%d", &student.shu);
			gotoxy(62, 15);
			scanf("%d", &student.ying);
			strcpy(head->num, student.num);
			strcpy(head->name, student.name);
			strcpy(head->sex, student.sex);
			head->yu = student.yu;
			head->shu = student.shu;
			head->ying = student.ying;
			system("cls");
			Sleep(2000);
			gotoxy(48, 16);
			printf("�޸ĳɹ�����");
			Sleep(2000);
		}
		else
		{
			gotoxy(52, 16);
			printf("�޴�ѧ������");
		}
	return p;
}

void search_num()						//ģ������ѧ��ѧ��
{
	stu student;
	int m = 0;
	char a[20];
	gotoxy(35, 14);
	printf("��������Ҫ���ҵ�ѧ��ѧ�ţ�");
	gotoxy(62, 14);
	scanf("%s", a);
	system("cls");
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %s %s %d %d %d", student.num, student.name, student.sex, &student.yu, &student.shu, &student.ying) != EOF)
	{
		if (strstr(student.num,a) != NULL)
		{
			m = m + 1;
			gotoxy(35, m);
			printf("%s\t%s\t%s\t%d\t%d\t%d\t", student.num, student.name, student.sex, student.yu, student.shu, student.ying);
		}
	}
	if (m==0)
	{
		gotoxy(48, 15);
		printf("û�з���������ѧ������");
	}
	fclose(fp3);
}

void search_name()						//ģ������ѧ������
{
	stu student;
	int m = 0;
	char a[10];
	gotoxy(35, 14);
	printf("��������Ҫ���ҵ�ѧ��������");
	gotoxy(62, 14);
	scanf("%s", a);
	system("cls");
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %s %s %d %d %d", student.num, student.name, student.sex, &student.yu, &student.shu, &student.ying) != EOF)
	{
		if (strstr(student.name,a) != NULL)
		{
			m = m + 1;
			gotoxy(35, m);
			printf("%s\t%s\t%s\t%d\t%d\t%d\t", student.num, student.name, student.sex, student.yu, student.shu, student.ying);
		}
	}
	if (m == 0)
	{
		gotoxy(48, 15);
		printf("û�з���������ѧ������");
	}
	fclose(fp3);
}

void search_sex()						//ģ������ѧ���Ա�
{
	stu student;
	int m = 0;
	char a[5];
	gotoxy(35, 14);
	printf("��������Ҫ���ҵ��Ա�");
	gotoxy(62, 14);
	scanf("%s", a);
	system("cls");
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %s %s %d %d %d", student.num, student.name, student.sex, &student.yu, &student.shu, &student.ying) != EOF)
	{
		if (strstr(student.sex,a ) != NULL)
		{
			m = m + 1;
			gotoxy(35, m);
			printf("%s\t%s\t%s\t%d\t%d\t%d\t", student.num, student.name, student.sex, student.yu, student.shu, student.ying);
		}
	}
	if (m == 0)
	{
		gotoxy(48, 15);
		printf("û�з���������ѧ������");
	}
	fclose(fp3);
}

void print()							//��ӡ����ѧ����Ϣ
{
	int m=0;
	stu student;
	fp3 = fopen(filename3, "a+");
	while (fscanf(fp3, "%s %s %s %d %d %d", student.num, student.name, student.sex, &student.yu, &student.shu, &student.ying) != EOF)
	{
		m = m + 1;
		gotoxy(35, m);
		printf("%s\t%s\t%s\t%d\t%d\t%d\t",student.num, student.name, student.sex, student.yu, student.shu, student.ying);
	}
	if (m == 0)
	{
		gotoxy(48, 15);
		printf("��ѧ�����ݣ���");
	}
	fclose(fp3);
}

void statistics1()			//ͳ��ȫ��ѧ���ɼ�
{
	int n;
	int count = 0;
	float x = 0, y = 0;
	stu *head;
	gotoxy(59, 17);
	scanf("%d", &n);
	system("cls");
	switch (n)
	{
	case 1:				//����ƽ����
		head=createlink();
		while (head->next->next != NULL)
		{
			head = head->next;
			y = y + head->yu;
			count = count + 1;
		}
		x = y / count;
		gotoxy(47, 15);
		printf("ȫ��ѧ�����ĳɼ�ƽ����Ϊ��%.2f", x);
		break;
	case 2:				//��ѧƽ����
		head = createlink();
		while (head->next->next != NULL)
		{
			head = head->next;
			y = y + head->shu;
			count = count + 1;
		}
		x = y / count;
		gotoxy(47, 15);
		printf("ȫ��ѧ����ѧ�ɼ�ƽ����Ϊ��%.2f", x);
		break;
	case 3:				//Ӣ��ƽ����
		head = createlink();
		while (head->next->next != NULL)
		{
			head = head->next;
			y = y + head->ying;
			count = count + 1;
		}
		x = y / count;
		gotoxy(47, 15);
		printf("ȫ��ѧ��Ӣ��ɼ�ƽ����Ϊ��%.2f", x);
		break;
	case 4:				//ȫ������ƽ����
		head = createlink();
		while (head->next->next != NULL)
		{
			head = head->next;
			y = y + head->yu;
			y = y + head->shu;
			y = y + head->ying;
			count = count + 1;
		}
		x = y / count;
		gotoxy(47, 15);
		printf("ȫ��ѧ���ɼ�ƽ����Ϊ��%.2f", x);
		break;
	case 0:
		gotoxy(53, 16);
		exit(0);
	default:
		gotoxy(56, 17);
		printf("�������");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
}

void statistics2()
{
	stu *head,student;
	float x;
	head=createlink();
	while (head->next != NULL)
	{
		head = head->next;
		if (strcmp(head->name, student11.name) == 0)
		{
			x = float(head->yu + head->shu + head->ying) / 3;
			gotoxy(35, 15);
			printf("���ĳɼ�Ϊ�����ģ�%d ��ѧ��%d Ӣ�%d ����ƽ���֣�%.2f", head->yu, head->shu, head->ying, x);
			strcpy(student.name, head->name);
		}
	}
	if (strcmp(student.name, student11.name) != 0)
	{
		gotoxy(45, 15);
		printf("������Ϣ��û�б���ʦ¼��ϵͳ");
	}
}

stu *pop_sort(stu *head)								//����ð������
{
	stu *pre, *p, *tail, *temp;
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail)
	{
		p = head->next;
		pre = head;
		while (p->next != tail)
		{
			if ((p->zongfen)>(p->next->zongfen))
			{
				pre->next = p->next;
				temp = p->next->next;
				p->next->next = p;
				p->next = temp;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	return head;
}

void caozuo1()				//��ɾ�Ĳ�
{
	int n,m=0;
	gotoxy(59, 15);
	scanf("%d", &n);
	stu *head, student,*p;
	switch (n)
	{
	case 1:					//����
		create();
		system("cls");
		gotoxy(53, 16);
		break;
	case 2:					//ɾ��
		head = createlink();										//���ļ��������ת��һ��������
		system("cls");
		gotoxy(35, 12);
		printf("��������ɾ����ѧ��ѧ�ţ�");
		gotoxy(35, 14);
		printf("��������ɾ����ѧ��������");
		gotoxy(62, 12);
		scanf("%s", student.num);
		gotoxy(62, 14);
		scanf("%s", student.name);
		head=del(head, student.num, student.name);		//ɾ���������и�ѧ���Ľڵ�
		save(head);													//��ɾ����ĵ������浽�ļ���
		system("cls");
		gotoxy(53, 16);
		break;
	case 3:					//�޸�
		system("cls");
		head=createlink();
		gotoxy(35, 12);
		printf("��������޸ĵ�ѧ��ѧ�ţ�");
		gotoxy(35, 14);
		printf("��������޸ĵ�ѧ��������");
		gotoxy(62, 12);
		scanf("%s", student.num);
		gotoxy(62, 14);
		scanf("%s", student.name);
		system("cls");
		head=change(head, student.num, student.name);
		save(head);
		system("cls");
		gotoxy(53, 16);
		break;
	case 4:					//ģ������
		system("cls");
		menu8();
		int m;
		gotoxy(59, 15);
		scanf("%d", &m);
		system("cls");
		switch (m)
		{
		case 1:
			search_num();
			break;
		case 2:
			search_name();
			break;
		case 3:
			search_sex();
			break;
		default:
			gotoxy(56, 17);
			printf("�������");
			Sleep(2000);
			system("cls");
			gotoxy(53, 16);
			exit(0);
		}
		break;
	case 5:					//��ӡ����ѧ����Ϣ
		system("cls");
		gotoxy(53, 16);
		Sleep(2000);
		print();
		break;
	case 6:					//ѧ���ɼ�ͳ��
		system("cls");
		menu9();
		statistics1();
		gotoxy(53, 16);
		break;
	case 7:					//���ɼ�����
		head = createlink();
		p = head;
		while (head->next != NULL)
		{
			head = head->next;
			head->zongfen = head->yu + head->shu + head->ying;
		}
		p=pop_sort(p);
		system("cls");
		while (p->next != NULL)
		{
			m = m + 1;
			p = p->next;
			printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t�����ܷ֣�%d\n", p->num, p->name, p->sex, p->zongfen);
		}
		break;
	case 0:
		gotoxy(53, 16);
		break;
	default:
		gotoxy(56, 17);
		printf("�������");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
}

void caozuo2()
{
	int n;
	gotoxy(59, 14);
	scanf("%d", &n);
	switch (n)
	{
	case 1:				//����
		system("cls");
		menu8();
		int m;
		gotoxy(59, 15);
		scanf("%d", &m);
		system("cls");
		switch (m)
		{
		case 1:
			search_num();			//��ѧ��ѧ�Ų���
			break;
		case 2:
			search_name();			//��ѧ����������
			break;
		case 3:
			search_sex();			//��ѧ���Ա����
			break;
		default:
			gotoxy(56, 17);
			printf("�������");
			Sleep(2000);
			system("cls");
			gotoxy(53, 16);
			exit(0);
		}
		break;
	case 2:							//ͳ�Ƶ�¼ѧ����ƽ����
		system("cls");
		statistics2();
		gotoxy(53, 16);
		break;
	case 0:
		gotoxy(56, 17);
		break;
	default:
		gotoxy(56, 17);
		printf("�������");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
}

void teawritefile()//��ʦ�趨����
{
	fp1 = fopen(filename1, "a+");//��׷�ӵķ�ʽ���ļ�
	if (fp1 == NULL)
	{
		printf("ע��ʧ��\n");
		gotoxy(48, 15);
		exit(1);
	}
	tea teacher;
	tea teacher1;
	gotoxy(40, 9);
	printf("�������ʦ���ţ�");
	gotoxy(40, 10);
	printf("�������ʦ������");
	gotoxy(40, 11);
	printf("�������ʦ�Ա�");
	gotoxy(40, 12);
	printf("���Զ������룺");
	gotoxy(62, 9);
	scanf("%s", teacher1.num);
	gotoxy(62, 10);
	scanf("%s", teacher1.name);
	gotoxy(62, 11);
	scanf("%s", teacher1.sex);
	gotoxy(62, 12);
	scanf("%s", teacher1.password);
		while (fscanf(fp1, "%s %s %s %s\n", teacher.num, teacher.name, teacher.sex, teacher.password) != EOF)
		{
			if (strcmp(teacher.name, teacher1.name) == 0 && strcmp(teacher1.num, teacher.num) == 0 && strcmp(teacher1.sex, teacher.sex) == 0)//�ж��Ƿ��ظ�ע��
			{
				gotoxy(53, 15);
				printf("���û��Ѵ��ڣ�");
				gotoxy(50, 16);
				printf("��������ȷ���û����ϣ�");
				Sleep(2000);
				system("cls");
				gotoxy(48, 15);
				exit(0);
			}
		}
		if (strlen(teacher1.password) > 11)					//strlen�������Լ����ַ��� str �ĳ��ȣ�ֱ���ս����ַ������������ս����ַ���
		{
			gotoxy(42, 15);
			printf("��������������볤�����˵�����ģ�");
			Sleep(2000);
			gotoxy(48, 16);
			exit(0);
		}
		fprintf(fp1, "%s %s %s %s\n", teacher1.num, teacher1.name, teacher1.sex, teacher1.password);
		gotoxy(48, 15);
		printf("��ϲ��ע��ɹ�!");
		Sleep(2000);//��ʱ���ã�ͣ�������ҳ��2��
	fclose(fp1);
}

void teareadfile()//��ʦ�����ȡ
{
	tea teacher;
	tea teacher1;
		fp1 = fopen(filename1, "a+");
		gotoxy(40, 10);	
		printf("�������ʦ������");
		gotoxy(40, 12);
		printf("����������(ʮλ����)��");
		gotoxy(62, 10);
		scanf("%s", teacher1.name);//�����û���
		char a[11];
		int i = 0;
		gotoxy(62, 12);
		for (i = 0; i < 11; i++)
		{
			gotoxy(62+i, 12);
			a[i] = getch();					//getch������;���ӿ���̨��ȡһ���ַ���������ʾ����Ļ�ϣ���������ʵ������Ķ�ȡ������
			printf("*");
			if (a[i] == 13)
			{
				break;
			}
		}
		int j;
		for (j=0; j < i; j++)
		{
			if (a[j] != 13)
			{
				teacher1.password[j] = a[j];
			}
		}
		teacher1.password[j] = '\0';		//�������11λ�Ļ�������\0����
		gotoxy(53, 13);
		printf("��¼�У����Ե�.....");
		Sleep(2000);
		system("cls");
		while (fscanf(fp1, "%s %s %s %s\n", teacher.num,teacher.name,teacher.sex, teacher.password) != EOF)
		{
			if (strcmp(teacher.name,teacher1.name)==0 && strcmp(teacher1.password,teacher.password)==0)//��ȡ����
			{
				gotoxy(53, 13);
				printf("��¼�ɹ�!");
				Sleep(2000);
				break;
			}
		}
		if (strcmp(teacher.name, teacher1.name) != 0 || strcmp(teacher1.password, teacher.password) != 0)
		{
			gotoxy(50, 13);
			Sleep(2000);
			gotoxy(50, 13);
			printf("��¼ʧ�ܣ���˶�����������");
			Sleep(2000);
			gotoxy(50, 14);
			exit(0);
		}
		fclose(fp1);
}

void stuwritefile()//ѧ���趨����
{
	fp2 = fopen(filename2, "a+");//��׷�ӵķ�ʽ���ļ�
	if (fp2 == NULL)
	{
		gotoxy(48, 15);
		printf("ע��ʧ��\n");
		gotoxy(48, 15);
		exit(1);
	}
	stu student;
	stu student1;
	gotoxy(40, 9);
	printf("������ѧ��ѧ�ţ�");
	gotoxy(40, 10);
	printf("������ѧ��������");
	gotoxy(40, 11);
	printf("������ѧ���Ա�");
	gotoxy(40, 12);
	printf("���Զ�������(ʮλ����)��");
	gotoxy(63, 9);
	scanf("%s", student1.num);
	gotoxy(63, 10);
	scanf("%s", student1.name);
	gotoxy(63, 11);
	scanf("%s", student1.sex);
	gotoxy(63, 12);
	scanf("%s", student1.password);
		while (fscanf(fp2, "%s %s %s %s\n", student.num, student.name, student.sex, student.password) != EOF)
		{
			if (strcmp(student.name, student1.name) == 0 && strcmp(student1.num, student.num) == 0 && strcmp(student1.sex, student.sex) == 0)//�ж��Ƿ��ظ�ע��
			{
				gotoxy(53, 15);
				printf("���û��Ѵ��ڣ�");
				gotoxy(50, 16);
				printf("��������ȷ���û����ϣ�");
				Sleep(2000);
				system("cls");
				gotoxy(48, 15);
				exit(0);
			}
		}
		if (strlen(student1.password) > 11)
		{
			gotoxy(42, 15);
			printf("��������������볤�����˵�����ģ�");
			gotoxy(48, 16);
			exit(0);
		}
		fprintf(fp2, "%s %s %s %s\n", student1.num, student1.name, student1.sex, student1.password);
		gotoxy(48, 15);
		printf("��ϲ��ע��ɹ�!");
		Sleep(2000);//��ʱ���ã�ͣ�������ҳ��2��
	fclose(fp2);
}

void stureadfile()//ѧ�������ȡ
{
	stu student;
	fp2 = fopen(filename2, "a+");
	gotoxy(40, 10);
	printf("������ѧ��������");
	gotoxy(40, 12);
	printf("����������(ʮλ����)��");
	gotoxy(62, 10);
	scanf("%s", student11.name);//�����û���
	char a[11];
	int i = 0;
	gotoxy(62, 12);
	for (i = 0; i < 11; i++)
	{
		gotoxy(62 + i, 12);
		a[i] = getch();				//getch������;���ӿ���̨��ȡһ���ַ���������ʾ����Ļ�ϣ���������ʵ������Ķ�ȡ������
		printf("*");
		if (a[i] == 13)
		{
			break;
		}
	}
	int j;
	for (j = 0; j < i; j++)
	{
		if (a[j] != 13)
		{
			student11.password[j] = a[j];
		}
	}
	student11.password[j] = '\0';
	gotoxy(53, 13);
	printf("��¼�У����Ե�.....");
	Sleep(2000);
	system("cls");
	while (fscanf(fp2, "%s %s %s %s\n", student.num, student.name, student.sex, student.password) != EOF)
	{
		if (strcmp(student.name, student11.name) == 0 && strcmp(student11.password, student.password) == 0)//��ȡ����
		{
			gotoxy(53, 13);
			printf("��¼�ɹ�!");
			Sleep(2000);
			break;
		}
	}
	if (strcmp(student.name, student11.name) != 0 || strcmp(student11.password, student.password) != 0)
	{
		gotoxy(50, 13);
		Sleep(2000);
		gotoxy(50, 13);
		printf("��¼ʧ�ܣ���˶�����������");
		Sleep(2000);
		gotoxy(50, 14);
		exit(0);
	}
	fclose(fp2);
}

void sign_up()		//ע��
{
	int select;
	system("cls");
	menu5();
	gotoxy(59, 15);
	scanf("%d", &select);
	system("cls");
	switch (select)
	{
	case 1:								//��ʦע��
		teawritefile();	//�ɹ���ʼע��
		system("cls");
		menu6();		//ע��ɹ����Ƿ��¼
		gotoxy(59, 15);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			sign_in();					//�ص���¼����
			break;
		case 0:
			gotoxy(59, 15);
			break;
		default:
			gotoxy(56, 17);
			printf("�������");
			Sleep(2000);
			system("cls");
			gotoxy(53, 16);
			exit(0);
		}
		break;
	case 2:								//ѧ��ע��
		stuwritefile();
		system("cls");
		menu6();		//ע��ɹ����Ƿ��¼
		gotoxy(59, 15);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			sign_in();					//�ص���¼����
			break;
		case 0:
			gotoxy(59, 15);
			exit(0);
		default:
			gotoxy(59, 13);
			printf("��Ч����\n");
			break;
		}
		break;
	case 0:
		gotoxy(59, 15);
		break;
	default:
		gotoxy(56, 17);
		printf("�������");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
}
void sign_in()//��¼
{
	int select;
	system("cls");
	menu4();
	gotoxy(59, 15);
	scanf("%d", &select);
	switch (select)
	{
	case 1:							//��ʦ��¼
		system("cls");
		teareadfile();
		system("cls");
		menu2();
		caozuo1();
		break;
	case 2:							//ѧ����¼
		system("cls");
		stureadfile();
		system("cls");
		menu3();
		caozuo2();
		break;
	case 0:
		gotoxy(53, 16);
		exit(0);
		break;
	default:
		gotoxy(56, 17);
		printf("�������");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
}

int main()
{
	int select;
	menu1();
	gotoxy(59, 15);
	scanf("%d", &select);
	switch (select)
	{
	case 1:
		sign_in();	//��¼
		break;
	case 2:
		sign_up();	//ע��
		break;
	default:
		gotoxy(56, 17);
		printf("�������");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
	return 0;
}