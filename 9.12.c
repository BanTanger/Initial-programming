#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//==============函数传参==========函数指针===========
//Add(int a, int b)
//{
//	int z = a + b;
//	return z;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int Add(a, b);
//	int (*p)(int, int) = Add;//只用指出传参的类型即可，不必写出参数，在打印时可自由调整参数。
//	printf("%d\n", (*p)(2, 5));
//	return 0;
//}
//
//void Print(char* str)
//{
//	printf("%s\n", str);
//}
//
//int main()
//{
//	void (*p)(char*) = Print;
//	(*p)("Hallo bit");
//	return 0;
//}
//
//
////====================计算器改版====================
//void menu()
//{
//	printf("***********************************\n");
//	printf("**       1.Add        2.Sub      **\n");
//	printf("**       3.Mul        4.Div      **\n");
//	printf("**       5.Xor        0.exit     **\n");
//	printf("***********************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//int main()
//{
//	int* arr[5];
//	int(*parr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请输入操作数以便选择:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("请输入:>");
//			scanf("%d%d", &x, &y);
//			int ret = (*parr[input])(x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("输入错误\n");
//		}
//	} while (input);
//	return 0;
//}
//====================计算器====================
//void menu()
//{
//	printf("***********************************\n");
//	printf("**       1.Add        2.Sub      **\n");
//	printf("**       3.Mul        4.Div      **\n");
//	printf("**       5.Xor        0.exit     **\n");
//	printf("***********************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void Calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个数以便于您想要的计算:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//
//int main()
//{
//	int* arr[5];
//	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };
//	int input = 0;
//	
//	do
//	{
//		menu();
//		printf("请输入操作数以便选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//
//	} while (input);
//	return 0;
//}
// 
// int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int* arr[5];
//	//int(*pa)(int, int) = Add;
//	int(*parr[4])(int, int) = { Add,Sub,Mul,Div };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", parr[i](2, 3));
//	}
//	return 0;
//}

//===============回调函数===========
//void print(char* str)
//{
//	printf("hehe:%s", str);
//}
//void test(void(*p)(char))
//{
//	printf("test\n");
//	p("bit\n");
//}
//int main()
//{
//	test(print);
//	return 0;
//}

//================比较函数================
int cmp(const void* e1,const void* e2)
{
	//实现函数比较
	return *(int*)e1 - *(int*)e2;
}

int main()
{
	int arr[10] = { 98,56,31,5,8,6,86,45,1,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\t", arr[i]);
	}
	return 0;
}
