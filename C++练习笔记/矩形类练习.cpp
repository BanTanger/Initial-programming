//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Rectangle {
//public:
//	Rectangle(int L = 0, int W = 0);
//	void getRectangleArea();
//private:
//	int m_Long;
//	int m_Weight;
//};
//Rectangle::Rectangle(int L,int W) {
//	m_Long = L;
//	m_Weight = W;
//}
//void Rectangle::getRectangleArea() {
//	int S;
//	S = m_Long * m_Weight;
//	cout << S << endl;
//}
//void test() {
//	int L, W;
//	cout << "长度";
//	cin >> L;
//	cout << "宽度";
//	cin >> W;
//	Rectangle p(L,W);
//	p.getRectangleArea();
//}
//int main() {
//	test();
//}

//class Rectangle
//{
//public:
//	Rectangle(float len, float width)
//	{
//		Length = len;
//		Width = width;
//	}
//	~Rectangle() {};
//	float GetArea() { return Length * Width; }
//	float GetLength() { return Length; }
//	float GetWidth() { return Width; }
//private:
//	float Length;
//	float Width;
//};
//void main()
//{
//	float length, width;
//	cout << "请输入矩形的长度：";
//	cin >> length;
//	cout << "请输入矩形的宽度：";
//	cin >> width;
//	Rectangle r(length, width);
//	cout << "长为" << length << "宽为" << width << "的矩形的面积为："<< r.GetArea() << endl;
//}