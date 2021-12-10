//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Shape {
//public:
//	virtual float getArea() { return -1; }
//	virtual float getPerim() { return -1; }//使用浮点型，必须要返回一个值，这里返回一个-1来回弹报错情况。
//};
//class Rectangle:public Shape {
//public:
//	Rectangle(float len, float width) :Long(len), Width(width) {}
//	~Rectangle() {}
//	virtual float getArea() { return Long * Width; }
//	virtual float getPerim() { return 2 * (Long + Width); }
//private:
//	float Long;
//	float Width;
//};
//class Circle :public Shape {
//public:
//	Circle(float r) :Radius(r) {}
//	~Circle() {}
//	float getArea() { return 3.14 * Radius * Radius; }
//	float getPerim() { return 3.14 * 2 * Radius; }
//	//基类函数前面加入vistual之后子类可以不用在写virtual，继承的时候也不需要
//private:
//	float Radius;
//};
//void test() {
//	Shape* sp;
//	sp = new Circle(5);
//	cout << "CircleArea = " << sp->getArea() << endl;
//	cout << "CirclePerim = " << sp->getPerim() << endl;
//	delete sp;
//	sp = new Rectangle(4, 6);
//	cout << "RectangleArea = " << sp->getArea()<< endl;
//	cout << "RectanglePerim = " << sp->getPerim() << endl;
//	delete sp;
//}
//int main() {
//	test();
//}