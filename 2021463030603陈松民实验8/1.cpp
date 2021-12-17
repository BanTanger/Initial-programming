//#define _CRT_SECURE_NO_WARNINGS 1
///*编写C语言代码，实现以下功能：
//输入平面上两个点P1(x1,y1)和P2(x2,y2)的坐标，
//以这两个点为左上角和右下角可以确定一个矩形，
//输出这个矩形的周长。要求平面上点的坐标和矩形都用结构体来表示。
//*/
//
//#include<stdio.h>
//#include<cmath>
//struct Point {
//	int x;
//	int y;
//};
//struct Rectangle {
//	int width;
//	int length;
//};
//int main() {
//	struct Point P1;
//	struct Point P2;//结构体获得两个点对象。
//	printf("输入P1,P2的X,Y坐标\n");
//	scanf("%d%d%d%d", &P1.x, &P1.y, &P2.x, &P2.y);
//	struct Rectangle p;//矩形对象。
//	p.length = abs(P1.x - P2.x);
//	p.width = abs(P1.y - P2.y);
//	int Perimeter = 2 * (p.width + p.length);
//	printf("%d\n", Perimeter);
//}