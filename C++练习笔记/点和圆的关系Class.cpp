//#include "点和圆的关系Class.h"
//#include<iostream>
//using namespace std;
//
//void isInCircle(Circle& c, Point& p) {
//	//计算两点距离的平方
//	int distance = pow((c.getCenter().getX() - p.getX()), 2) + pow((c.getCenter().getY() - p.getY()), 2);
//	//计算半径的平方
//	int rDistance = pow(c.getR(), 2);
//	if (rDistance == distance)
//		cout << "在圆上" << endl;
//	else if (rDistance > distance)
//		cout << "在原内" << endl;
//	else
//		cout << "在员外" << endl;
//}
//
//int main()
//{
//	//创建圆
//	Circle c;
//	c.setR(10);
//	Point center;
//	center.setX(10);
//	center.setY(0);
//	c.setCenter(center);
//	//建立坐标系。
//
//	//创建点
//	Point p;
//	p.setX(10);
//	p.setY(10);
//
//	//判断关系
//	isInCircle(c, p);
//}