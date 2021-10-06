#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define SPACE ' '
//int main()
//{
//	//使用getchar来实现打印空格，如果不是空格就转到下一个字符、
//	char ch;
//	printf("请输入一个字母（可大可小）");
//	ch = getchar();
//	while(ch != '\n')//多多调试啊，傻逼sb
//	{
//		if (ch == SPACE)
//			putchar(ch);
//		else
//			putchar(ch + 1);
//		ch = getchar();//获取下一个字符
//	}
//	putchar(ch);//打印换行字符。
//	
//	return 0;
//}

//int main()
//{
//	int ch;
//	while ((ch = getchar()) != '\n')
//	{
// //while(ch = getchar() != '\n')错误
//		;
//	}
//}

//密码编程
#include<ctype.h>   //提供isalpha（）函数，此函数只会读取字母，非字母字符自动跳过
int main()
{
	int ch;
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))//==if(isalpha(ch)==0)//如果是字母
			//putchar(ch + 1);//改变它
			//大写换小写函数tolower（）
			//小写换大写函数toupper（）
		{
			ch = tolower(ch);
			//ch = toupper(ch);
			putchar(ch);
		}
		else
			putchar(ch);//原样输出
	}
	putchar(ch);//换行操作。
	return 0;
}