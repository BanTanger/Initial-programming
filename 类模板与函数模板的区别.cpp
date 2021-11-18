//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
////类模板可以在参数列表中有默认参数
//template<class NameType, class AgeType = int>
//class Person {
//public:
//	Person(NameType name, AgeType age) {
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//	void showPerson() {
//		cout << "name:" << this->m_Name << endl << "age:" << this->m_Age;
//	}
//	AgeType m_Age;
//	NameType m_Name;
//};
////类模板没有自动类型推导。
//void test() {
//	Person<string, int> p1("你妈逼", 60);//通过模板参数列表给函数传值
//	Person p1("你妈逼", 60);
//	p1.showPerson();
//}
//void test2() {
//	Person<string> p1("你妈逼", 60);
//}
//int main()
//{
//	test();
//}