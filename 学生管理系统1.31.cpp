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
char filename1[] = "D:\\Visual Studio 2013\\Projects\\学生管理系统1.3\\教师注册资料.txt";
char filename2[] = "D:\\Visual Studio 2013\\Projects\\学生管理系统1.3\\学生注册资料.txt";

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
	printf(" 学生管理系统");
	gotoxy(40, 10);
	printf("******************菜单*********************");
	gotoxy(40, 11);
	printf("*               1 登录                    *");
	gotoxy(40, 12);
	printf("*               2 注册                    *");
	gotoxy(40, 13);
	printf("*               0 退出                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu2()//教师登录后菜单
{
	gotoxy(53, 7);
	printf(" 学生管理系统");
	gotoxy(40, 9);
	printf("******************菜单*********************");
	gotoxy(40, 10);
	printf("* 1 输入				2 删除 *");
	gotoxy(40, 11);
	printf("* 3 查找				4 修改 *");
	gotoxy(40, 12);
	printf("* 5 插入				6 统计 *");
	gotoxy(40, 13);
	printf("* 7 排序				8 保存 *");
	gotoxy(40, 14);
	printf("* 9 显示				0 退出 *");
	gotoxy(40, 15);
	printf("*******************************************");
	gotoxy(40, 16);
	//printf("请输入你的选择(0-9): ");
}
void menu3()//学生登录后菜单
{
	gotoxy(53, 7);
	printf(" 学生管理系统");
	gotoxy(40, 9);
	printf("******************菜单*********************");
	gotoxy(40, 10);
	printf("* 1 查找				2 统计 *");
	gotoxy(40, 11);
	printf("* 3 排序				4 退出 *");
	gotoxy(40, 15);
	printf("*******************************************");
	gotoxy(40, 16);
}
void menu4()//登录菜单
{
	gotoxy(53, 8);
	printf(" 学生管理系统");
	gotoxy(40, 10);
	printf("******************菜单*********************");
	gotoxy(40, 11);
	printf("*             1 教师登录                  *");
	gotoxy(40, 12);
	printf("*             2 学生登录                  *");
	gotoxy(40, 13);
	printf("*               0 退出                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu5()//注册菜单
{
	gotoxy(53, 8);
	printf(" 学生管理系统");
	gotoxy(40, 10);
	printf("******************菜单*********************");
	gotoxy(40, 11);
	printf("*             1 教师注册                  *");
	gotoxy(40, 12);
	printf("*             2 学生注册                  *");
	gotoxy(40, 13);
	printf("*               0 退出                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu6()//注册成功后的登录菜单
{
	gotoxy(53, 8);
	printf(" 学生管理系统");
	gotoxy(40, 10);
	printf("******************菜单*********************");
	gotoxy(40, 11);
	printf("*               1 登录                    *");
	gotoxy(40, 12);
	printf("*                                         *");
	gotoxy(40, 13);
	printf("*               0 退出                    *");
	gotoxy(40, 14);
	printf("*******************************************");
}



void teawritefile()//教师设定密码
{
	fp1 = fopen(filename1, "a+");//以追加的方式打开文件
	if (fp1 == NULL)
	{
		printf("注册失败\n");
		gotoxy(48, 15);
		exit(1);
	}
	tea teacher;
	tea teacher1;
	int n;
		gotoxy(40, 9);
		printf("请输入教师工号：");
		gotoxy(40, 10);
		printf("请输入教师姓名：");
		gotoxy(40, 11);
		printf("请输入教师性别：");
		gotoxy(40, 12);
		printf("请自定义密码：");
		gotoxy(40, 13);
		printf("0 退出\\1 继续：");
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
				if (strcmp(teacher.name, teacher1.name) == 0 && strcmp(teacher1.num, teacher.num) == 0 && strcmp(teacher1.sex, teacher.sex) == 0)//判断是否重复注册
				{
					gotoxy(53, 15);
					printf("该用户已存在！");
					gotoxy(50, 16);
					printf("请输入正确的用户资料！");
					Sleep(2000);
					system("cls");
					gotoxy(48, 15);
					exit(0);
				}
			}
			if (strlen(teacher1.password) > 11)					//strlen函数可以计算字符串 str 的长度，直到空结束字符，但不包括空结束字符。
			{
				gotoxy(42, 15);
				printf("密码过长，请输入长度适宜的密码的！");
				gotoxy(48, 16);
				exit(0);
			}
			else if (strcmp(teacher.name, teacher1.name) != 0 && strcmp(teacher1.num, teacher.num) != 0 && strcmp(teacher1.sex, teacher.sex) != 0)
			{
				fprintf(fp1, "%s %s %s %s\n", teacher1.num, teacher1.name, teacher1.sex, teacher1.password);
				gotoxy(48, 15);
				printf("恭喜您注册成功!");
				Sleep(2000);//延时作用，停留在这个页面2秒
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
void teareadfile()//教师密码读取
{
	tea teacher;
	tea teacher1;
		fp1 = fopen(filename1, "a+");
		gotoxy(40, 10);	
		printf("请输入教师姓名：");
		gotoxy(40, 12);
		printf("请输入密码(十位以内)：");
		gotoxy(62, 10);
		scanf("%s", teacher1.name);//输入用户名
		char a[11];
		int i = 0;
		gotoxy(62, 12);
		for (i = 0; i < 11; i++)
		{
			gotoxy(62+i, 12);
			a[i] = getch();					//getch函数用途：从控制台读取一个字符，但不显示在屏幕上，可以用来实现密码的读取的作用
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
		teacher1.password[j] = '\0';		//如果不到11位的话，就以\0结束
		gotoxy(53, 13);
		printf("登录中，请稍等.....");
		Sleep(2000);
		system("cls");
		while (fscanf(fp1, "%s %s %s %s\n", teacher.num,teacher.name,teacher.sex, teacher.password) != EOF)
		{
			if (strcmp(teacher.name,teacher1.name)==0 && strcmp(teacher1.password,teacher.password)==0)//读取密码
			{
				gotoxy(53, 13);
				printf("登录成功!");
				Sleep(2000);
				break;
			}
		}
		if (strcmp(teacher.name, teacher1.name) != 0 || strcmp(teacher1.password, teacher.password) != 0)
		{
			gotoxy(50, 13);
			Sleep(2000);
			gotoxy(50, 13);
			printf("登录失败，请核对姓名或密码");
			gotoxy(50, 14);
		}
		fclose(fp1);
}



void stuwritefile()//学生设定密码
{
	fp2 = fopen(filename2, "a+");//以追加的方式打开文件
	if (fp2 == NULL)
	{
		gotoxy(48, 15);
		printf("注册失败\n");
		gotoxy(48, 15);
		exit(1);
	}
	stu student;
	stu student1;
	int n;
	gotoxy(40, 9);
	printf("请输入学生学号：");
	gotoxy(40, 10);
	printf("请输入学生姓名：");
	gotoxy(40, 11);
	printf("请输入学生性别：");
	gotoxy(40, 12);
	printf("请自定义密码(十位以内)：");
	gotoxy(40, 13);
	printf("0 退出\\1 继续：");
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
			if (strcmp(student.name, student1.name) == 0 && strcmp(student1.num, student.num) == 0 && strcmp(student1.sex, student.sex) == 0)//判断是否重复注册
			{
				gotoxy(53, 15);
				printf("该用户已存在！");
				gotoxy(50, 16);
				printf("请输入正确的用户资料！");
				Sleep(2000);
				system("cls");
				gotoxy(48, 15);
				exit(0);
			}
		}
		if (strlen(student1.password) > 11)
		{
			gotoxy(42, 15);
			printf("密码过长，请输入长度适宜的密码的！");
			gotoxy(48, 16);
			exit(0);
		}
		else if (strcmp(student.name, student1.name) != 0 && strcmp(student1.num, student.num) != 0 && strcmp(student1.sex, student.sex) != 0)
		{
			fprintf(fp2, "%s %s %s %s\n", student1.num, student1.name, student1.sex, student1.password);
			gotoxy(48, 15);
			printf("恭喜您注册成功!");
			Sleep(2000);//延时作用，停留在这个页面2秒
			break;//退出循环
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
void stureadfile()//学生密码读取
{
	stu student;
	stu student1;
	fp2 = fopen(filename2, "a+");
	gotoxy(40, 10);
	printf("请输入学生姓名：");
	gotoxy(40, 12);
	printf("请输入密码(十位以内)：");
	gotoxy(62, 10);
	scanf("%s", student1.name);//输入用户名
	char a[11];
	int i = 0;
	gotoxy(62, 12);
	for (i = 0; i < 11; i++)
	{
		gotoxy(62 + i, 12);
		a[i] = getch();				//getch函数用途：从控制台读取一个字符，但不显示在屏幕上，可以用来实现密码的读取的作用
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
	printf("登录中，请稍等.....");
	Sleep(2000);
	system("cls");
	while (fscanf(fp2, "%s %s %s %s\n", student.num, student.name, student.sex, student.password) != EOF)
	{
		if (strcmp(student.name, student1.name) == 0 && strcmp(student1.password, student.password) == 0)//读取密码
		{
			gotoxy(53, 13);
			printf("登录成功!");
			Sleep(2000);
			break;
		}
	}
	if (strcmp(student.name, student1.name) != 0 || strcmp(student1.password, student.password) != 0)
	{
		gotoxy(50, 13);
		Sleep(2000);
		gotoxy(50, 13);
		printf("登录失败，请核对姓名或密码");
		gotoxy(50, 14);
	}
	fclose(fp2);
}



void sign_up()		//注册
{
	int select;
	system("cls");
	menu5();
	gotoxy(59, 15);
	scanf("%d", &select);
	system("cls");
	switch (select)
	{
	case 1:								//教师注册
		teawritefile();	//成功开始注册
		system("cls");
		menu6();		//注册成功后是否登录
		gotoxy(59, 15);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			teareadfile();				//教师密码读取
			break;
		case 0:
			gotoxy(59, 15);
			break;
		default:
			gotoxy(59, 13);
			printf("无效输入\n");
			break;
		}
		break;
	case 2:								//学生注册
		stuwritefile();
		system("cls");
		menu6();		//注册成功后是否登录
		gotoxy(59, 15);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			stureadfile();				//学生密码读取
			break;
		case 0:
			gotoxy(59, 15);
			exit(0);
		default:
			gotoxy(59, 13);
			printf("无效输入\n");
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
void sign_in()//登录
{
	int select;
	system("cls");
	menu4();
	gotoxy(59, 15);
	scanf("%d", &select);
	switch (select)
	{
	case 1:							//教师登录
		system("cls");
		teareadfile();
		break;
	case 2:							//学生登录
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
		sign_in();	//登录
		break;
	case 2:
		sign_up();	//注册
		break;
	default:
		gotoxy(59, 15);//退出时光标位置
		break;
	}
	return 0;
}







