#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
struct student
{
	int num;//ѧ��
	char name[10];//����
	int score;//�ɼ�
}stu[3];
int main()//���ýṹ�������ж�ѧ���ɼ��ߵ�
{
	int i, j;
	struct student stu[3];//��֮ǰ�Ĳ�ͬ
	printf("����������ѧ�š�ѧ���������ɼ�:");
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
				temp = stu[i];//��������ʾ��������Ǵ��
				stu[i] = stu[j];//�ṹ��ʵ�����ܻ��ำֵ�������ǵĳ�Ա���Ը�ֵ�������Ա���ַ������������ַ�����������ȥʵ�֡�
				stu[j] = temp;//������Ҳ�����У����ҾͲ�֪����ô������
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%d %s %d\n", stu[i].num, stu[i].name, stu[i].score);
	}
	return 0;
}