//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Person {
//public:
//	static void func() {
//		m_A = 100;//静态成员函数可以访问静态的成员变量
//		m_B = 100;//静态成员函数不可以访问非静态成员变量
//		cout << "static void func的调用" << endl;
//	}
//	static int m_A;//静态成员变量类内声明，类外初始化
//	int m_B;
//
//	//静态成员函数有访问权限；
//private:
//	static void func2() {
//		cout << "static void func2的调用" << endl;
//	}
//};
//int Person::m_A = 0;//初始化操作
////两种访问方式
//void test() {
//	//1.通过对象来访问
//	Person p;
//	p.func();
//	//2.通过类名来访问
//	Person::func();
//
//	//
//	Person::func2();//类外访问不到私有静态函数成员；
//}
//int main() {
//	test();
//}