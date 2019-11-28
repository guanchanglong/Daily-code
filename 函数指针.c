#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
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

//void copy(char *q,char *p)//字符指针复制的另一种想法
//{
//	int i;
//	for (i = 0; *(q + i) != '\0'; i++)
//	{
//		*(p + i) = *(q + i);
//	}
//	*(p + i) = '\0';
//}
//int main()
//{
//	int j = 0;
//	char *q;
//	char a[] = "              ";
//	q = a;
//	scanf("%s", q);
//	char b[] = "              ";
//	char *p = b;
//	copy(q,p);
//	for (j = 0; *(p + j) != '\0'; j++)
//	{
//		printf("%c", *(p + j));
//	}
//	return 0;
//}

//函数指针
//int max(int x, int y)//求两个数中的较大者
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int main()
//{
//	int a=0, b=0,c;
//	scanf("%d %d", &a, &b);
//	int(*p)(int, int);//定义一个指针函数，*p两侧的（）不能省略
//	p = max;//将函数max的入口地址赋给指针变量p（函数名代表该函数的入口地址）
	//这样，调用*p就是调用max函数
//	c = (*p)(a, b);
//	printf("%d\n", c);
//	return 0;
//}

//int max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int min(int x, int y)
//{
//	if (x > y)
//		return y;
//	else
//		return x;
//}
////int max(int x, int y)
////{
////	if (x > y)/这样的写法是错误的，这里的函数有一个很明显的漏洞：当if…… 不包括所有的条件在内，也就是说有可能会出现条件不符合if(……）的情况，这时候函数就不知道该返回什么值了。
////		return x;
////}
////int min(int x, int y)
////{
////	if (x > y)
////		return y;
////}
//int main()
//{
//	int max(int, int);
//	int min(int x, int y);
//	int (*p)(int, int);
//	int a=0, b=0,c=0,d=0;
//	printf("请输入a和b的值：");
//	scanf("%d,%d", &a, &b);
//	printf("请输入c的值（输入0或1）：");
//	scanf("%d", &c);
//	if (c == 1)
//		p = max;
//	else if (c == 0)
//		p = min;
//	d = (*p)(a, b);//（error C4703: 使用了可能未初始化的本地指针变量“p”）这个错误在VS 2013中会出现，是编译器的问题，代码在旧的编译器上还是可以运行的
//	if (c == 1)
//		printf("max=%d", d);
//	else
//		printf("min=%d", d);
//	return 0;
//}

//今天突然想到的，C语言中输出小数点后多少位小数的做法是printf("%.xxxlf",a);注意：f前面的是L的小写形式
//例如：printf("%.2lf",a);就是打印小数点后2位

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int min(int x, int y)
{
	if (x > y)
		return y;
	else
		return x;
}
int sum(int x, int y)
{
	int z;
	z = x + y;
	return z;
}
int fun(int x, int y, int(*p)(int, int))//定义一个通用函数，用指向函数的指针作函数参数就是函数里面再定义一个指针函数作为形参
{
	int result;
	result = (*p)(x, y);//另一个被函数的地址入口
	printf("%d\n", result);
	return result;
}
int main()
{
	int a=0, b=0,c=0,d=0;
	printf("请输入a和b的值：");
	scanf("%d%d", &a, &b);
	printf("请输入c的值（输入0、1或2）：");
	scanf("%d", &c);
	if (c == 1)
		fun(a, b, max);//用指向函数的指针作函数参数
	else if (c == 0)
		fun(a, b, min); // 用指向函数的指针作函数参数
	else if (c == 2)
		fun(a, b, sum); // 用指向函数的指针作函数参数
	return 0;
}