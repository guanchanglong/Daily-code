#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	FILE *fp;
//	char a[100];
//	printf("请输入一段字符串:\n");
//	gets(a);
//	char filename[20];
//	printf("请输入文件地址:\n");
//	scanf("%s", filename);
//	fp = fopen(filename, "a+");//以可读写的方式打开文件，如文件存在，则文件原先的内容将保留
//	//感觉凭借这个函数可以创建任意格式的文件
//	if (fp == NULL)
//	{
//		printf("打开失败");
//		return 0;
//	}
//	else
//	{
//		printf("%s打开成功\n", filename);
//		fputs(a, fp);		//将字符串a的输入到文件里面
//		fclose(fp);
//	}
//	fp = fopen(filename, "r");
//	if (fp == NULL)
//	{
//		printf("打开失败");
//		return 0;
//	}
//	else
//	{
//		printf("%s读取内容为：\n",filename);
//		while (fgets(a, sizeof(a), fp))//fgets函数读取完后返回返回NULL
//		{
//			printf("%s\n", a);
//		}
//		fclose(fp);
//	}
//	return 0;
//}

////文件复制
//int main()
//{
//	FILE *in,*out;
//	char infile[50], outfile[50];
//	char s[256];
//	printf("请输入源文件名：");
//	scanf("%s", infile);
//	printf("请输入目标文件名：");
//	scanf("%s", outfile);
//	if ((in = fopen(infile, "r")) == NULL)
//	{
//		printf("打开文件%s失败\n", infile);
//		exit(0);
//	}
//	if ((out = fopen(outfile, "w")) == NULL)
//	{
//		printf("不能建立%s文件\n", outfile);
//		exit(0);
//	}
//	while (fgets(s, 256, in))
//	{
//		fputs(s, out);
//	}
//	printf("文件复制完成\n");
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
//	printf("请输入商品数据\n");
//	for (i = 1; i <= n; i++)
//	{
//		printf("请输入序号");
//		scanf("%s", record.id);
//		printf("请输入名字");
//		scanf("%s", record.name);
//		printf("请输入价格");
//		scanf("%f", &record.price);
//		printf("请输入数量");
//		scanf("%d", &record.count);
//		printf("\n");
//		fprintf(fp, "%s %s %.2f %d", record.id, record.name, record.price, record.count);//fprintf函数除了fp与printf函数不同外，其基本用法与printf函数类似
//	}
//}
//void ReadFile(FILE *fp, int n)
//{
//	Rec record;
//	double total = 0;
//	rewind(fp);
//	while (fscanf(fp, "%s %s %f %d\n", record.id, record.name, &record.price, &record.count) != EOF)//fscanf函数除了fp与scanf函数不同外，其基本用法与scanf函数类似
//	{
//		printf("序号：%s 名称：%s 价格：%.2f 数量：%d\n", record.id, record.name, record.price, record.count);
//		total = total + record.price*record.count;
//	}
//	printf("合计：%.2f\n", total);
//}
//int main()
//{
//	char filename[20];
//	int n;
//	FILE *fp;
//	printf("请输入目标文件：\n");
//	scanf("%s", filename);
//	fp = fopen(filename, "w+");
//	if (fp == NULL)
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	printf("请输入商品数量:\n");
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
	printf("请输入商品数据\n");
	for (i = 1; i <= n; i++)
	{
		printf("请输入序号\n");
		scanf("%s", record.id);
		printf("请输入名字\n");
		scanf("%s", record.name);
		printf("请输入价格\n");
		scanf("%f", &record.price);
		printf("请输入总数\n");
		scanf("%d", &record.count);
		fwrite(&record, sizeof(Rec), 1, fp);			//函数返回写入数据的个数
	}
}
void ReadFile(FILE *fp, int n)
{
	Rec record;
	double total=0;
	rewind(fp);
	while (fread(&record, sizeof(Rec), 1, fp))			//函数返回读取数据的个数,当读取数据为0时,循环停止
	{
		printf("序号：%s 名字：%s 价格：%.2f 数量：%d\t\n", record.id, record.name, record.price, record.count);
		total = total + record.price*record.count;
	}
	printf("合计：%.2f\n", total);
}
int main()
{
	char filename[10];
	FILE *fp;
	int n;
	printf("请输入文件名：\n");
	scanf("%s", filename);
	fp = fopen(filename, "wb+");
	if (fp == NULL)
	{
		printf("文件打开失败");
		exit(1);						//exit(0)表示正常退出, exit(1)表示异常退出.这个1是返回给操作系统的
	}
	printf("请输入商品数量:\n");
	scanf("%d", &n);
	WriteFile(fp, n);
	ReadFile(fp, n);
	fclose(fp);
	return 0;
}