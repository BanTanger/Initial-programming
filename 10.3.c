#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char arr[20];
//	printf("请输入名字:>");
//	scanf("%s", &arr);
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	float a;
//	printf("\a输入:");
//	printf(" 要______\b\b\b\b\b\b");
//	scanf("%f", &a);
//	printf("\n\t%.2f 一个月薪水 和 一年之后的总薪水%.2f", a, a * 12);
//	printf("\r加油！\n");
//	return 0;
//}

//#define SCORE 10
//void print(int index, int score[SCORE])
//{
//	
//}
//int main()
//{
//	int index = 0;
//	int score[SCORE] = {0};
//	int sum = 0;
//	float average = 0;
//
//	//使用函数来包装
//	// 	   我用的函数有什么问题呢。为什么无法包装。得不到想要的结果
//	//print(index,score[SCORE]);
//	printf("请输入%d次高尔夫球得分情况:\n", SCORE);
//	for (index = 0; index < SCORE; index++)
//	{
//		scanf("%d", &score[index]);
//		//这里不太理解，为什么能读取第一次输入之后后面的元素
//		//是否这样理解，一开始数组下标为零，我用scanf输入一个值给下标零数组，然后下标往后递增
//		//因为更新了变量，for循环再一次执行scanf，但跳过\0，并且之前在缓冲区内的剩下9个数值依然保留
//		//所以不在需要输入，而是继续读取数值。
//		//按下enter建也要把10个值全输入完
//	}
//	printf("得分情况:\n");
//	for (index = 0; index < SCORE; index++)
//	{
//		printf("%5d", score[index]);
//	}
//	printf("\n");
//	for (index = 0; index < SCORE; index++)
//	{
//		sum += score[index];
//	}
//	average = (float)sum / SCORE;
//	printf("sum=%d,average=%.2f\n", sum, average);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int i = 0;
//	printf("请输入\n");
//	scanf("%d", &n);
//	for (i = 0; i < n-2; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n; j++)
//		{
//			printf("$");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	printf("请输入行数\n");
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("$");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	char ch[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for(;i<6;)
//		{
//			printf("%s", ch[i]);
//		}
//		printf("\n");
//	}
//}
// 
// int main()
//{
//	int n = 0;
//	char ch;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (ch = ('F' + i); ch < ('F'-i); ch++)//原来是我的编译器不支持
//			//只能使用数组并遍历元素。
//		{
//			printf("%c", ch);
//		}
//		printf("\n");
//	}
//}

//int main(void)
//{
//    char let = 'F';
//    char start;
//    char end;
//    //双指针
//    for (end = let; end >= 'A'; end--)
//    {
//        for (start = let; start >= end; start--)
//            printf("%c", start);
//        printf("\n");
//    }
//    return 0;
//}

int main()
{
	int index = 0;
	char ch[26] = "ABCDEFGHIJKLMNOPQRSTUVWSYZ";
	int n = 0;
	//=============倒序三角===========
	/*for (int i = 0; i <= n;i++)
	{
		for (index = n; index >= i; index--)
		{
			printf("%c", ch[index]);
		}
		printf("\n");
	}	*/

	//==============正序三角===========
	/*for (int i = 0; i <= n; i++)
	{
		for (index = 0; index <= i; index++)
		{
			printf("%c", ch[index]);
		}
		printf("\n");
	}*/

	//===========正三角===========
	//for (int i = 1; i < n; i++)
	//{
	//	//打印空格
	//	int j = 0;
	//	for (j = 1; j<=(n - i)-1; j++)
	//	{
	//		printf(" ");
	//	}
	//	//打印星号
	//	for (index = 0; index <2*i-1; index++)
	//	{
	//		printf("%c",ch[index]);
	//	}
	//	printf("\n");
	//}

	//============正三角（难度升级：要求回文输入）=============
	/*printf("请输入一个大写字母，以此为基础往下递减（直至到A）\n:>");
	scanf("%c", &ch[index]);
	for (n = 0; n < index; n++)
	{
		for()
	}*/

		int m, i, z, q;
		char x;
		scanf("%c", &x);

		n = x - 'A';

		for (m = 0; m < n + 1; m++)
		{
			for (i = 0; m < n - i; i++)
				printf(" ");
			for (z = 0; z <= m; z++)//执行完条件之后就会更新，不管是否再进入循环
				printf("%c", 'A' + z);
			for (q = 2; 'A' + z - q >= 'A'; q++)
				printf("%c", 'A' + z - q);
			printf("\n");
		}
	return 0;
}