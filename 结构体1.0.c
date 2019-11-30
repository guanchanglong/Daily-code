#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//struct student
//{
//	int num;
//	char sex[3];
//	char name[10];
//	char zhuzhi[20];
//	int score;
//};
//结构体变量的几种定义方法
//1.struct friend friend1,friend2;//这种方法比较实用
//
//2.struct friend//这种也比较常用
//{
//	int num;
//	struct Date birthday;
//	char name[20];
//	int age;
//}friend1,friend2;
//
//3.struct//不太推荐使用，因为定义了一遍之后就不能继续定义了，因为它没有结构体名
//{
//	int num;
//	struct Date birthday;
//	char name[20];
//	int age;
//}friend1,friend2;

//int main()
//{
//	struct student student1 = {1010,"男","关昌隆","广西梧州"};//在此处学号如果是04193021的话编译器会显示无效的八进制数字，暂时未找到原因
//	printf("%d %s %s %s\n", student1.num, student1.sex, student1.name, student1.zhuzhi);//"."是成员运算符，它在所有的运算符中优先级最高
//	//注意：不能用结构体变量名输出所有成员的值
//	//例如：这种写法是错误的printf("%s\n",studen1);
//	return 0;
//}

//int main()//这结构体一不留神就容易打错变量的名称，最好在清醒的时候打这种代码...
//{
//	struct student student1, student2;
//	scanf("%d %s %s %s %d", &student1.num, &student1.sex, &student1.name, &student1.zhuzhi,&student1.score);
//	scanf("%d %s %s %s %d", &student2.num, &student2.sex, &student2.name, &student2.zhuzhi,&student2.score);
//	if (student1.score > student2.score)//比较结构变量的大小
//		printf("%d %s %s %d", student1.num, student1.sex, student1.name, student1.zhuzhi, student1.score);
//	else
//		printf("%d %s %s %s %d", student2.num, student2.sex, student2.name, student2.zhuzhi, student2.score);
//	return 0;
//}

struct student
{
	int num;//学号
	char name[10];//名字
	int score;//成绩
}stu[3];
int main()//利用结构体数组判断学生成绩高低
{
	int i, j;
	printf("请依次输入学号、学生姓名、成绩");
	for(i = 0; i < 3; i++)
	{
		scanf("%d %s %d", &stu[i].num, &stu[i].name, &stu[i].score);
	}
	struct student temp;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (stu[i].score>stu[j].score)
			{
				temp = stu[i];//编译器显示这里好像是错的
				stu[i] = stu[j];//结构体实例不能互相赋值，但它们的成员可以赋值，如果成员是字符串，必须用字符串拷贝函数去实现。
				stu[j] = temp;//但是它也能运行，这我就不知道怎么回事了
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%d %s %d\n", stu[i].num, stu[i].name, stu[i].score);
	}
	return 0;
}