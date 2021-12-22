#define _CRT_SECURE_NO_WARNINGS 1
#include "func.h"

//系统基本功能：增加、修改、删除、浏览、查找、排序、统计等。

inline void menu() {
	printf("1.增加\t2.修改\t3.删除\t4.浏览\t5.查找\t6.排序\t7.统计\n");
}
int main() {
	do {
		int input;
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:addfunc(); break;
		case 2:changefunc(); break;
		case 3:deletefunc(); break;
		case 4:lookfunc(); break;
		//case 5:findfunc(); break;
		case 6:sortfunc(); break;
		//case 7:statisticsfunc(); break;
		default:printf("输入错误");
			break;
		}
	} while (1);
}