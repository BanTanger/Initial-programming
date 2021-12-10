#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Point {
public:
	Point(int x, int y) :x(x), y(y) {}
	Point& operator++() {
		x++, y++;
		return *this;
	}
	Point operator++(int) {//∫Û÷√
		Point p = *this;
		++(*this);
		return p;
	}
	int x;
	int y;
};
ostream& operator<<(ostream& cout, Point& p) {
	cout << p.x <<" "<< p.y << endl;
	return cout;
}
int main() {
	Point p(1,2);
	cout << p << endl;
	cout << ++p << endl;
	//cout << p.operator++() << endl;
}