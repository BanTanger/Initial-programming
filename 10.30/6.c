//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdbool.h>
//int main()
//{
//	int i, k, j, n, count = 1;
//	int t = 0; int A = 0, B = 0, C = 0;
//	int a[100] = { 0 }, b[100] = { 0 }, c[100] = { 0 } ;
//	scanf("%d%d%d%d", &i, &k, &j, &n);
//	int max = (i > j && i > k) ? i : ((j > k) ? j : k);
//	int T = (n - 1) * max;
//	//用数组
//	int x = 1;//计数变量
//	for (; x < n; x++)
//	{
//		A += i; a[A] = 1;
//		B += k; b[B] = 1;
//		C += j; c[C] = 1;
//	}
//	for (;t<=T; t++)
//	{
//		
//		if ((a[t] + b[t] + c[t]) >= 1)//同响记为响一次
//		{
//			count++;
//			continue;
//		}
//		else 
//			continue;
//	}
//	printf("%d", count);
//	return 0;
//}