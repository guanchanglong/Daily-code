#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct student
{
	int num;//学号
	char name[10];//名字
	int score;//成绩
}stu[3];
int main()//利用结构体数组判断学生成绩高低
{
	int i, j;
	struct student stu[3];//与之前的不同
	printf("请依次输入学号、学生姓名、成绩:");
	for (i = 0; i < 3; i++)
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