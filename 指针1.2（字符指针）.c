#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void average(float *p, int n)//���������ĸ���Ŀ��ƽ����
//{
//	float *p_end;
//	float sum = 0,aver;
//	p_end = p + n - 1;
//	for (; p <= p_end; p++)
//		sum += *p;
//	aver = sum / n;
//	printf("ƽ����Ϊ��%5.2f\n", aver);
//}
//void search(float(*p)[4], int n)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//	{
//		printf("�������˵��ĿƳɼ�Ϊ��%5.2f ", *(*(p + n) + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	float sore[3][4];
//	float (*p)[4];
//	p = sore;//�˴�����д��p=sore[0],��Ϊ�����ߵ����Ͳ�ƥ�䣬pΪ��άָ�룬sore[0]Ϊһάָ��
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

//int main()//�ַ�����
//{
//	char a[] = "I Love China������";
//	printf("%s\n", a);
//	printf("%c\n", a[0]);
//	return 0;
//}

//int main()//�ַ�ָ��
//{
//	char *a = "I Love China!!!";
//	printf("%s\n", a);//������a+1ʱ������Ľ����" Love China!!!",��Ϊ�׵�ַ�������һ���ֽڣ��ʲ��ٴ�ӡ"I"
//	//�ڵ����ַ�ָ�����������ʱ������������ǰ��ӡ�*��
//	a = "I Love Code!!!";//���ַ�ָ����ٸ�ֵ
//	printf("%s\n", a);
//	return 0;
//}

//int main()
//{
//	char *a="I Love China!!!";
//	/*scanf("%s", a);*///����д���Ǵ���ģ���Ϊָ��aδ��ʼ���������ʼ���ˣ�Ҳ�������ָ��a���������
//	printf("%s", a);
//	return 0;
//}
//
//int main()
//{
//	char *a, b[100];
//	a = b;
//	scanf("%s", a);
//	printf("%s\n", a);//����д�����ԣ���Ϊ�Ѿ�ָ����ָ��aָ��b���飨b������Ĭ��ȫΪ0��
//	return 0;
//}

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

//int main()//�ַ�ָ����ʽ
//{
//	char *a = "I Love China!!!";
//	char *b;
//	b = a;
//	printf("%s\n", b);
//	return 0;
//}

//int main()//ͨ���ı��׵�ַ��ֵ������������ַ���
//{
//	char *a = "I Love China!!!";//char a[]="I Love China!!!";
//	a = a + 7;//a=a+7��aΪ������ʱ����д���Ǵ���ģ���Ϊ������Ϊһ�������������޸�
//	printf("%s\n", a);
//	return 0;
//}

//int main()
//{
//	char *a = "I Love China!!!";
//	printf("%c\n", a[0]);//�ַ�ָ����Ҳ�������±귨��ָ���ַ����еĵ�ĳ��Ԫ��
//	//��Ϊ�ַ�ָ�����ڴ��еĴ�ŷ�ʽ���ַ�������һ����
//	return 0;
//}

int main()
{
	char *p;
	int a = 10, b = 100;
	p = "a=%d,b=%d\n";
	printf(p, a, b);//�൱��printf("a=%d,b=%d\n",a,b);
	return 0;
}