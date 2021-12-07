//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<assert.h>
//using namespace std;
//
////点类的实现
//class Point {
//public:
//	Point() :m_x(0), m_y(0) { count++; }
//	Point(int x, int y) :m_x(x), m_y(y) { count++; }//构造函数用来初始化。
//	~Point() { count--; }//析构函数的调用。
//	static void getcount() {
//		cout << count << endl;
//	}
//	int move(int newX, int newY) {
//		m_x = newX;
//		m_y = newY;
//	}
//private:
//	int m_x;
//	int m_y;
//	static int count;
//};
////动态数组的实现
//class ArrayOfPoint {
//public:
//	ArrayOfPoint(int size) :size(size) {
//		points = new Point[size];
//	}
//	~ArrayOfPoint() {
//		cout << "Delect...." << endl;
//		delete[]points;
//	}
//	Point& element(int index) {
//		assert(index >= 0 && index <= size);
//		return points[index];
//	}
//private:
//	int size;
//	Point* points;//指向Point类的首地址，在public里实现Point类数组的实现，动态申请内存
//};
//int Point::count = 0;//类外实现静态成员变量的初始化。
//int main() {
//	int n = 0;
//	Point a(4, 3);
//	//cout << "input" << endl;
//	//cin >> n;//键入点的个数
//	/*for (int i = 0; i < n; i++) {
//		int x, y;
//		cin >> x >> y;
//		Point(x, y);
//	}
//	Point b(a);
//	Point::getcount();*/
//	cout << "input";
//	cin >> n;//键入点的个数
//	ArrayOfPoint points(n);//创建数组对象。
//	points.element(0).move(5, 0);//访问数组下标为0的元素。
//	points.element(1).move(10, 5);//访问数组下标为1的元素。
//	
//}
