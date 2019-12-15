#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int num;
	char name[10];
}a1 = { 1, "guan" },a2 = { 2, "su" };//注意，这里不能用''来初始化字符
int main()
{
	strcpy(a1.name,a2.name);//实践证明，strcpy函数可以将a2.name的值(即里面的字符)赋给a1.name
	printf("%s", a1.name);
	return 0;
}