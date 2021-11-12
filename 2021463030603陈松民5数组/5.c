#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 20
//不用数组操作/
//int main()
//{
//	int i = 0,number = 0,character = 0;
//	char ch;
//	while ((ch = getchar()) != '\n') {
//		if (ch <= '9' && ch >= '0')
//			number++;
//		else if (ch <= 'z' && ch >= 'a')
//			character++;
//		else
//			continue;
//	}
//	printf("单词%d 数字%d", number, character);
//}

//int main()
//{
//	int number = 0, character = 0;
//	char str[MAX];
//	gets(str);
//	for (int i = 0; i < MAX; i++)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//			number++;
//		else if (str[i] >= 'a' && str[i] <= 'z')
//			character++;
//		else
//			continue;
//	}
//	printf("数字%d 单词%d", number, character);
//}