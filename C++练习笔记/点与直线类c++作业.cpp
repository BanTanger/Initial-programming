#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Point {
public:
	Point(double x = 0,double y = 0):x(x),y(y) {}
	Point(const Point& p) :x(p.x), y(p.y) {}
	~Point() {}	
public:
	double x;
	double y;
};
class Line :public Point{
	/*friend Point setPoint(Line& l1, Line& l2);*/
public:
	Line GetLine(Point Source, Point Destination);
	Point setPoint(Line& l1, Line& l2);
	double LineA() { return a; }
	double LineB() { return b; }
	double LineC() { return c; }
	void Show(Point p);
private:
	double a;
	double b;
	double c;
};
Point Line::setPoint(Line& l1, Line& l2) {
	Point ptemp;
	double D;
	D = l1.LineA() * l2.LineB() - l2.LineA() * l1.LineB();
	ptemp.x = (l1.LineB() * l2.LineC() - l2.LineB() * l1.LineC()) / D;
	ptemp.y = (l1.LineC() * l2.LineA() - l2.LineC() * l1.LineA()) / D;
	return ptemp;
}
Line Line:: GetLine(Point Source, Point Destination) {
	Line ltemp;
	ltemp.a = Source.y - Destination.y;
	ltemp.b = Destination.x - Source.x;
	ltemp.c = Source.x*Destination.y - Destination.x*Source.y;
	return ltemp;
}
void Line::Show(Point p) {
	cout << "(" << p.x << "," << p.y << ")" << endl;
}
int main() {
	Line l;
	double x0, x1, x2, x3, y0, y1, y2, y3;
	char str1, str2, str3;
	while (1) {
		cout << "直线A的起点到终点:";
		cin >> str1 >> x0 >> str2 >> y0 >> str3 >> str1 >> x1 >> str2 >> y1 >> str3;
		cout << "直线B的起点到终点:";
		cin >> str1 >> x2 >> str2 >> y2 >> str3 >> str1 >> x3 >> str2 >> y3 >> str3;
		Line a = l.GetLine(Point(x0, y0), Point(x1, y1));
		Line b = l.GetLine(Point(x2, y2), Point(x3, y3));
		cout << "两直线交点坐标为：";
		l.Show(l.setPoint(a, b));
	}
}