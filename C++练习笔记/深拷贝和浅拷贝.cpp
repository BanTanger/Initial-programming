//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//class Person {
//
//public:
//	Person(int age,int height) {
//		m_height = new int(height);
//		m_age = age;
//
//	}
//	~Person() {
//	//析构函数一般用来销毁堆区的数据
//		if (m_height == NULL) {
//			delete m_height;
//			m_height = NULL;
//		}
//	}
//	int m_age;
//	int* m_height;
//};
//void test() {
//	Person p1(10, 160);
//	cout << "年龄" << p1.m_age << "身高" << *p1.m_height << endl;
//	Person p2(p1);
//	cout << "年龄" << p2.m_age << "身高" << *p2.m_height << endl;
//}
//int main()
//{
//	test();
//}