//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person {
//	//成员函数实现运算符重载
//public:
//	/*Person operator+(Person& p) {
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//	int m_A;
//	int m_B;
//private:
//
//};
//
////全局函数实现重载
//Person operator+(Person& p1, Person& p2) {
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//Person operator+(Person& p1, int num) {
//	Person temp;
//	temp.m_A = p1.m_A + num;
//	temp.m_B = p1.m_B + num;
//	return temp;
//}
//void test() {
//	Person p1;
//	p1.m_A = 10;
//	p1.m_B = 20;
//	Person p2;
//	p2.m_A = 20;
//	p2.m_B = 10;
//	//Person p3 = p1 + p2;//简写模式
//	
//	//成员函数本质调用
//	//Person p3 = p1.operator+(p2);
//	
//	//全局函数的本质调用
//	//Person p3 = operator+(p1, p2);
//
//	//运算符重载也可以使用函数重载
//	Person p3 = p1 + 10;
//	cout << p3.m_A << endl;
//	cout << p3.m_B << endl;
//
//	
//}
//int main() {
//	test();
//}