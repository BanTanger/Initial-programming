#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void game()
{
	//雷的信息存储
	//1.布置好的
	char board[ROWS][COLS] = { 0 };
	//2.排查出来的（要展示的）
	char show[ROWS][COLS] = { 0 };
	//初始化
	initboard(board,ROWS,COLS,'0');
	initboard(show,ROWS,COLS,'*');
	//打印棋盘
	//Displayboard(board, ROW, COL);
	Displayboard(show, ROW, COL);
	//布置雷
	setboard(board, ROW, COL);
	/*Displayboard(board, ROW, COL)*/;
	//扫雷
	find(board,show,ROW,COL);//把board.show,row,col传递过去
}
void menu()
{
	printf("****************************\n");
	printf("********   1.play   ********\n");
	printf("********   0.exit   ********\n");
	printf("****************************\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入非法\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
