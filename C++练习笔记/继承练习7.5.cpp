//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Shape {
//public:
//	Shape() {}
//	~Shape() {}
//	virtual float getArea(){return -1;}
//};
//class Rectangle:public Shape {
//public:
//	Rectangle(float len, float width) :m_Weight(width), m_Long(len) {}
//	~Rectangle() {}
//	virtual float getArea() { return m_Long * m_Weight; }
//private:
//	float m_Long;
//	float m_Weight;
//};
//class Circle :public Shape{
//public:
//	Circle(float r) :m_Radius(r) {}
//	~Circle() {}
//	float getArea() { return 3.14 * m_Radius * m_Radius; }
//private:
//	float m_Radius;
//};
//class Square :public Rectangle {
//public:
//	Square(float len);
//	~Square() {}
//};
//Square::Square(float len):Rectangle(len, len) {}
//void test() {
//	Shape* sp;
//	sp = new Circle(5);
//	cout << "CirleOfArea is " << sp->getArea() << endl;
//	delete sp;
//	sp = new Rectangle(4, 6);
//	cout << "RectangleOfArea is " << sp->getArea() << endl;
//	delete sp;
//	sp = new Square(5);
//	cout << "SquareOfArea is " << sp->getArea() << endl;
//	delete sp;
//}
//int main() {
//	test();
//}