//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
//class Person {
//public:
//	Person(int age) {
//		this->age = age;
//	}
//	//Person& PersonAddAge(Person& p) {
//	//	this->age += p.age;
//	//	return *this;//此时this指向的是p2整体
//	//}//通过引用返回的是本身对象，而不加引用就会创建出一个新的对象
//	Person PersonAddAge(Person& p) {
//		this->age += p.age;
//		return *this;//此时this指向的是p2整体
//	}
//	int age;
//};
//
////1.解决名称冲突
//void test() {
//	Person p(18);
//	cout << "p的年龄为：" << p.age << endl;
//}
//
////2.返回对象本身用*this
//void test2() {
//	Person p1(10);
//	Person p2(10);
//	//p2.PersonAddAge(p1);//拷贝构造函数初始化
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2的年龄为：" << p2.age << endl;
//}
//
//int main()
//{
//	//test();
//	test2();
//}