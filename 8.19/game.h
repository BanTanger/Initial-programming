#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void initboard(char board[ROWS][COLS], int row, int col,char set);
void Displayboard(char board[ROWS][COLS],int row,int col);
void setboard(char board[ROWS][COLS], int row, int col);
void find(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void zk(char board[ROW][COL], int x, int y);