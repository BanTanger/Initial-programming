#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int get_max(int x, int y)
{//表达有错误，函数中不能用打印来表示
	if (x > y)
		return x;
	else
		return y;
	return 0;
}
int main()
{
	int a = 10;
	int b = 20;
	int max = get_max(a, b);
	printf("%d\n", max);
	return 0;
}
// 
// int get_max(int x, int y)
//{//表达有错误，函数中不能用打印来表示
//	if (x > y)
//	{
//		printf("%d\n", x);
//	}
//	else
//		printf("%d\n", y);
//	if (x == y)
//	{
//		printf("您输入的两个值相等，无法比较\n");
//	}
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	get_max(a, b);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "hello world";
//	memset(arr1, '*', 5);
//	printf("%s\n", arr1);
//	return 0;
//}

//=======================strcpy==============================
//int main()
//{
//	char arr1[] = "bit";
//	char arr2[20] = "###############";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//=======================求和函数=============================
//int Add(int x,int y)
//{
//	int z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}

//==========================自动关机程序==============================
//int main()
//{
//	char input[20] = { 0 };
//	//shutdown -s -t 60
//	system("shutdown -s -t 60");
//  again:
//	printf("请注意，你的电脑将在1分钟内关机，如果输入：我是猪，则取消关机\n请输入>:");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪") == 0)//比较两个字符串
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	printf("关机程序已取消，请勿相信他人给你发的程序应用\n");
//		return 0;
//}

//=======================goto循环=========================
//int main()
//{
//again:
//	printf("hello bit\n");
//	goto again;
//	return 0;
//}

//=======================数字游戏=========================
//void menu()
//{
//	printf("******************************************\n");
//	printf("** To Choose:>  1.play  0.exit     *******\n");
//	printf("******************************************\n");
//}
//void game()
//{
//	int guess = 0;
//	int ret = 0;
//	ret = rand()%100+1;//生成1到100之间的随机数（取模）
//	//printf("%d\n",ret);
//	//猜数字（循环猜测）
//	while (1)
//	{
//		printf("请猜数字(在1到100之间):>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned)time(NULL));//NULL空指针，不需要返回任何一个值时使用
//	//时间戳
//	//此语句要放在主函数里面，若放到自定义game函数里则不够随机
//	int input = 0;
//	do 
//	{
//		menu();
//		printf("请选择0/1>:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();//猜数字游戏
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	int b = 0;
//	for (b=1; b <= 9; b++){
//		//从1开始，打印9行
//		for (a = 1; a <= b; a++){
//	printf("%d*%d=%d\t", a, b, a * b);
//		}
//		printf("\n");
//    }
//	return 0;
//}

//int main()//===================有错误==================
//{
//	int i = 0; int j = 0;
//	for (i = 1, j = 1; i <= 9&& j <= 9; i++, j++)
//	{	
//		if (i == j)
//		{
//			printf("%d*%d", i, j);
//			j++;
//		}
//		 if (i < j)
//		{	
//			printf("\n%d*%d ",i,j);
//			i++;
//		}
//	}
//	return 0;
//}

//==================寻找最大值(数组中)=====================
//int main()
//{
//	int i = 0;
//	int arr[] = { -1,-5,6,-2,-7,10,8 };
//	int sz = strlen(arr);
//	int max = arr[0];//假设数组第一个下标为最大
//	//后面在通过赋值不断更正，循环比较max和数组中每一个元素的大小
//	for (i = 1; i <= sz; i++)
//	{	
//		if (max < arr[i])
//			max = arr[i];
//	}
//	printf("%d\n", max);
//	return 0;
//}

//==================分数求和=======================
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag = -flag;
//	}
//	printf("sum=%lf\n", sum);
//	return 0;
//}

//==================寻找出现9的数字=======================
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (; i <= 100; i++)
//	{
//		//if ((i % 10 == 9) || (i / 10 == 9))
//			//这里出现问题，表达式表示为if  - else if
//			//99中，出现了两次9数字，所以要重复计算
//			//9,19,29,39....89,99 - 10个
//			//90,91,92.....98,99 - 10个
//			//得到的结果应该是10+10.
//			//正确表达应该写两个并列的if
//		if(i%10==9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//}

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//		//跳过偶数：i=101;i<=200;i+=2
//	{
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//			//或者是j<=i/2   sqrt(i)<i/2
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i))
//		{	
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}