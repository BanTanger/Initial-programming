#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = a & b;
//	printf("%d", c);
//}
//int main()
//{
//	int a = -1;
//	int b = a << 1;
//	printf("%d", b);
//}

//加减法，会溢出
//异或法

int main()
{
	int a = 3;
	int b = 5;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d", a, b);
	return 0;
}