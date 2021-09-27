#define _CRT_SECURE_NO_WARNINGS 1
#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define MAX_SNAKE 100  //蛇的最大节数

#undef UNICODE
#undef _UNICODE

#include<graphics.h>
#include<stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#include<mmsyscom.h>
#pragma comment(lib,"winmm.lib")


enum DIR //表示蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct Snake//蛇
{
	int num;//长度
	int dir;//方向
	int score;//分数
	int size;//蛇身
	int speed;//速度
	POINT coor[MAX_SNAKE];
}snake;

struct Food//食物
{
	POINT fd;
	int flag;
	DWORD color;//颜色[0-255]

}food;

void GameInit()//初始化
{
	srand((unsigned int)time(NULL));

	//定义蛇
	snake.num = 3;
	snake.dir = RIGHT;
	snake.score = 0;
	snake.size = 10;
	snake.speed = 10;
	snake.coor[2].x = 0;//第三节尾巴
	snake.coor[2].y = 0;//初始化是左上角的长条
	snake.coor[1].x = 0 + snake.size;
	snake.coor[1].y = 0;
	snake.coor[0].x = 0 + 2 * snake.size;//蛇头
	snake.coor[0].y = 0;

	//定义食物
	food.fd.x = rand() % (WIN_WIDTH / 10) * 10;
	food.fd.x = rand() % (WIN_HEIGHT / 10) * 10;
	food.flag = 1;//初始化食物存在
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
}

void GameDraw()
{
	setbkcolor(RGB(105, 160, 141));
	cleardevice();//清空元素

	//画蛇
	setfillcolor(YELLOW);//填充函数
	//画矩形，一共三次
	int i = 0;
	for (i = 0; i < snake.num; i++)
	{
		setlinecolor(BLACK);
		fillrectangle(snake.coor[i].x,snake.coor[i].y,snake.coor[i].x + snake.size,snake.coor[i].y + snake.size);
		/*在 easyx 中，solidrectangle 这个函数用于画无边框的填充矩形,而fillrectangle用于画有边框的填充矩形
	void solidrectangle(int left,int top,int right,int bottom);
	void solidrectangle(矩形左部 x 坐标,	矩形顶部 y 坐标,	矩形右部 x 坐标,	矩形底部 y 坐标);
		*/
	}
	//画食物
	if (food.flag == 1)//通过填充颜色的方式来实现食物被吃完后消失（吃掉后flag==0，则不填充）
	{
		setfillcolor(food.color);
		fillellipse(food.fd.x, food.fd.y, food.fd.x + 10, food.fd.y + 10);
	}
	//显示分数
	char tmp[20] = "";
	sprintf(tmp, "分数：%d", snake.score);
	//sprintf,通过检测变量来不断打印数值
	outtextxy(20, 20, tmp);
	//void outtextxy(int x, int y, LPCTSTR str);	// 在指定位置输出字符串

}

void KeyControl()
{
	if (GetAsyncKeyState(VK_UP) && snake.dir != DOWN)//后面的条件确保了不可以进行反向操作
	{
		snake.dir = UP;
	}
	if (GetAsyncKeyState(VK_DOWN) && snake.dir != UP)
	{
		snake.dir = DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) && snake.dir != RIGHT)
	{
		snake.dir = LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) && snake.dir != LEFT)
	{
		snake.dir = RIGHT;
	}

}


void GameInit();  //初始化游戏元素
void GameDraw();  //创建贪吃蛇
void SnakeMove();  // 操作蛇的移动
void KeyControl();  //控制方向函数
void EatFood();  //吃食物
void DontEatSelf();  //游戏结束判断
void Pause();  //游戏暂停

void main(void)
{
	initgraph(WIN_WIDTH, WIN_HEIGHT, SHOWCONSOLE);//初始化一个图形窗口
	printf("\tWelcome! \n");
	printf("\tPlay Game Right Now！\n");
	GameInit();  //初始化游戏元素

	mciSendString("open Carnival_De_Brazil.mp3 alias a", 0, 0, 0);
	mciSendString("play a repeat", 0, 0, 0);

	while (1)  //使用死循环来保证可以一直游玩
	{
		SnakeMove();  //先移动
		GameDraw();  //再画蛇
		EatFood();
		KeyControl();
		DontEatSelf();
		Sleep(50);  //每次都要间隔半秒钟，才可以实时的看见，否则运行速度太快了，没法操作
		//同理这个操作也可以成为设置游戏难度的选项
		//Pause();

	}

	getchar();//用来防止 游戏窗口一闪而过
	closegraph();  //关闭游戏图形窗口
}

void SnakeMove()
{
	/*要操作蛇头的移动，蛇的身体随着蛇头一起运动，就是
	要从最后一节开始，让蛇的每一节身体都随着移动到它前一节身体的位置上
	*/
	int i;
	for (i = snake.num - 1; i > 0; i--)  //因为是对数组进行操作，所以这里要 -1,并且这里是i-- 
	{
		snake.coor[i].x = snake.coor[i - 1].x;
		snake.coor[i].y = snake.coor[i - 1].y;

	}
	switch (snake.dir)
	{
	case UP:snake.coor[0].y -= 10;
		/*
		这里要实现的是可以在窗口处自由进出
		因为记录的是蛇头方块左边的坐标，而这里我们要使蛇头在接触到边沿(是蛇头的右边）就进入下面的边界
		所以这里要有个+10，就是为了去掉蛇头自身的长度
		*/
		if (snake.coor[0].y + 10 <= 0)
		{
			snake.coor[0].y = WIN_HEIGHT;
		}
		break;
	case DOWN:snake.coor[0].y += 10;
		if (snake.coor[0].y >= WIN_HEIGHT)
		{
			snake.coor[0].y = 0;
		}
		break;
	case LEFT:snake.coor[0].x -= 10;
		if (snake.coor[0].x + 10 <= 0)
		{
			snake.coor[0].x = WIN_WIDTH;
		}
		break;
	case RIGHT:snake.coor[0].x += 10;
		if (snake.coor[0].x >= WIN_WIDTH)
		{
			snake.coor[0].x = 0;
		}
		break;

	default:printf("错误操作，请重新操作！");
		break;
	}
	//snake.coor[0].x += 10;

}
void EatFood()
{
	if (snake.coor[0].x == food.fd.x && snake.coor[0].y == food.fd.y && food.flag == 1)
	{
		snake.num++;
		snake.score += 10;
		food.flag = 0;
	}
	if (food.flag == 0)
	{
		food.fd.x = rand() % (WIN_WIDTH / 10) * 10;
		food.fd.y = rand() % (WIN_HEIGHT / 10) * 10;
		food.flag = 1;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	}
}

void DontEatSelf()
{
	for (int i = 4; i < snake.num; i++)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
		{
			outtextxy(200, 200, "Game over!");
			_getch();  //保持停顿
			exit(666);
		}

	}
}

void Pause()
{
	if (_getch() == 32)  //32表示空格
	{
		//while (_getch() != ' ');
		while (1)
		{
			_getch();
		}
	}
}
