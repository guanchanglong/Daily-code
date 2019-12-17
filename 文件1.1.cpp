#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdlib.h>
#include<stdio.h>
//int main(void)
//{
//	FILE *fp;
//	char inpu[20];
//	scanf("%s", inpu);//此处输入的是一个文件所在的地址，例如:D:\\wenjian.txt，如输入错误则fopen返回空指针
//	fp = fopen(inpu, "r");//以只读的方式打开文件
//	if (fp == NULL)//如果输入的文件地址错误，则fopen返回一个空指针
//	{
//		printf("%s 打开失败\n", inpu);
//	}
//	else//如果输入正确，即打开成功
//	{
//
//		printf("%s 打开成功\n", inpu);
//	}
//	if (fclose(fp)== NULL)//fclose的返回值为NULL，fp的地址并没有发生改变
//	{
//		printf("关闭成功\n");
//	}
//	else
//	{
//		printf("关闭失败\n");
//	}
//	return 0;
//}

//int main()
//{
//	FILE *fp;
//	char inpu[20] = "D:\\wenjian.txt";
//	fp = fopen(inpu, "r");			//以只读的方式打开文件
//	if (fp == NULL)
//	{
//		printf("%s打开失败\n", inpu);
//		return 0;
//	}
//	printf("\n%s文件内容:", inpu);
//	//两种判断文件是否读完的方法
//	//1
//	while (!feof(fp))				//feof函数的用法：如果文件结束，函数返回1（真），否则返回0（假）（故feof函数前面加个！表示相反值）
//	{
//		putchar(fgetc(fp));			//用此函数读取文件里面的内容只能是字符型，如果是汉字则会输出乱码，因为fgetc函数返回的是字符的ASCII码
//	}
//	//2
//	char ch;
//	while ((ch = fgetc(fp)) != EOF)//fgetc函数正常返回时返回读取字符的ASCII码，故不能读取汉字，不正常返回时返回EOF。此处返回EOF表示文件读取完毕
//		putchar(ch);
//	printf("\n");
//	fclose(fp);//关闭文件
//	return 0;
//}


//void WriteFile(FILE *fp)//函数：向文件里面写内容
//{
//	char ch;
//	printf("请输入文件内容，以#结束！\n");
//	while ((ch=getchar())!= '#') //"!="号前面的括号千万不能省略
//	{
//		fputc(ch, fp);			//写入文件
//	}
//	rewind(fp);                 //rewind函数作用：将文件指针重新定位到文件开头
//}
//void ReadFile(FILE *fp)			//函数：从文件里面读内容
//{
//	char ch;
//	printf("读取文件内容：\n");
//	ch = fgetc(fp);
//	while (ch != EOF)
//	{
//		putchar(ch);
//		ch = fgetc(fp);
//	}
//	printf("\n文件读取结束");  
//}
//int main()
//{
//	FILE *fp;
//	char inputfile[30];
//	printf("请输入文件名：");
//	scanf("%s", inputfile);
//	fp = fopen(inputfile,"w+");
//	if (fp == NULL)					//如果文件打开出错，则fp函数返回一个空指针
//	{
//		printf("打开文件失败");
//		return 0;
//	}
//	else
//	{
//		printf("\n%s打开成功\n", inputfile);
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
	printf("请输入一段字符串:\n");
	gets(a);
	char filename[20];
	printf("请输入文件地址:\n");
	scanf("%s", filename);
	fp = fopen(filename, "a+");
	if (fp == NULL)
	{
		printf("打开失败");
		return 0;
	}
	else
	{
		printf("%s打开成功\n", filename);
		fputs(a, fp);
		fclose(fp);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("打开失败");
		return 0;
	}
	else
	{
		printf("%s读取内容为：\n");
		while (fgets(a, sizeof(a), fp))
		{
			printf("%s\n", a);
		}
		fclose(fp);
	}
	return 0;
}