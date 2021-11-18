//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//template<class NameType, class AgeType>
//class Person {
//public:
//	Person(NameType name, AgeType age);
//	void showPerson();
//	AgeType m_Age;
//	NameType m_Name;
//};
//
//template<class NameType, class AgeType>
//Person<NameType, AgeType>::Person(NameType name, AgeType age)
//{
//	this->m_Age = age;
//	this->m_Name = name;
//}
//
//template<class NameType, class AgeType>
//void Person<NameType, AgeType>::showPerson() {
//	cout << "name:" << this->m_Name << endl << "age:" << this->m_Age;
//}
//
//void test() {
//	Person<string, int> p1("你妈逼", 60);//通过模板参数列表给函数传值
//	p1.showPerson();
//}
//
//int main()
//{
//	test();
//}