#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()//���ַ���a���Ƶ��ַ���b�ϣ�������ַ���b���ַ�������ʽ��
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

//void copy(char *q,char *p)//�ַ�ָ�븴�Ƶ���һ���뷨
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

//����ָ��
//int max(int x, int y)//���������еĽϴ���
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
//	int(*p)(int, int);//����һ��ָ�뺯����*p����ģ�������ʡ��
//	p = max;//������max����ڵ�ַ����ָ�����p������������ú�������ڵ�ַ��
	//����������*p���ǵ���max����
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
////	if (x > y)/������д���Ǵ���ģ�����ĺ�����һ�������Ե�©������if���� ���������е��������ڣ�Ҳ����˵�п��ܻ��������������if(���������������ʱ�����Ͳ�֪���÷���ʲôֵ�ˡ�
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
//	printf("������a��b��ֵ��");
//	scanf("%d,%d", &a, &b);
//	printf("������c��ֵ������0��1����");
//	scanf("%d", &c);
//	if (c == 1)
//		p = max;
//	else if (c == 0)
//		p = min;
//	d = (*p)(a, b);//��error C4703: ʹ���˿���δ��ʼ���ı���ָ�������p�������������VS 2013�л���֣��Ǳ����������⣬�����ھɵı������ϻ��ǿ������е�
//	if (c == 1)
//		printf("max=%d", d);
//	else
//		printf("min=%d", d);
//	return 0;
//}

//����ͻȻ�뵽�ģ�C���������С��������λС����������printf("%.xxxlf",a);ע�⣺fǰ�����L��Сд��ʽ
//���磺printf("%.2lf",a);���Ǵ�ӡС�����2λ

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
int fun(int x, int y, int(*p)(int, int))//����һ��ͨ�ú�������ָ������ָ���������������Ǻ��������ٶ���һ��ָ�뺯����Ϊ�β�
{
	int result;
	result = (*p)(x, y);//��һ���������ĵ�ַ���
	printf("%d\n", result);
	return result;
}
int main()
{
	int a=0, b=0,c=0,d=0;
	printf("������a��b��ֵ��");
	scanf("%d%d", &a, &b);
	printf("������c��ֵ������0��1��2����");
	scanf("%d", &c);
	if (c == 1)
		fun(a, b, max);//��ָ������ָ������������
	else if (c == 0)
		fun(a, b, min); // ��ָ������ָ������������
	else if (c == 2)
		fun(a, b, sum); // ��ָ������ָ������������
	return 0;
}