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
	char password[12];
	struct student *next;
}stu;

FILE *fp1,*fp2,*fp3;
char filename1[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\��ʦע������.txt";
char filename2[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\ѧ��ע������.txt";
char filename3[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\ѧ���ɼ�.txt";

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
	printf("* 5 ����				6 ͳ�� *");
	gotoxy(40, 13);
	printf("* 7 ����				8 ���� *");
	gotoxy(40, 14);
	printf("* 9 ��ʾ				0 �˳� *");
	gotoxy(40, 15);
	printf("*******************************************");
	gotoxy(40, 16);
	//printf("���������ѡ��(0-9): ");
}
void menu3()//ѧ����¼��˵�
{
	gotoxy(53, 7);
	printf(" ѧ������ϵͳ");
	gotoxy(40, 9);
	printf("******************�˵�*********************");
	gotoxy(40, 10);
	printf("* 1 ����				2 ͳ�� *");
	gotoxy(40, 11);
	printf("* 3 ����				4 �˳� *");
	gotoxy(40, 15);
	printf("*******************************************");
	gotoxy(40, 16);
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
	stu student;
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
		system("cls");
		gotoxy(48, 15);
		Sleep(2000);
		gotoxy(48, 15);
		printf("����ɹ�!");
		Sleep(3000);
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
		//gotoxy(35, 8);
		//printf("��ѧ��Ϊ000����");
		while (strcmp("000", p->num) != 0)
		{
			p = (stu*)malloc(sizeof(stu));
			system("cls");
			gotoxy(48, 8);
			printf("��ѧ��Ϊ000����");
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

stu *del(stu*head, char num[],char name[],char sex[])//ɾ������ڵ�
{
	stu *p1, *p2;
	p2 = NULL;
	if (head == NULL)//������ǿ�����
	{
		gotoxy(56, 17);
		printf("���ݿ�����ѧ������");
		return head;
	}
	p1 = head;
	while (strcmp(p1->num,num)!=0 &&strcmp(p1->name,name)!=0 &&strcmp(p1->sex,sex)!=0 && p1->next != NULL)//��������Ѱ��Ŀ��ֵ						///�����bug��
	{
		p2 = p1;
		p1 = p2->next;
	}
	if (strcmp(p1->num,num)==0 && strcmp(p1->name,name)==0 && strcmp(p1->sex,sex)==0)
	{
		if (p1 == head)//Ŀ��ڵ�Ϊͷ�ڵ�
		{
			head = p1->next;
			gotoxy(53, 16);
			printf("ɾ���ɹ�");
			gotoxy(50, 17);
		}
		else
		{
			p2->next = p1->next;
			gotoxy(53, 16);
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

void caozuo()				//��ɾ�Ĳ�
{
	int n;
	gotoxy(59, 16);
	scanf("%d", &n);
	switch (n)
	{
	case 1:					//����
		create();
		gotoxy(53, 16);
		break;
	case 2:					//ɾ��
		stu *head,student;
		head = createlink();										//���ļ��������ת��һ��������
		system("cls");
		gotoxy(35, 9);
		printf("��������ɾ����ѧ��ѧ�ţ�");
		gotoxy(35, 10);
		printf("��������ɾ����ѧ��������");
		gotoxy(35, 11);
		printf("��������ɾ����ѧ���Ա�");
		gotoxy(62, 9);
		scanf("%s", student.num);
		gotoxy(62, 10);
		scanf("%s", student.name);
		gotoxy(62, 11);
		scanf("%s", student.sex);
		head=del(head, student.num, student.name, student.sex);		//ɾ���������и�ѧ���Ľڵ�
		save(head);													//��ɾ����ĵ������浽�ļ���
		break;
	case 3:					//�޸�
		break;
	case 4:					//����
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 0:
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
	int n;
	gotoxy(40, 9);
	printf("�������ʦ���ţ�");
	gotoxy(40, 10);
	printf("�������ʦ������");
	gotoxy(40, 11);
	printf("�������ʦ�Ա�");
	gotoxy(40, 12);
	printf("���Զ������룺");
	gotoxy(40, 13);
	printf("0 �˳�\\1 ������");
	gotoxy(62, 9);
	scanf("%s", teacher1.num);
	gotoxy(62, 10);
	scanf("%s", teacher1.name);
	gotoxy(62, 11);
	scanf("%s", teacher1.sex);
	gotoxy(62, 12);
	scanf("%s", teacher1.password);
	gotoxy(62, 13);
	scanf("%d", &n);
	switch (n)
	{
	case 1:
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
			gotoxy(48, 16);
			exit(0);
		}
		else if (strcmp(teacher.name, teacher1.name) != 0 && strcmp(teacher1.num, teacher.num) != 0 && strcmp(teacher1.sex, teacher.sex) != 0)
		{
			fprintf(fp1, "%s %s %s %s\n", teacher1.num, teacher1.name, teacher1.sex, teacher1.password);
			gotoxy(48, 15);
			printf("��ϲ��ע��ɹ�!");
			Sleep(2000);//��ʱ���ã�ͣ�������ҳ��2��
		}
		break;
	case 0:
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
			gotoxy(50, 14);
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
	int n;
	gotoxy(40, 9);
	printf("������ѧ��ѧ�ţ�");
	gotoxy(40, 10);
	printf("������ѧ��������");
	gotoxy(40, 11);
	printf("������ѧ���Ա�");
	gotoxy(40, 12);
	printf("���Զ�������(ʮλ����)��");
	gotoxy(40, 13);
	printf("0 �˳�\\1 ������");
	gotoxy(63, 9);
	scanf("%s", student1.num);
	gotoxy(63, 10);
	scanf("%s", student1.name);
	gotoxy(63, 11);
	scanf("%s", student1.sex);
	gotoxy(63, 12);
	scanf("%s", student1.password);
	gotoxy(63, 13);
	scanf("%d", &n);
	switch (n)
	{
	case 1:
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
		else if (strcmp(student.name, student1.name) != 0 && strcmp(student1.num, student.num) != 0 && strcmp(student1.sex, student.sex) != 0)
		{
			fprintf(fp2, "%s %s %s %s\n", student1.num, student1.name, student1.sex, student1.password);
			gotoxy(48, 15);
			printf("��ϲ��ע��ɹ�!");
			Sleep(2000);//��ʱ���ã�ͣ�������ҳ��2��
			break;//�˳�ѭ��
		}
		break;
	case 0:
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
	fclose(fp2);
}
void stureadfile()//ѧ�������ȡ
{
	stu student;
	stu student1;
	fp2 = fopen(filename2, "a+");
	gotoxy(40, 10);
	printf("������ѧ��������");
	gotoxy(40, 12);
	printf("����������(ʮλ����)��");
	gotoxy(62, 10);
	scanf("%s", student1.name);//�����û���
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
			student1.password[j] = a[j];
		}
	}
	student1.password[j] = '\0';
	gotoxy(53, 13);
	printf("��¼�У����Ե�.....");
	Sleep(2000);
	system("cls");
	while (fscanf(fp2, "%s %s %s %s\n", student.num, student.name, student.sex, student.password) != EOF)
	{
		if (strcmp(student.name, student1.name) == 0 && strcmp(student1.password, student.password) == 0)//��ȡ����
		{
			gotoxy(53, 13);
			printf("��¼�ɹ�!");
			Sleep(2000);
			break;
		}
	}
	if (strcmp(student.name, student1.name) != 0 || strcmp(student1.password, student.password) != 0)
	{
		gotoxy(50, 13);
		Sleep(2000);
		gotoxy(50, 13);
		printf("��¼ʧ�ܣ���˶�����������");
		gotoxy(50, 14);
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
		caozuo();
		break;
	case 2:							//ѧ����¼
		system("cls");
		stureadfile();
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