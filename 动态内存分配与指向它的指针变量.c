#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//int main()
//{
//	int a=3;
//	int *p1 = &a;
//	char*p2;
//	void *p3;//����һ��������ָ��
//	p3 = (void*)p1;
//	p2 = (char*)p3;
//	printf("%d\n", *p1);
//	return 0;
//}

void check(int *p)
{
	int i;
	printf("They are fail:");
	for (i = 0; i < 5; i++)
	{
		if (p[i] < 60)
			printf("%d", p[i]);
		printf("\n");
	}
}
int main()
{
	void check(int *);
	int *p1, i;
	p1 = malloc(5 * sizeof(int));//�˴�������5*4���ֽڵĶ�̬�ڴ�ռ䡣sizeof�ⶨ�������ڱ�ϵͳ�е��ֽ���
	//�ñ��������ý���ǿ������ת�����������Զ�����ת������
	//p1=(int *)malloc(5*sizeof(int));//Ҳ���Խ���ǿ������ת����malloc��void*�ͣ�����ת��Ϊint*�ͣ�
	for (i = 0; i < 5; i++)
	{
		scanf("%d", p1 + i);
	}
	check(p1);
	return 0;
}