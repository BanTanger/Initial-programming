//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Cube {
//public:
//	//属性
//	void setH(int H) {
//		m_H = H;
//	}
//	void setL(int L) {
//		m_L = L;
//	}
//	void setW(int W) {
//		m_W = W;
//	}
//
//	int getH() {
//		return m_H;
//	}
//	int getL() {
//		return m_L;
//	}
//	int getW() {
//		return m_W;
//	}
//	//行为
//	//获取面积
//	int calculateS() {
//		return (m_L * m_W + m_H * m_L + m_H * m_W) * 2;
//	}
//	//获取体积
//	int calculateV() {
//		return (m_L * m_W * m_H);
//	}
//
//	//利用成员函数判断两个立方体是否相等
//	bool isSameByClass(Cube c) {
//		if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
//			return true;
//		else return false;
//	}
//private:
//	int m_L;
//	int m_H;
//	int m_W;
//};
//
//bool isSame(Cube& c1, Cube& c2) {
//	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
//		return true;
//	return false;
//}
//int main()
//{
//	//创建一个立方体对象
//	Cube c1;
//	c1.setH(10);
//	c1.setW(10);
//	c1.setL(10);
//
//	//cout << "面积：" << c1.calculateS() << endl;
//	//cout << "体积：" << c1.calculateV() << endl;
//	Cube c2;
//	c2.setH(10);
//	c2.setW(10);
//	c2.setL(12);
//
//	bool ret = isSame(c1,c2);
//	if (ret)
//		cout << "相等" << endl;
//	else
//		cout << "不相等" << endl;
//}