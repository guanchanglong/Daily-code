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
//	p = &stu;//�ṹ��ָ��
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
	float aver;//����ѧ�����ſ�Ŀ��ƽ��ֵ
};
struct student max(struct student stu[], int n)
{
	int i, m = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].aver >stu[m].aver)//�Ƚ�ѧ����ƽ���ֵĴ�С
		{
			m = i;
		}
	}
	return stu[m];//����ƽ��������ѧ����print������ȥ
}
void print(struct student stud)
{
	printf("�ɼ���ߵ�ѧ���ǣ�\n");
	printf("ѧ�ţ�%d\t������%s\t���ſγɼ���%.2lf\tƽ���ɼ���%.2lf\n", stud.num, stud.name, stud.score[0], stud.score[1], stud.score[2], stud.aver);
}
void input(struct student stu[],int n)//����ѧ����Ϣ
{
	int i;
	printf("�������λѧ������Ϣ��ѧ�š�������3�ſ�Ŀ�ĳɼ���\n");
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
	printf("������ѧ����Ŀ:");
	scanf("%d", &n);//��������¼��ѧ������Ŀ
	p = stu;
	input(p,n);
	print(max(p,n));
	return 0;
}