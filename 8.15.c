#include<stdio.h>
#include<string.h>

#include "add.h"//自定义头文件用”“

int main()
{
	char arr[] = "bit";
	int len = strlen(arr);
	printf("%d\n", len);
	return 0;
}

//==========================函数递归====================
//要求：输入1234，打印1 2 3 4
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf_s("%d", &num);
//	print(num);
//	return 0;
//
//}

//int main()
//{
//	printf("hehe\n");
//	main();
//		return 0;
//}

//int main()
//{
//	int a = 20;
//	int b = 10;
//	int sum = Add(a, b);
//	//函数调用
//	printf("%d\n", sum);
//	return 0;
//}


//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//	return 0;
//}

//int main()
//{
//	int len = 0;
//	len = strlen("abc");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abc"));//链式访问
//}

//void Add(int* p)
//{
//	(*p)++;
//}
//
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}

//============================判断函数=========================
//int binary_search(int arr[], int k,int sz){
//	//算法的实现：
//	int left = 0;
//	int right = sz-1;//不能在传参的过程中输入元素个数
//    while(left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k){
//			left = mid + 1;}
//		else if (arr[mid] > k){
//			right = mid - 1;}
//		else{
//			return mid;}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 7;
//	int ret = binary_search(arr,k,sz);
//	if (ret == -1){
//		printf("找不到指定的数字\n");}
//	else{
//		printf("找到了，下标是：%d\n", ret);}
//	return 0;
//}
//int binary_search(int arr[], int k,int sz)
//{
//	//算法的实现：
//	int left = 0;
//	int right = sz-1;//不能在传参的过程中输入元素个数
//    while(left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	int k = 7;
//	int ret = binary_search(arr,k,sz);
//	if (ret == -1)
//	{
//		printf("找不到指定的数字\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	return 0;
//}

//int is_prime(int n)//=====================素数=================
//{
//	//是素数返回1，不是素数返回0
//	int z = 0;
//	for (z = 2; z <= n / 2; z++)
//	{
//		if (n % z == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)//prime factor素数因子
//			printf("%d ", i);
//	}
//	return 0;
//}

//int is_leap_year(int y)//-================闰年================
//{
//	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		//判断year是否为闰年
//		if (is_leap_year(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//============================交换函数=========================
//void Swap(int x, int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//Swap2(int* pa, int* pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//
//	printf("a=%d b=%d\n", a, b);
//	//Swap1(a,b);
//	Swap2(&a, &b);
//	
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}