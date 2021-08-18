#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	int ret = 0;
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化数组
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋 循环
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = iswin(board,ROW，COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = iswin(board, ROW，COL);
		if (ret != 'c')
		{
			printf("电脑赢\n");
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if(ret = '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n")；
	}
}

void menu()
{
	printf("*************菜单************\n");
	printf("*****  1.play   0.exit  *****\n");
	printf("*****************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请输入选择（1/0）:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏：三子棋\n");
			game();
			break;
		case 0:
			printf("即将退出游戏\n");
			break;
		default:
			printf("您输入的值不符合菜单所提供，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}