#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	FILE *fp;
//	char a[100];
//	printf("������һ���ַ���:\n");
//	gets(a);
//	char filename[20];
//	printf("�������ļ���ַ:\n");
//	scanf("%s", filename);
//	fp = fopen(filename, "a+");//�Կɶ�д�ķ�ʽ���ļ������ļ����ڣ����ļ�ԭ�ȵ����ݽ�����
//	//�о�ƾ������������Դ��������ʽ���ļ�
//	if (fp == NULL)
//	{
//		printf("��ʧ��");
//		return 0;
//	}
//	else
//	{
//		printf("%s�򿪳ɹ�\n", filename);
//		fputs(a, fp);		//���ַ���a�����뵽�ļ�����
//		fclose(fp);
//	}
//	fp = fopen(filename, "r");
//	if (fp == NULL)
//	{
//		printf("��ʧ��");
//		return 0;
//	}
//	else
//	{
//		printf("%s��ȡ����Ϊ��\n",filename);
//		while (fgets(a, sizeof(a), fp))//fgets������ȡ��󷵻ط���NULL
//		{
//			printf("%s\n", a);
//		}
//		fclose(fp);
//	}
//	return 0;
//}

////�ļ�����
//int main()
//{
//	FILE *in,*out;
//	char infile[50], outfile[50];
//	char s[256];
//	printf("������Դ�ļ�����");
//	scanf("%s", infile);
//	printf("������Ŀ���ļ�����");
//	scanf("%s", outfile);
//	if ((in = fopen(infile, "r")) == NULL)
//	{
//		printf("���ļ�%sʧ��\n", infile);
//		exit(0);
//	}
//	if ((out = fopen(outfile, "w")) == NULL)
//	{
//		printf("���ܽ���%s�ļ�\n", outfile);
//		exit(0);
//	}
//	while (fgets(s, 256, in))
//	{
//		fputs(s, out);
//	}
//	printf("�ļ��������\n");
//	fclose(in);
//	fclose(out);
//	return 0;
//}

//typedef struct rec
//{
//	char id[10];
//	char name[20];
//	float price;
//	int count;
//}Rec;
//void WriteFile(FILE *fp, int n)
//{
//	int i;
//	Rec record;
//	printf("��������Ʒ����\n");
//	for (i = 1; i <= n; i++)
//	{
//		printf("���������");
//		scanf("%s", record.id);
//		printf("����������");
//		scanf("%s", record.name);
//		printf("������۸�");
//		scanf("%f", &record.price);
//		printf("����������");
//		scanf("%d", &record.count);
//		printf("\n");
//		fprintf(fp, "%s %s %.2f %d", record.id, record.name, record.price, record.count);//fprintf��������fp��printf������ͬ�⣬������÷���printf��������
//	}
//}
//void ReadFile(FILE *fp, int n)
//{
//	Rec record;
//	double total = 0;
//	rewind(fp);
//	while (fscanf(fp, "%s %s %f %d\n", record.id, record.name, &record.price, &record.count) != EOF)//fscanf��������fp��scanf������ͬ�⣬������÷���scanf��������
//	{
//		printf("��ţ�%s ���ƣ�%s �۸�%.2f ������%d\n", record.id, record.name, record.price, record.count);
//		total = total + record.price*record.count;
//	}
//	printf("�ϼƣ�%.2f\n", total);
//}
//int main()
//{
//	char filename[20];
//	int n;
//	FILE *fp;
//	printf("������Ŀ���ļ���\n");
//	scanf("%s", filename);
//	fp = fopen(filename, "w+");
//	if (fp == NULL)
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	printf("��������Ʒ����:\n");
//	scanf("%d", &n);
//	WriteFile(fp, n);
//	ReadFile(fp, n);
//	fclose(fp);
//	return 0;
//}

typedef struct Rec
{
	char id[10];
	char name[20];
	float price;
	int count;
}Rec;
void WriteFile(FILE *fp,int n)
{
	int i;
	Rec record;
	printf("��������Ʒ����\n");
	for (i = 1; i <= n; i++)
	{
		printf("���������\n");
		scanf("%s", record.id);
		printf("����������\n");
		scanf("%s", record.name);
		printf("������۸�\n");
		scanf("%f", &record.price);
		printf("����������\n");
		scanf("%d", &record.count);
		fwrite(&record, sizeof(Rec), 1, fp);			//��������д�����ݵĸ���
	}
}
void ReadFile(FILE *fp, int n)
{
	Rec record;
	double total=0;
	rewind(fp);
	while (fread(&record, sizeof(Rec), 1, fp))			//�������ض�ȡ���ݵĸ���,����ȡ����Ϊ0ʱ,ѭ��ֹͣ
	{
		printf("��ţ�%s ���֣�%s �۸�%.2f ������%d\t\n", record.id, record.name, record.price, record.count);
		total = total + record.price*record.count;
	}
	printf("�ϼƣ�%.2f\n", total);
}
int main()
{
	char filename[10];
	FILE *fp;
	int n;
	printf("�������ļ�����\n");
	scanf("%s", filename);
	fp = fopen(filename, "wb+");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
		exit(1);						//exit(0)��ʾ�����˳�, exit(1)��ʾ�쳣�˳�.���1�Ƿ��ظ�����ϵͳ��
	}
	printf("��������Ʒ����:\n");
	scanf("%d", &n);
	WriteFile(fp, n);
	ReadFile(fp, n);
	fclose(fp);
	return 0;
}