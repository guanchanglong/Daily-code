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
//获取光标的位置x
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
	return (pBuffer.dwCursorPosition.X + 1);
}
//获取光标的位置y
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
	return (pBuffer.dwCursorPosition.Y + 1);
}
//设置光标的位置
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
	int x, y;
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
	x = wherex();
	y = wherey();
}
void menu3()//学生登录后菜单
{
	int x, y;
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
	x = wherex();
	y = wherey();
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
				printf("恭喜您注册成功!");
				Sleep(2000);//延时作用，停留在这个页面2秒
				break;//退出循环
		}
		else if (n == 0)
		{
			gotoxy(48, 15);
			exit(0);
		}
	}
}
void readfile(FILE *fp)//密码读取
{
	tea teacher;
	tea teacher1;
	while (1)
	{
		rewind(fp);
		gotoxy(40, 10);
		printf("请输入教师姓名：");
		gotoxy(40, 12);
		printf("请输入密码(十位以内)：");
		gotoxy(62, 10);
		scanf("%s", teacher1.name);//输入用户名
		gotoxy(62, 12);
		scanf("%lld", teacher1.password);//输入密码                                         此处开始有问题
		gotoxy(53, 13);
		printf("登录中，请稍等.....");
		Sleep(2000);
		system("cls");
		while (fscanf(fp, "%s %lld", teacher.name, &teacher.password) != EOF)
		{
			printf("%s %lld", teacher.name, &teacher.password);

			//if (teacher1.name == teacher.name&&teacher1.password == teacher.password)//读取密码
			//{
			//	gotoxy(53, 13);
			//	printf("登录成功!");
			//	Sleep(2000);
			//	break;
			//}
		}
		if (teacher1.name != teacher.name&&teacher1.password != teacher.password)
		{
			gotoxy(50, 13);
			printf("登录失败，请核对姓名或密码");
		}
	}
}

void sign_up()		//注册
{
	int select;
	system("cls");
	menu5();
	gotoxy(59, 15);
	scanf("%d", &select);
	system("cls");
	if (select == 1)//教师注册
	{
		FILE *fp;
		char filename[] = "D:\\Visual Studio 2013\\Projects\\学生管理系统1.3\\教师注册资料.txt";
		fp = fopen(filename, "r+");//以追加的方式打开文件
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
		if (select == 1)//登录
		{
			readfile(fp);//密码读取
		}
		else if(select==0)           //退出
		{
			gotoxy(59, 15);
		}
		else
		{
			gotoxy(59, 13);
			printf("无效输入\n");
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
void sign_in()//登录
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
		sign_in();	//登录
	}
	else if (select == 2)
	{
		sign_up();	//注册
	}
	else
	{
		gotoxy(59, 15);//退出时光标位置
	}
	return 0;
}







