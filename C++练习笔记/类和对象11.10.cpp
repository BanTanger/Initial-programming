#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//double PI = 3.14;
//class Circle{
//	//访问权限：
//	//公共权限 public   成员 类内可以访问，类外可以访问
//	//私有权限 private  成员 类内可以访问，类外不可以访问 子可以访问父中保护内容
//	//保护权限 protect	成员 类内可以访问，类外不可以访问 子不可访问
//public:
//
//	//属性：半径
//	int m_r;
//
//	//行为：获得元的周长
//	double calculateZC()
//	{
//		return 2 * PI * m_r;
//	}
//};
//
//int main()
//{
//	Circle C;
//	C.m_r = 10;
//
//	cout << "周长为：" << C.calculateZC() << endl;
//}

//学生类的创建
//class students {
//public:
//	string m_name;
//	int m_id;
//	void showStudents() {
//		cout << m_name << endl;
//		cout << m_id << endl;
//	}
//	void setName(string name) {
//		m_name = name;
//	}
//	void setId(int id) {
//		m_id = id;
//	}
//};
//int main()
//{
//	students stu1;
//	//stu1.m_name = "张三";
//	stu1.setName("张三");
//	//stu1.m_id = 123456789;
//	stu1.setId(13456);
//	stu1.showStudents();
//}

//class Pertorn {
//
//protected:
//	string m_Car;
//
//private:
//	int m_Password;
//
//public:
//	string m_Name;
//	void func()
//	{
//		m_Name = "张三";
//		m_Car = "拖拉机";
//		m_Password = 123546;
//	}
//};
//
//int main()
//{
//	Pertorn p;
//
//	p.m_Name = "零四";
//	//p.m_Car //保护权限内容无法访问；
//}