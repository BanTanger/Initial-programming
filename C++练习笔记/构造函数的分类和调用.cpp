//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////构造函数的分类和调用
////分类 无参构造（默认构造）和有参构造
////     普通构造函数，拷贝构造函数
//class Person {
//public:
//	int age;
//	Person() {
//		cout << "Person的构造函数调用" << endl;
//	}
//	~Person() {
//		cout << "Person的析构函数调用" << endl;
//	}
//	Person(int a) {
//		age = a;
//	}
//	//拷贝
//	Person(const Person& p) {
//		age = p.age;
//	}
//};
////调用
//void test()
//{
//	//1.括号法
//	Person p;//默认构造函数调用
//	Person p1(10);//有参构造函数
//	Person p2(p1);//拷贝构造函数
//
//	//注意事项
//	//调用默认构造函数，不要加（），会被当成声明
//	Person p();
//
//	cout << "p1 的年龄是：" << p1.age << endl;
//	cout << "p2 的年龄是：" << p2.age << endl;
//	//2.显示法
//	Person p1;
//	Person p2 = Person(10);
//	Person p3 = Person(p2);
//
//	//Person(10);//匿名对象，特点，当前行执行结束后，系统会立即回收掉匿名对象。
//
//	//不要利用拷贝构造函数，初始化一个匿名对象。Person(p3)==Person p3
//
//	//3.隐式转换法
//	//Person p4 = 10;
//	//Person p4 = 10 == Person p4 = Person (10);
//}
//int main()
//{
//	test();
//}