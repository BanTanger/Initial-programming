//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Preson {
//public:
//	Preson() {
//		cout << "Person的默认构造函数调用" << endl;
//	}
//	Preson(int a) {
//		cout << "Person的有参构造函数调用" << endl;
//		m_age = a;
//	}
//	Preson(const Preson& p) {
//		cout << "Person的拷贝构造函数调用" << endl;
//		m_age = p.m_age;
//	}
//	~Preson() {
//		cout << "Person的析构函数调用" << endl;
//	}
//	
//	int m_age;
//};
////1.使用一个已经创建的对象来初始化一个新对象
//void test() {
//	Preson p1(20);
//	Preson p2(p1);
//	cout<<"P2的年龄是 " << p2.m_age << endl;
//}
//
////2.值传递方式给函数参数传值
//void doWork(Preson p) {
//
//}
//void test02() {
//	Preson p;
//	doWork(p);
//}
//
////3.值方式返回局部对象
//Preson doWork2() {
//	Preson p1;
//	return p1;
//}
//void test03() {
//	Preson p = doWork2();
//}
//int main()
//{
//	//test02();
//	test03();
//}