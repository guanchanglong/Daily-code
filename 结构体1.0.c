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
//�ṹ������ļ��ֶ��巽��
//1.struct friend friend1,friend2;//���ַ����Ƚ�ʵ��
//
//2.struct friend//����Ҳ�Ƚϳ���
//{
//	int num;
//	struct Date birthday;
//	char name[20];
//	int age;
//}friend1,friend2;
//
//3.struct//��̫�Ƽ�ʹ�ã���Ϊ������һ��֮��Ͳ��ܼ��������ˣ���Ϊ��û�нṹ����
//{
//	int num;
//	struct Date birthday;
//	char name[20];
//	int age;
//}friend1,friend2;

//int main()
//{
//	struct student student1 = {1010,"��","�ز�¡","��������"};//�ڴ˴�ѧ�������04193021�Ļ�����������ʾ��Ч�İ˽������֣���ʱδ�ҵ�ԭ��
//	printf("%d %s %s %s\n", student1.num, student1.sex, student1.name, student1.zhuzhi);//"."�ǳ�Ա��������������е�����������ȼ����
//	//ע�⣺�����ýṹ�������������г�Ա��ֵ
//	//���磺����д���Ǵ����printf("%s\n",studen1);
//	return 0;
//}

//int main()//��ṹ��һ����������״����������ƣ���������ѵ�ʱ������ִ���...
//{
//	struct student student1, student2;
//	scanf("%d %s %s %s %d", &student1.num, &student1.sex, &student1.name, &student1.zhuzhi,&student1.score);
//	scanf("%d %s %s %s %d", &student2.num, &student2.sex, &student2.name, &student2.zhuzhi,&student2.score);
//	if (student1.score > student2.score)//�ȽϽṹ�����Ĵ�С
//		printf("%d %s %s %d", student1.num, student1.sex, student1.name, student1.zhuzhi, student1.score);
//	else
//		printf("%d %s %s %s %d", student2.num, student2.sex, student2.name, student2.zhuzhi, student2.score);
//	return 0;
//}

struct student
{
	int num;//ѧ��
	char name[10];//����
	int score;//�ɼ�
}stu[3];
int main()//���ýṹ�������ж�ѧ���ɼ��ߵ�
{
	int i, j;
	printf("����������ѧ�š�ѧ���������ɼ�");
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