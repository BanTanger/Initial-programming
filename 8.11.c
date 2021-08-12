#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	int x, y;
//	for (x = 0, y = 0; x < 2 && y < 5; x++, y++)
//	{
//		printf("你是傻逼\n");
//	}
//		return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i = 5)
//			printf("wdnmd\n");
//		printf("%d ", i);
//	}
//	return 0;
//}

/*int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (i = 5)
			printf("wdnmd\n");
		printf("%d ", i);
	}
	return 0;
}*/


/*int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (5 == i)
			continue;
		printf("%d ", i);
	}
	return 0;
}*/

/*int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		if (5 == i)
			break;
		printf("%d ", i);
	}
}*/

/*int main()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{

		printf("%d ", i);
	}
}*/

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < 'a' || ch>'z')
//		   continue;
//		ch = ch - 32;
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//		 continue;
//		putchar(ch);
//	}
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}

int main()
{
	int ch = 0;
	char password[20] = { 0 };
	printf("请输入密码:>\n");
	scanf("%s", password);//输入密码，并存放在password的数组中
	while ((ch = getchar()) != '\n');
	printf("请确认（Y/N）:>");
	ch = getchar();
	if (ch == 'Y')
		printf("确认成功\n");
	else
		printf("确认失败\n");
		return 0;
}

// int main()
//{
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("请输入密码:>\n");
//	scanf("%s", password);//输入密码，并存放在password的数组中
//	getchar();
//	printf("请确认（Y/N）:>");
//	ch = getchar();
//	if (ch == 'Y')
//		printf("确认成功\n");
//	else
//		printf("确认失败\n");
//		return 0;
//}