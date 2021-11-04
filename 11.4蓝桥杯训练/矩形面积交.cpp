//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//#define min(x,y) ((x)<(y)?(x):(y))
//#define max(x,y) ((x)>(y)?(x):(y))
//
//int main()
//{
//	double x1, x2, x3, x4;
//	double y1, y2, y3, y4;
//	double m1, n1;
//	double m2, n2;
//	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
//	scanf("%lf%lf%lf%lf", &x3, &y3, &x4, &y4);
//
//	//特别精妙啊卧槽。
//	m1 = max(min(x1, x2), min(x3, x4));
//	n1 = max(min(y1, y2), min(y3, y4));
//	//较大值矩形的最左下角。
//	m2 = min(max(x1, x2), max(x3, x4));
//	n2 = min(max(y1, y2), max(y3, y4));
//	//较小值矩形的最右上角。
//	if (m2 > m1 && n2 > n1)
//		printf("%.2lf", (m2 - m1) * (n2 - n1));
//	else
//		printf("0.00");
//}