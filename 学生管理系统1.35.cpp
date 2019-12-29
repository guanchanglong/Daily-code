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
char filename1[] = "D:\\Visual Studio 2013\\Projects\\学生管理系统1.3\\教师注册资料.txt";
char filename2[] = "D:\\Visual Studio 2013\\Projects\\学生管理系统1.3\\学生注册资料.txt";
char filename3[] = "D:\\Visual Studio 2013\\Projects\\学生管理系统1.3\\学生成绩.txt";

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
	printf("* 1 添加				2 删除 *");
	gotoxy(40, 11);
	printf("* 3 修改				4 查找 *");
	gotoxy(40, 12);
	printf("* 5 查看				6 统计 *");
	gotoxy(40, 13);
	printf("* 7 排序				0 退出 *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu3()//学生登录后菜单
{
	gotoxy(53, 7);
	printf(" 学生管理系统");
	gotoxy(40, 9);
	printf("******************菜单*********************");
	gotoxy(40, 10);
	printf("*                1 查找                   *");
	gotoxy(40, 11);
	printf("*                2 统计                   *");
	gotoxy(40, 12);
	printf("*                0 退出                   *");
	gotoxy(40, 13);
	printf("*******************************************");
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
void menu7()
{
	gotoxy(53, 6);
	printf(" 学生管理系统");
	gotoxy(35, 9);
	printf("请输入学生学号：");
	gotoxy(35, 10);
	printf("请输入学生姓名：");
	gotoxy(35, 11);
	printf("请输入学生性别：");
	gotoxy(35, 12);
	printf("请输入学生成绩:");
	gotoxy(35, 14);
	printf("语文：	数学：		英语：");
}
void menu8()
{
	gotoxy(53, 8);
	printf(" 学生管理系统");
	gotoxy(40, 10);
	printf("******************菜单*********************");
	gotoxy(40, 11);
	printf("*            1 按学号查找                 *");
	gotoxy(40, 12);
	printf("*            2 按姓名查找                 *");
	gotoxy(40, 13);
	printf("*            3 按性别查找                 *");
	gotoxy(40, 14);
	printf("*******************************************");
}
void menu9()
{
	gotoxy(53, 8);
	printf(" 学生管理系统");
	gotoxy(40, 10);
	printf("******************菜单*********************");
	gotoxy(40, 11);
	printf("*            1 语文平均分                 *");
	gotoxy(40, 12);
	printf("*            2 数学平均分                 *");
	gotoxy(40, 13);
	printf("*            3 英语平均分                 *");
	gotoxy(40, 14);
	printf("*        4 全部学生三科平均分             *");
	gotoxy(40, 15);
	printf("*               0 退出                    *");
	gotoxy(40, 16);
	printf("*******************************************");
}

stu *createlink(void)								//将文件里的信息转换到链表里
{
	fp3 = fopen(filename3, "a+");
	stu *p, *q, *head;
	stu student;
	p = q = (stu*)malloc(sizeof(stu));
	head = p;
	while (fscanf(fp3, "%s %s %s %d %d %d", student.num, student.name, student.sex, &student.yu, &student.shu, &student.ying) != EOF)
	{
		p = (stu*)malloc(sizeof(stu));
		strcpy(p->num, student.num);			//strcpy函数可以复制一个字符数组里的内容到另一个字符数组里
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

stu *del(stu*head, char num[], char name[])//删除链表节点
{
	stu *p1, *p2;
	p2 = NULL;
	if (head == NULL)//传入的是空链表
	{
		gotoxy(56, 15);
		printf("数据库里无学生数据");
		return head;
	}
	p1 = head;
	while (strcmp(p1->num, num) != 0 && strcmp(p1->name, name) != 0 && p1->next != NULL)//遍历链表寻找目标值
	{
		p2 = p1;
		p1 = p2->next;
	}
	if (strcmp(p1->num, num) == 0 && strcmp(p1->name, name) == 0)
	{
		if (p1 == head)//目标节点为头节点
		{
			head = p1->next;
			gotoxy(48, 15);
			printf("删除成功！！");
			gotoxy(50, 17);
		}
		else
		{
			p2->next = p1->next;
			gotoxy(53, 15);
			printf("删除成功");
			gotoxy(50, 17);
		}
	}
	else
	{
		gotoxy(51, 15);
		printf("无该学生");
		gotoxy(53, 16);
	}
	return head;
}

stu *save(stu*head)																//链表的保存
{
	fp3 = fopen(filename3, "w+");												//以w+的方式打开文件，将文件里原来的内容清空，写入新的内容
	while (head->next != NULL)
	{
		head = head->next;
		fprintf(fp3, "%s %s %s %d %d %d\n", head->num, head->name, head->sex, head->yu, head->shu, head->ying);//保存链表到文件里
	}
	fclose(fp3);
	return head;
}

stu *create(void)		//增添学生信息
{	
	fp3 = fopen(filename3, "a+");
	if (fp3 == NULL)
	{
		system("cls");
		gotoxy(56, 17);
		printf("增添失败");
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
		if (strcmp(student.name, p->name) == 0 && strcmp(p->num, student.num) == 0 && strcmp(p->sex, student.sex) == 0)//判断是否重复增加学生信息
		{
			gotoxy(50, 15);
			printf("该学生已存在！");
			gotoxy(50, 16);
			printf("请输入正确的学生信息！");
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
		printf("增添成功!");
		Sleep(2000);
	}
	system("cls");
	gotoxy(35, 13);
	printf("是否继续添加学生信息(是1/否0)：");
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
			printf("当学号和姓名为000结束");
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
					if (strcmp(student.name, p->name) == 0 && strcmp(p->num, student.num) == 0 && strcmp(p->sex, student.sex) == 0)//判断是否重复增加学生信息
					{
						gotoxy(53, 15);
						printf("该学生已存在！");
						gotoxy(50, 16);
						printf("请输入正确的学生信息！");
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
		printf("输入错误");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
	fclose(fp3);
	return head;
}

stu *change(stu*head,char num[],char name[])					//链表的修改
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
			printf("请输入修改的学生学号：");
			gotoxy(35, 11);
			printf("请输入修改的学生姓名：");
			gotoxy(35, 12);
			printf("请输入修改的学生性别：");
			gotoxy(35, 13);
			printf("请输入修改的学生语文成绩：");
			gotoxy(35, 14);
			printf("请输入修改的学生数学成绩：");
			gotoxy(35, 15);
			printf("请输入修改的学生英语成绩：");
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
			printf("修改成功！！");
			Sleep(2000);
		}
		else
		{
			gotoxy(52, 16);
			printf("无此学生！！");
		}
	return p;
}

void search_num()						//模糊查找学生学号
{
	stu student;
	int m = 0;
	char a[20];
	gotoxy(35, 14);
	printf("请输入需要查找的学生学号：");
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
		printf("没有符合条件的学生！！");
	}
	fclose(fp3);
}

void search_name()						//模糊查找学生姓名
{
	stu student;
	int m = 0;
	char a[10];
	gotoxy(35, 14);
	printf("请输入需要查找的学生姓名：");
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
		printf("没有符合条件的学生！！");
	}
	fclose(fp3);
}

void search_sex()						//模糊查找学生性别
{
	stu student;
	int m = 0;
	char a[5];
	gotoxy(35, 14);
	printf("请输入需要查找的性别：");
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
		printf("没有符合条件的学生！！");
	}
	fclose(fp3);
}

void print()							//打印所有学生信息
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
		printf("无学生数据！！");
	}
	fclose(fp3);
}

void statistics1()			//统计全班学生成绩
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
	case 1:				//语文平均分
		head=createlink();
		while (head->next->next != NULL)
		{
			head = head->next;
			y = y + head->yu;
			count = count + 1;
		}
		x = y / count;
		gotoxy(47, 15);
		printf("全部学生语文成绩平均分为：%.2f", x);
		break;
	case 2:				//数学平均分
		head = createlink();
		while (head->next->next != NULL)
		{
			head = head->next;
			y = y + head->shu;
			count = count + 1;
		}
		x = y / count;
		gotoxy(47, 15);
		printf("全部学生数学成绩平均分为：%.2f", x);
		break;
	case 3:				//英语平均分
		head = createlink();
		while (head->next->next != NULL)
		{
			head = head->next;
			y = y + head->ying;
			count = count + 1;
		}
		x = y / count;
		gotoxy(47, 15);
		printf("全部学生英语成绩平均分为：%.2f", x);
		break;
	case 4:				//全班三科平均分
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
		printf("全部学生成绩平均分为：%.2f", x);
		break;
	case 0:
		gotoxy(53, 16);
		exit(0);
	default:
		gotoxy(56, 17);
		printf("输入错误");
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
			printf("您的成绩为：语文：%d 数学：%d 英语：%d 三科平均分：%.2f", head->yu, head->shu, head->ying, x);
			strcpy(student.name, head->name);
		}
	}
	if (strcmp(student.name, student11.name) != 0)
	{
		gotoxy(45, 15);
		printf("您的信息并没有被教师录入系统");
	}
}

stu *pop_sort(stu *head)								//链表冒泡排序
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

void caozuo1()				//增删改查
{
	int n,m=0;
	gotoxy(59, 15);
	scanf("%d", &n);
	stu *head, student,*p;
	switch (n)
	{
	case 1:					//增添
		create();
		system("cls");
		gotoxy(53, 16);
		break;
	case 2:					//删除
		head = createlink();										//将文件里的数据转入一个单链表
		system("cls");
		gotoxy(35, 12);
		printf("请输入需删除的学生学号：");
		gotoxy(35, 14);
		printf("请输入需删除的学生姓名：");
		gotoxy(62, 12);
		scanf("%s", student.num);
		gotoxy(62, 14);
		scanf("%s", student.name);
		head=del(head, student.num, student.name);		//删除单链表中该学生的节点
		save(head);													//将删除后的单链表保存到文件里
		system("cls");
		gotoxy(53, 16);
		break;
	case 3:					//修改
		system("cls");
		head=createlink();
		gotoxy(35, 12);
		printf("请输入待修改的学生学号：");
		gotoxy(35, 14);
		printf("请输入待修改的学生姓名：");
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
	case 4:					//模糊查找
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
			printf("输入错误");
			Sleep(2000);
			system("cls");
			gotoxy(53, 16);
			exit(0);
		}
		break;
	case 5:					//打印所有学生信息
		system("cls");
		gotoxy(53, 16);
		Sleep(2000);
		print();
		break;
	case 6:					//学生成绩统计
		system("cls");
		menu9();
		statistics1();
		gotoxy(53, 16);
		break;
	case 7:					//按成绩排序
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
			printf("学号：%s\t姓名：%s\t性别：%s\t三科总分：%d\n", p->num, p->name, p->sex, p->zongfen);
		}
		break;
	case 0:
		gotoxy(53, 16);
		break;
	default:
		gotoxy(56, 17);
		printf("输入错误");
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
	case 1:				//查找
		system("cls");
		menu8();
		int m;
		gotoxy(59, 15);
		scanf("%d", &m);
		system("cls");
		switch (m)
		{
		case 1:
			search_num();			//按学生学号查找
			break;
		case 2:
			search_name();			//按学生姓名查找
			break;
		case 3:
			search_sex();			//按学生性别查找
			break;
		default:
			gotoxy(56, 17);
			printf("输入错误");
			Sleep(2000);
			system("cls");
			gotoxy(53, 16);
			exit(0);
		}
		break;
	case 2:							//统计登录学生的平均分
		system("cls");
		statistics2();
		gotoxy(53, 16);
		break;
	case 0:
		gotoxy(56, 17);
		break;
	default:
		gotoxy(56, 17);
		printf("输入错误");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
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
	gotoxy(40, 9);
	printf("请输入教师工号：");
	gotoxy(40, 10);
	printf("请输入教师姓名：");
	gotoxy(40, 11);
	printf("请输入教师性别：");
	gotoxy(40, 12);
	printf("请自定义密码：");
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
			Sleep(2000);
			gotoxy(48, 16);
			exit(0);
		}
		fprintf(fp1, "%s %s %s %s\n", teacher1.num, teacher1.name, teacher1.sex, teacher1.password);
		gotoxy(48, 15);
		printf("恭喜您注册成功!");
		Sleep(2000);//延时作用，停留在这个页面2秒
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
			Sleep(2000);
			gotoxy(50, 14);
			exit(0);
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
	gotoxy(40, 9);
	printf("请输入学生学号：");
	gotoxy(40, 10);
	printf("请输入学生姓名：");
	gotoxy(40, 11);
	printf("请输入学生性别：");
	gotoxy(40, 12);
	printf("请自定义密码(十位以内)：");
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
		fprintf(fp2, "%s %s %s %s\n", student1.num, student1.name, student1.sex, student1.password);
		gotoxy(48, 15);
		printf("恭喜您注册成功!");
		Sleep(2000);//延时作用，停留在这个页面2秒
	fclose(fp2);
}

void stureadfile()//学生密码读取
{
	stu student;
	fp2 = fopen(filename2, "a+");
	gotoxy(40, 10);
	printf("请输入学生姓名：");
	gotoxy(40, 12);
	printf("请输入密码(十位以内)：");
	gotoxy(62, 10);
	scanf("%s", student11.name);//输入用户名
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
			student11.password[j] = a[j];
		}
	}
	student11.password[j] = '\0';
	gotoxy(53, 13);
	printf("登录中，请稍等.....");
	Sleep(2000);
	system("cls");
	while (fscanf(fp2, "%s %s %s %s\n", student.num, student.name, student.sex, student.password) != EOF)
	{
		if (strcmp(student.name, student11.name) == 0 && strcmp(student11.password, student.password) == 0)//读取密码
		{
			gotoxy(53, 13);
			printf("登录成功!");
			Sleep(2000);
			break;
		}
	}
	if (strcmp(student.name, student11.name) != 0 || strcmp(student11.password, student.password) != 0)
	{
		gotoxy(50, 13);
		Sleep(2000);
		gotoxy(50, 13);
		printf("登录失败，请核对姓名或密码");
		Sleep(2000);
		gotoxy(50, 14);
		exit(0);
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
			sign_in();					//回到登录函数
			break;
		case 0:
			gotoxy(59, 15);
			break;
		default:
			gotoxy(56, 17);
			printf("输入错误");
			Sleep(2000);
			system("cls");
			gotoxy(53, 16);
			exit(0);
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
			sign_in();					//回到登录函数
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
		gotoxy(56, 17);
		printf("输入错误");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
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
		system("cls");
		menu2();
		caozuo1();
		break;
	case 2:							//学生登录
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
		printf("输入错误");
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
		sign_in();	//登录
		break;
	case 2:
		sign_up();	//注册
		break;
	default:
		gotoxy(56, 17);
		printf("输入错误");
		Sleep(2000);
		system("cls");
		gotoxy(53, 16);
		exit(0);
	}
	return 0;
}