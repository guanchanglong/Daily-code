#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdlib.h>
#include<stdio.h>
//int main(void)
//{
//	FILE *fp;
//	char inpu[20];
//	scanf("%s", inpu);//�˴��������һ���ļ����ڵĵ�ַ������:D:\\wenjian.txt�������������fopen���ؿ�ָ��
//	fp = fopen(inpu, "r");//��ֻ���ķ�ʽ���ļ�
//	if (fp == NULL)//���������ļ���ַ������fopen����һ����ָ��
//	{
//		printf("%s ��ʧ��\n", inpu);
//	}
//	else//���������ȷ�����򿪳ɹ�
//	{
//
//		printf("%s �򿪳ɹ�\n", inpu);
//	}
//	if (fclose(fp)== NULL)//fclose�ķ���ֵΪNULL��fp�ĵ�ַ��û�з����ı�
//	{
//		printf("�رճɹ�\n");
//	}
//	else
//	{
//		printf("�ر�ʧ��\n");
//	}
//	return 0;
//}

//int main()
//{
//	FILE *fp;
//	char inpu[20] = "D:\\wenjian.txt";
//	fp = fopen(inpu, "r");			//��ֻ���ķ�ʽ���ļ�
//	if (fp == NULL)
//	{
//		printf("%s��ʧ��\n", inpu);
//		return 0;
//	}
//	printf("\n%s�ļ�����:", inpu);
//	//�����ж��ļ��Ƿ����ķ���
//	//1
//	while (!feof(fp))				//feof�������÷�������ļ���������������1���棩�����򷵻�0���٣�����feof����ǰ��Ӹ�����ʾ�෴ֵ��
//	{
//		putchar(fgetc(fp));			//�ô˺�����ȡ�ļ����������ֻ�����ַ��ͣ�����Ǻ������������룬��Ϊfgetc�������ص����ַ���ASCII��
//	}
//	//2
//	char ch;
//	while ((ch = fgetc(fp)) != EOF)//fgetc������������ʱ���ض�ȡ�ַ���ASCII�룬�ʲ��ܶ�ȡ���֣�����������ʱ����EOF���˴�����EOF��ʾ�ļ���ȡ���
//		putchar(ch);
//	printf("\n");
//	fclose(fp);//�ر��ļ�
//	return 0;
//}


//void WriteFile(FILE *fp)//���������ļ�����д����
//{
//	char ch;
//	printf("�������ļ����ݣ���#������\n");
//	while ((ch=getchar())!= '#') //"!="��ǰ�������ǧ����ʡ��
//	{
//		fputc(ch, fp);			//д���ļ�
//	}
//	rewind(fp);                 //rewind�������ã����ļ�ָ�����¶�λ���ļ���ͷ
//}
//void ReadFile(FILE *fp)			//���������ļ����������
//{
//	char ch;
//	printf("��ȡ�ļ����ݣ�\n");
//	ch = fgetc(fp);
//	while (ch != EOF)
//	{
//		putchar(ch);
//		ch = fgetc(fp);
//	}
//	printf("\n�ļ���ȡ����");  
//}
//int main()
//{
//	FILE *fp;
//	char inputfile[30];
//	printf("�������ļ�����");
//	scanf("%s", inputfile);
//	fp = fopen(inputfile,"w+");
//	if (fp == NULL)					//����ļ��򿪳�����fp��������һ����ָ��
//	{
//		printf("���ļ�ʧ��");
//		return 0;
//	}
//	else
//	{
//		printf("\n%s�򿪳ɹ�\n", inputfile);
//		WriteFile(fp);
//		ReadFile(fp);
//		fclose(fp);
//	}
//	return 0;
//}

int main()
{
	FILE *fp;
	char a[100];
	printf("������һ���ַ���:\n");
	gets(a);
	char filename[20];
	printf("�������ļ���ַ:\n");
	scanf("%s", filename);
	fp = fopen(filename, "a+");
	if (fp == NULL)
	{
		printf("��ʧ��");
		return 0;
	}
	else
	{
		printf("%s�򿪳ɹ�\n", filename);
		fputs(a, fp);
		fclose(fp);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("��ʧ��");
		return 0;
	}
	else
	{
		printf("%s��ȡ����Ϊ��\n");
		while (fgets(a, sizeof(a), fp))
		{
			printf("%s\n", a);
		}
		fclose(fp);
	}
	return 0;
}