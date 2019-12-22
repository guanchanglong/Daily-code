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
char filename1[] = "D:\\Visual Studio 2013\\Projects\\学生管理系统1.3\\教师注册资料.txt";
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
void writefile(FILE *fp)//设定密码
{
	tea teacher;
	tea teacher1;
	int n;
	while (1)
	{
		gotoxy(40, 9);
		printf("请输入教师工号：");
		gotoxy(40, 10);
		printf("请输入教师姓名：");
		gotoxy(40, 11);
		printf("请输入教师性别：");
		gotoxy(40, 12);
		printf("请定义密码：");
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
			while (fscanf(fp, "%s %s %s %s\n", teacher.num, teacher.name, teacher.sex, teacher.password) != EOF)
			{
				if (strcmp(teacher.name, teacher1.name) == 0 && strcmp(teacher1.num, teacher.num) == 0 && strcmp(teacher1.sex, teacher.sex) == 0)//判断是否重复注册
				{
					gotoxy(53, 15);
					printf("该用户已存在！");
					gotoxy(50, 16);
					printf("请输入正确的用户资料！");
					Sleep(2000);
					system("cls");
				}
			}
			if (strcmp(teacher.name, teacher1.name) != 0 && strcmp(teacher1.password, teacher.password) != 0)
			{
				fprintf(fp, "%s %s %s %s\n", teacher1.num, teacher1.name, teacher1.sex, teacher1.password);
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
		fclose(fp);
	}
}
void readfile(FILE *fp)//密码读取
{
	tea teacher;
	tea teacher1;
	/*while (1)
	{*/
		fp = fopen(filename1, "a+");
		gotoxy(40, 10);	
		printf("请输入教师姓名：");
		gotoxy(40, 12);
		printf("请输入密码(十位以内)：");
		gotoxy(62, 10);
		scanf("%s", teacher1.name);//输入用户名
		gotoxy(62, 12);
		scanf("%s", teacher1.password);//输入密码 
		gotoxy(53, 13);
		printf("登录中，请稍等.....");
		Sleep(2000);
		system("cls");
		while (fscanf(fp, "%s %s %s %s\n", teacher.num,teacher.name,teacher.sex, teacher.password) != EOF)
		{
			printf("%s %s %s %s\n", teacher.num, teacher.name, teacher.sex, teacher.password);
			if (strcmp(teacher.name,teacher1.name)==0 && strcmp(teacher1.password,teacher.password)==0)//读取密码
			{
				gotoxy(53, 13);
				printf("登录成功!");
				Sleep(2000);
				break;
			}
		}
		if (strcmp(teacher.name, teacher1.name) != 0 && strcmp(teacher1.password, teacher.password) != 0)
		{
			//system("cls");
			Sleep(2000);
			gotoxy(50, 13);
			printf("登录失败，请核对姓名或密码");
		}
		fclose(fp);
	//}
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
	case 1:							//教师注册
		fp = fopen(filename1, "a+");//以追加的方式打开文件
		if (fp == NULL)
		{
			printf("注册失败\n");
			exit(1);
		}
		writefile(fp);	//成功开始注册
		system("cls");
		menu6();		//注册成功后
		gotoxy(59, 15);
		scanf("%d", &select);
		system("cls");
		switch (select)
		{
		case 1:
			readfile(fp);//密码读取
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
void sign_in()//登录
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







