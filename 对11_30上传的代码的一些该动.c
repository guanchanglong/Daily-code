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
	struct student stu[3];//与之前的不同，添加上这里之后之前报错的地方（第25行）就不会再报错了（虽然我也不知道这是为什么）
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
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%d %s %d\n", stu[i].num, stu[i].name, stu[i].score);
	}
	return 0;
}
