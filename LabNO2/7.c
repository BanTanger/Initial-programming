//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//int n = 1000;
//float x,S = 0.0;
//float func(float A,float B,float (*fun)(float x))
//{
//	float SumS = 0.0;
//	float num = (B - A) / n;//区间定义份数；
//	x = A;//定义x；
//	A = (*fun)(x);//上底长；
//	for (int i = 1; i <= n; i++)
//	{
//		x += num;//往右走
//		B = (*fun)(x);
//		S = (A + B)*num / 2;
//		A = B;//循环实现底边转换。计算下一个面积
//		SumS += S;
//	}
//	return (SumS);
//}
//float fun(float x)
//{
//	float y = x * x * x + x * x + x + 1;
//	return y;
//}
//int main()
//{
//	float A, B ;
//	scanf("%f%f", &A, &B);
//	float SumS = func(A,B,fun);
//	printf("%f", SumS);
//	return 0;
//}