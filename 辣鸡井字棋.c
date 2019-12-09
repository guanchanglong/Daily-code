#define _CRT_SECURE_NO_WARNINGS 1
#define X 3
#define Y 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void b(char a[X][Y], int x, int y);
void D(char a[X][Y], int x, int y);
void playermove(char a[X][Y], int x, int y);
void computermove(char a[X][Y], int x, int y);
char iswin(char a[X][Y], int x, int y);

void b(char a[X][Y], int x, int y)
{
	int i;
	int j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			a[i][j] = ' ';
		}
	}
}
void D(char a[X][Y], int x, int y)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf(" %c ", a[i][j]);
			if (j < y - 1)
				printf("|");
		}
		printf("\n");
		if (i < x - 1)
		{
			for (j = 0; j < y; j++)
			{
				printf("---");
				if (j < x - 1)
					printf("|");
			}

			printf("\n");
		}
	}
}
void playermove(char a[X][Y], int x, int y)
{
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= X && y >= 1 && y <= Y)
		{
			if (a[x - 1][y - 1] != ' ')
			{
				printf("坐标被占用，请重新输入\n");
			}
			else
			{
				a[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("非法坐标，请重新输入\n");
		}
	}

}
void computermove(char a[X][Y], int x, int y)
{
	int i, j;
	printf("电脑走：\n");
	while (1)
	{
		i = rand() % x;
		j = rand() % y;
		if (a[i][j] == ' ')
		{
			a[i][j] = '#';
			break;
		}
	}
}
int isfull(char a[X][Y], int x, int y)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (a[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char iswin(char a[X][Y], int x, int y)
{
	int i;
	for (i = 0; i < x; i++)//行
	{
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][1] != ' ')
			return a[i][1];
	}
	for (i = 0; i < y; i++)//列
	{
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[1][i] != ' ')
			return a[1][i];
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != ' ')//斜
		return a[1][1];
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[1][1] != ' ')
		return a[1][1];
	if (isfull(a, x, y) == 1)
	{
		return 'Q';
	}
	return 'C';
}


#define _CRT_SECURE_NO_WARNINGS 1
void menu()
{
	printf("********************************\n");
	printf("********     1.play    *********\n");
	printf("********     0.exit    *********\n");
	printf("********************************\n");
}
void game()
{
	char ret = 0;
	char a[X][Y] = { 0 };
	b(a, X, Y);
	D(a, X, Y);
	while (1)
	{
		playermove(a, X, Y);
		D(a, X, Y);
		ret = iswin(a, X, Y);
		if (ret != 'C')
		{
			break;
		}
		computermove(a, X, Y);
		D(a, X, Y);
		ret = iswin(a, X, Y);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}
void test()
{
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			/*printf("猜数字\n");*/
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
		}
	} while (input);

}
int main()
{
	test();
	return 0;
}