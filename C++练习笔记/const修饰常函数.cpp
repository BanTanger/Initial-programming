//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Person {
//public:
//	//this指针的本质，是指针常量，指针的指向是不可以被修改的，
//	//this == Person* const this 确定指针指向
//	//void showPerson() == const Person* const this 确定指针指向并且值也不允许修改
//	void showPerson()const
//	{
//		//this -> m_A = 100;
//		//this = NULL;//this指针不可以修改指针指向
//		this->m_B = 100;
//	}
//	void func() {
//		
//	}
//	int m_A;
//	mutable int m_B;//特殊变量，在常函数中，通过mutable关键词。
//};
//void test() {
//	Person p;
//	p.showPerson();
//}
////常对象
//void test2() {
//	const Person p;
//	p.m_A = 100;
//	p.m_B = 100;
//
//	//常对象只能调用常函数
//	p.showPerson();
//	p.func();
//}
//int main()
//{
//	test();
//}