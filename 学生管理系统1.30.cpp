#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <windows.h>
#include<time.h>
#include<string.h>
typedef struct teacher
{
	char num[20];
	char name[10];
	char sex[5];
	char password[20];
	struct teacher *next;
}tea;
typedef struct student
{
	int num;
	char name[10];
	char sex[5];
	struct student *next;
}stu;
FILE *fp;
char filename1[] = "D:\\Visual Studio 2013\\Projects\\ѧ������ϵͳ1.3\\��ʦע������.txt";
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
void writefile(FILE *fp)//�趨����
{
	tea teacher;
	tea teacher1;
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
			while (fscanf(fp, "%s %s %s %s\n", teacher.num, teacher.name, teacher.sex, teacher.password) != EOF)
			{
				if (strcmp(teacher.name, teacher1.name) == 0 && strcmp(teacher1.num, teacher.num) == 0 && strcmp(teacher1.sex, teacher.sex) == 0)//�ж��Ƿ��ظ�ע��
				{
					gotoxy(53, 15);
					printf("���û��Ѵ��ڣ�");
					gotoxy(50, 16);
					printf("��������ȷ���û����ϣ�");
					Sleep(2000);
					system("cls");
				}
			}
			if (strcmp(teacher.name, teacher1.name) != 0 && strcmp(teacher1.password, teacher.password) != 0)
			{
				fprintf(fp, "%s %s %s %s\n", teacher1.num, teacher1.name, teacher1.sex, teacher1.password);
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
		fclose(fp);
	}
}
void readfile(FILE *fp)//�����ȡ
{
	tea teacher;
	tea teacher1;
	/*while (1)
	{*/
		fp = fopen(filename1, "a+");
		gotoxy(40, 10);	
		printf("�������ʦ������");
		gotoxy(40, 12);
		printf("����������(ʮλ����)��");
		gotoxy(62, 10);
		scanf("%s", teacher1.name);//�����û���
		gotoxy(62, 12);
		scanf("%s", teacher1.password);//�������� 
		gotoxy(53, 13);
		printf("��¼�У����Ե�.....");
		Sleep(2000);
		system("cls");
		while (fscanf(fp, "%s %s %s %s\n", teacher.num,teacher.name,teacher.sex, teacher.password) != EOF)
		{
			printf("%s %s %s %s\n", teacher.num, teacher.name, teacher.sex, teacher.password);
			if (strcmp(teacher.name,teacher1.name)==0 && strcmp(teacher1.password,teacher.password)==0)//��ȡ����
			{
				gotoxy(53, 13);
				printf("��¼�ɹ�!");
				Sleep(2000);
				break;
			}
		}
		if (strcmp(teacher.name, teacher1.name) != 0 && strcmp(teacher1.password, teacher.password) != 0)
		{
			//system("cls");
			Sleep(2000);
			gotoxy(50, 13);
			printf("��¼ʧ�ܣ���˶�����������");
		}
		fclose(fp);
	//}
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
	case 1:							//��ʦע��
		fp = fopen(filename1, "a+");//��׷�ӵķ�ʽ���ļ�
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
		switch (select)
		{
		case 1:
			readfile(fp);//�����ȡ
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
	case 2:

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
	case 1:

		break;
	case 2:

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







