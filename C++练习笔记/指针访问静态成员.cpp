#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Point {

public:
	Point(int x, int y) :m_x(x), m_y(y) { count++;}
	Point(const Point& p) :m_x(p.m_x), m_y(p.m_y) { count++; }
	~Point() { count--; }
	static void getcount() {
		cout << count << endl;
	}
private:
	int m_x;
	int m_y;
	static int count;
};
int Point::count = 0;
int main() {
	void (*funcptr)() = Point::getcount;
	Point a(4, 5);
	funcptr();
	Point b(a);
	funcptr();
}