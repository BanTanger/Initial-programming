#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void initboard(char board[ROW][COL], int row, int col,int set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		for (j = 0; j <= col; j++)
		{
			board[i][j] = set;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <=row;i++)//开辟出来的棋盘是11*11，我们需要9*9，从下标1开始打印，到row(下标9)，刚刚好是9*9
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setboard(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
//'3'-'0'=3
int get(char board[ROWS][COLS], int x, int y)
{
	//统计xy周围八格相加的结果
	return board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y - 1] - '0' * 8;
}
//void zk(char board[ROW][COL],int x,int y)
//{
//	if (board[x][y] == '0')
//	{
//		board[x][y] = ' ';
//		board[x - 1][y];
//		board[x - 1][y - 1];
//		board[x][y - 1];
//		board[x + 1][y - 1];
//		board[x + 1][y];
//		board[x + 1][y + 1];
//		board[x][y + 1];
//		board[x - 1][y - 1];
//	}
//
//}
void find(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//获胜条件
	while (1)
	{
		printf("请输入坐标\n");
		scanf("%d%d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//判断 1.雷，gameover.2.统计
			if (board[x][y] == '1')
			{
				printf("GAMEOVER!\n");
				Displayboard(board, ROW, COL);
				break;
			}
			else
			{
				//计算，xy坐标周围有几个雷，
				int count = get(board,x,y);
				show[x][y] = count + '0';//将数字转换成字符
				zk(board,x,y);
				Displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法!\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		Displayboard(board, ROW, COL);
	}
}