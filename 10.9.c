#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 81
//=============gets函数的用法============

//int main()
//{
//	char name[MAX];
//	char* ptr;
//
//	printf("请输入名字：");
//	ptr = gets(name);//指针接收get的值；函数定义
//	printf("%s? ah! %s", name, ptr);
//	return 0;
//}

//=============fgets函数的用法============
int main()
{
	char name[MAX];
	char* ptr;

	printf("请输入名字：");
	ptr = fgets(name,MAX,stdin);//指针接收fget的值；
	//第二个参数定义大小，第三个参数定义读取哪个文件
	printf("%s? ah! %s", name, ptr);
	return 0;
}

