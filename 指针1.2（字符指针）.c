#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void average(float *p, int n)//求三个人四个科目的平均分
//{
//	float *p_end;
//	float sum = 0,aver;
//	p_end = p + n - 1;
//	for (; p <= p_end; p++)
//		sum += *p;
//	aver = sum / n;
//	printf("平均分为：%5.2f\n", aver);
//}
//void search(float(*p)[4], int n)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//	{
//		printf("第三个人的四科成绩为：%5.2f ", *(*(p + n) + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	float sore[3][4];
//	float (*p)[4];
//	p = sore;//此处不能写成p=sore[0],因为这两者的类型不匹配，p为二维指针，sore[0]为一维指针
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%f", *(p + i) + j);
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%5.2f ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//	average(*sore, 12);
//	search(sore, 2);
//	return 0;
//}

//int main()//字符数组
//{
//	char a[] = "I Love China！！！";
//	printf("%s\n", a);
//	printf("%c\n", a[0]);
//	return 0;
//}

//int main()//字符指针
//{
//	char *a = "I Love China!!!";
//	printf("%s\n", a);//当换成a+1时，输出的结果是" Love China!!!",因为首地址向后退了一个字节，故不再打印"I"
//	//在调用字符指针里面的内容时，不用再在其前面加“*”
//	a = "I Love Code!!!";//对字符指针的再赋值
//	printf("%s\n", a);
//	return 0;
//}

//int main()
//{
//	char *a="I Love China!!!";
//	/*scanf("%s", a);*///这种写法是错误的，因为指针a未初始化，就算初始化了，也输出不了指针a里面的内容
//	printf("%s", a);
//	return 0;
//}
//
//int main()
//{
//	char *a, b[100];
//	a = b;
//	scanf("%s", a);
//	printf("%s\n", a);//这种写法可以，因为已经指定了指针a指向b数组（b数组内默认全为0）
//	return 0;
//}

//int main()//将字符串a复制到字符串b上，并输出字符串b（字符数组形式）
//{
//	char a[] = "I Love China!!!",b[20];
//	int i;
//	for (i = 0; *(a + i) != '\0'; i++)
//	{
//		*(b + i) = *(a + i);
//	}
//	*(b + i+1) = '\0';
//	for (i = 0; a[i] != '\0'; i++)
//	{
//		printf("%c", *(a + i));
//	}
//	printf("\n");
//	for (i = 0; b[i]!='\0'; i++)
//	{
//		printf("%c", *(b + i));
//	}
//	return 0;
//}

//int main()//字符指针形式
//{
//	char *a = "I Love China!!!";
//	char *b;
//	b = a;
//	printf("%s\n", b);
//	return 0;
//}

//int main()//通过改变首地址的值来控制输出的字符串
//{
//	char *a = "I Love China!!!";//char a[]="I Love China!!!";
//	a = a + 7;//a=a+7当a为数组名时这种写法是错误的，因为数组名为一个常量，不可修改
//	printf("%s\n", a);
//	return 0;
//}

//int main()
//{
//	char *a = "I Love China!!!";
//	printf("%c\n", a[0]);//字符指针中也可以用下标法来指向字符串中的的某个元素
//	//因为字符指针在内存中的存放方式与字符数组是一样的
//	return 0;
//}

int main()
{
	char *p;
	int a = 10, b = 100;
	p = "a=%d,b=%d\n";
	printf(p, a, b);//相当于printf("a=%d,b=%d\n",a,b);
	return 0;
}