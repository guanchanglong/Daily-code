#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int num;
	char name[10];
}a1 = { 1, "guan" },a2 = { 2, "su" };//ע�⣬���ﲻ����''����ʼ���ַ�
int main()
{
	strcpy(a1.name,a2.name);//ʵ��֤����strcpy�������Խ�a2.name��ֵ(��������ַ�)����a1.name
	printf("%s", a1.name);
	return 0;
}