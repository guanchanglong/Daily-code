#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//struct student
//{
//	int num;
//	char name[10];
//	char sex[10];
//};
//int main()
//{
//	struct student stu;
//	struct student *p;
//	p = &stu;//结构体指针
//	scanf("%d%s%s", &stu.num, &stu.name, &stu.sex);
//	printf("%d\t%s\t%s\n",(*p).num,(*p).name,(*p).sex);
//	return 0;
//}

#define N 100 
struct student
{
	int num;
	char name[10];
	float score[3];
	float aver;//定义学生三门科目的平均值
};
struct student max(struct student stu[], int n)
{
	int i, m = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].aver >stu[m].aver)//比较学生们平均分的大小
		{
			m = i;
		}
	}
	return stu[m];//返回平均分最大的学生到print函数中去
}
void print(struct student stud)
{
	printf("成绩最高的学生是：\n");
	printf("学号：%d\t姓名：%s\t三门课成绩：%.2lf\t平均成绩：%.2lf\n", stud.num, stud.name, stud.score[0], stud.score[1], stud.score[2], stud.aver);
}
void input(struct student stu[],int n)//输入学生信息
{
	int i;
	printf("请输入各位学生的信息：学号、姓名、3门科目的成绩：\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d %s %f %f %f", &stu[i].num, &stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].aver = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
	}
}
int main()
{
	void input(struct student stu[],int n);
	struct student max(struct student stu[],int n);
	void print(struct student stu);
	int n;
	struct student stu[N];
	struct student *p;
	printf("请输入学生数目:");
	scanf("%d", &n);//输入所需录入学生的数目
	p = stu;
	input(p,n);
	print(max(p,n));
	return 0;
}