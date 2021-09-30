#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"通讯录.h"
#include<string.h>
void menu()
{
	printf("******************************\n");
	printf("***** 1.add      2.del   *****\n");
	printf("***** 3.search   4.modify*****\n");
	printf("***** 5.show     6.sort  *****\n");
	printf("***** 0.exit             *****\n");
	printf("******************************\n");
}

int main()
{
	int input = 0;
	struct Contact con;//con就是通讯录，里面包含1000个元素的数和当前存放的值
	
	//通过一个结构体来封装两个相似变量
	//int size = 0;
	//struct PeoInfo con[MAX];//存放一千人的个人信息
	
    InitContact(&con);//传地址效率高，而且函数改值需要通过传地址来影响主函数。
	
//创建通讯录
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);//&con传输通讯录的地址
			break;
		case DEL:
			DelContact(&con);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			break;
		case 0:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n"); 
			break;
		}
	} while (input);
	return 0;
}