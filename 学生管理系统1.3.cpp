#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <windows.h>
#include<time.h>
typedef struct teacher
{
	long long num;
	char name[10];
	char sex[5];
	long long password;
	struct teacher *next;
}tea;
typedef struct student
{
	int num;
	char name[10];
	char sex[5];
	struct student *next;
}stu;
//��ȡ����λ��x
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
	return (pBuffer.dwCursorPosition.X + 1);
}
//��ȡ����λ��y
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
	return (pBuffer.dwCursorPosition.Y + 1);
}
//���ù���λ��
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
	int x, y;
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
	x = wherex();
	y = wherey();
}
void menu3()//ѧ����¼��˵�
{
	int x, y;
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
	x = wherex();
	y = wherey();
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
void writefile(FILE *fp)//�趨����
{
	tea teacher;
	int n;
	while (1)
	{
		gotoxy(40, 9);
		printf("�������ʦ���ţ�");
		gotoxy(40, 10);
		printf("�������ʦ������");
		gotoxy(40, 11);
		printf("�������ʦ�Ա�");
		gotoxy(40, 12);
		printf("�붨�����룺");
		gotoxy(40, 13);
		printf("0 �˳�\\1 ������");
		gotoxy(62, 9);
		scanf("%lld", &teacher.num);
		gotoxy(62, 10);
		scanf("%s", teacher.name);
		gotoxy(62, 11);
		scanf("%s", teacher.sex);
		gotoxy(62, 12);
		scanf("%lld", &teacher.password);
		gotoxy(62, 13);
		scanf("%d", &n);
		if (n == 1)
		{
				fprintf(fp, "%lld %s %s %lld", &teacher.num, teacher.name, teacher.sex, &teacher.password);
				gotoxy(53, 15);
				printf("��ϲ��ע��ɹ�!");
				Sleep(2000);//��ʱ���ã�ͣ�������ҳ��2��
				break;//�˳�ѭ��
		}
		else if (n == 0)
		{
			gotoxy(48, 15);
			exit(0);
		}
	}
}
void readfile(FILE *fp)//�����ȡ
{
	tea teacher;
	tea teacher1;
	while (1)
	{
		rewind(fp);
		gotoxy(40, 10);
		printf("�������ʦ������");
		gotoxy(40, 12);
		printf("����������(ʮλ����)��");
		gotoxy(62, 10);
		scanf("%s", teacher1.name);//�����û���
		gotoxy(62, 12);
		scanf("%lld", teacher1.password);//��������                                         �˴���ʼ������
		gotoxy(53, 13);
		printf("��¼�У����Ե�.....");
		Sleep(2000);
		system("cls");
		while (fscanf(fp, "%s %lld", teacher.name, &teacher.password) != EOF)
		{
			printf("%s %lld", teacher.name, &teacher.password);

			//if (teacher1.name == teacher.name&&teacher1.password == teacher.password)//��ȡ����
			//{
			//	gotoxy(53, 13);
			//	printf("��¼�ɹ�!");
			//	Sleep(2000);
			//	break;
			//}
		}
		if (teacher1.name != teacher.name&&teacher1.password != teacher.password)
		{
			gotoxy(50, 13);
			printf("��¼ʧ�ܣ���˶�����������");
		}
	}
}

void sign_up()		//ע��
{
	int select;
	system("cls");
	menu5();
	gotoxy(59, 15);
	scanf("%d", &select);
	system("cls");
	if (select == 1)//��ʦע��
	{
		FILE *fp;
		char filename[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\��ʦע������.txt";
		fp = fopen(filename, "r+");//��׷�ӵķ�ʽ���ļ�
		if (fp == NULL)
		{
			printf("ע��ʧ��\n");
			exit(1);
		}
		writefile(fp);	//�ɹ���ʼע��
		system("cls");
		menu6();		//ע��ɹ���
		gotoxy(59, 15);
		scanf("%d", &select);
		system("cls");
		if (select == 1)//��¼
		{
			readfile(fp);//�����ȡ
		}
		else if(select==0)           //�˳�
		{
			gotoxy(59, 15);
		}
		else
		{
			gotoxy(59, 13);
			printf("��Ч����\n");
		}
	}
	else if (select == 2)
	{

	}
	else
	{
		gotoxy(59, 15);
	}
}
void sign_in()//��¼
{
	int select;
	system("cls");
	menu4();
	gotoxy(59, 15);
	scanf("%d", &select);
	if (select == 1)
	{

	}
	else if (select == 2)
	{

	}
	else
	{
		gotoxy(59, 15);
	}
}
int main()
{
	int select;
	menu1();
	gotoxy(59, 15);
	scanf("%d", &select);
	if (select == 1)
	{
		sign_in();	//��¼
	}
	else if (select == 2)
	{
		sign_up();	//ע��
	}
	else
	{
		gotoxy(59, 15);//�˳�ʱ���λ��
	}
	return 0;
}







