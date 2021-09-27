#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//======指针实现判断大小端===
//int cleck()
//{
//	int a = 1;
//   return *(char*)&a;
//   //取出a的地址，然后再强制类型转化成char
//   //这样4个字节变成1个字节，就可以判断大小端。
//}
//int main()
//{
//	int a;
//	int ret = cleck();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else if (ret == 0)
//	{
//		printf("大端\n");
//	}
//	return 0;
//}
//======联合体实现判断大小端=====
//int cleck()
//{
//	union Un
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//int main()
//{
//	int a;
//	int ret = cleck();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else if (ret == 0)
//	{
//		printf("大端\n");
//	}
//	return 0;
//}