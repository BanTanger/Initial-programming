//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person {
//
//public:
//	Person(string name, int age)
//	{
//		this->m_age = age;
//		this->m_name = name;
//	}
//
//	int m_age;
//	string m_name;
//};
//template<class T>
//bool myCompare(T& a, T& b) {
//	if (a == b)
//		return true;
//	else
//		return false;
//}
//
////利用具体化Person的版本代码，具体化优先调用
//template<>bool myCompare(Person& p1, Person& p2) {
//	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
//		return true;
//	else
//		return false;
//}
//void test1() {
//	int a = 10;
//	int b = 20;
//	bool ret = myCompare(a, b);
//	if (ret)
//		cout << "a==b" << endl;
//	else
//		cout << "a!=b" << endl;
//}
//void test2() {
//	Person p1("tom", 10);
//	Person p2("tom", 10);
//	bool ret = myCompare(p1, p2);
//	if (ret)
//		cout << "a==b" << endl;
//	else
//		cout << "a!=b" << endl;
//}
//int main()
//{
//	test1();
//	test2();
//}