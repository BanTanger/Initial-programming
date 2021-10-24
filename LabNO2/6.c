//#define _CRT_SECURE_NO_WARNINGS 1
////=====最大子序列积-====
//#include<stdio.h>
//#include<stdlib.h>
//
////int test(int* arr,int n,int* max)
////{
////	int i, j, temp;
////	for (i = 0; i < n - 1; i++)
////	{
////		for (j = 0; j < n - i - 1; j++)
////		{
////			if (arr[i] < arr[j + 1])
////			{
////				max[j] = arr[i] * arr[j];
////				if (max[j] <= max[j + 1])
////					max[j] = max[j + 1];
////			}
////			
////		}
////	}
////	return max[j];
////}
//int compare(int a, int b)
//{
//	int x = 0;
//	return x = (a > b) ? b : a;
//}
//int test(int* arr, int n,int (*compare)(int,int))
//{
//	int max = arr[0]; 
//	for (int i = 0; i < n; i++)//循环n趟；
//	{
//		int mul = 1; int weight = 1;
//		for (int j = i; j < n ; j++)
//		{
//			weight = j - i;
//			int len = compare(arr[i], arr[j]);
//			if(weight == 0)
//				mul = len * (weight + 1);
//			else
//				mul = len * weight;
//			if (mul > max)
//				max = mul;
//		}
//	}
//	return max;
//}
//int main()
//{
//	int arr[20] = { 1,8,6,2,5,4,8,3,7 };
//	int sz = 9;
//	int x = test(arr,sz,compare);
//	printf("%d", x);
//}