#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#define	_CRT_NONSTDC_NO_DEPRECATE 0
#include <stdio.h>
#include <windows.h>
#include<time.h>
#include<string.h>
#include<conio.h>
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
	char password[12];
	struct student *next;
}stu;

FILE *fp1,*fp2;
char filename1[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\��ʦע������.txt";
char filename2[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\ѧ��ע������.txt";

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
	printf("* 1 ����				2 ɾ�� *");
	gotoxy(40, 11);
	printf("* 3 ����				4 �޸� *");
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
			gotoxy(59, 15);
			break;
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
		gotoxy(59, 15);
		break;
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
			teareadfile();				//��ʦ�����ȡ
			break;
		case 0:
			gotoxy(59, 15);
			break;
		default:
			gotoxy(59, 13);
			printf("��Ч����\n");
			break;
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
			stureadfile();				//ѧ�������ȡ
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
		gotoxy(59, 15);
		break;
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
		break;
	case 2:							//ѧ����¼
		system("cls");
		stureadfile();
		break;
	default:
		gotoxy(59, 15);
		break;
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
		gotoxy(59, 15);//�˳�ʱ���λ��
		break;
	}
	return 0;
}







