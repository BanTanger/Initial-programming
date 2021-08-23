#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//============================结构体==================================
struct Stu
{
	char name[10];
	int age;
	char id[20];
};

int main()
{
	int a = 0;
	struct Stu s1 = { "陈帆四届",18,"1314520" };
	printf("%s\n", s1.name);
	printf("%d\n", s1.age);
	printf("%s\n", s1.id);
	return 0;
}

//int main()
//{
//	int a = 1; 
//	int b = 2;
//	int c = (a > b, a = b + 10, a, b = a + 1);
//
//}

//int main()
//{
//	int a = 11;
//	a=a | (1 << 2);//|
//	printf("%d\n", a);
//	a = a &(~(1 << 2));//&
//	printf("%d\n", a);
//}

//int main()
//{
//	int a = 10;
//	short s = 0;
//	printf("%d\n", sizeof(s = a + 5));
//	printf("%d\n", s);
//}

//int main()
//{
//	int a = 0;
//	int arr[10] = { 0 };
//	char c = 'r';
//	char* p = &c;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(int));
//
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(int [10]));
//
//	printf("%d\n", sizeof(c));
//	printf("%d\n", sizeof(char));
//
//	printf("%d\n", sizeof(p));
//	printf("%d\n", sizeof(char*));
//}

//按位与手段
//int main()
//{
//	int i = 0;
//	int a = 0;
//	int count = 0;
//	scanf("%d",&a);
//	for (i = 0; i < 32; i++)
//	{
//		if (((a >> i) & 1 )== 1)
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}

//无法计算负数
//int main()
//{
//	int num = 0;
//	int count = 0;
//	scanf("%d", &num);
//	while(num)
//		if (num % 2 == 1)
//		{
//			num=num / 2;
//			count++;
//		}
//	printf("%d\n", count);
//	return 0;
//}