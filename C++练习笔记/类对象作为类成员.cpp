#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//类对象作为类成员的时候，是先调用成员类的
class Phone {
public:
	Phone(string pName) {
		cout << "Phone的构造函数调用" << endl;
		m_PName = pName;
	}
	string  m_PName;

};
class Person {
public:
	Person(string name, string pName) :m_Name(name), m_Phone(pName) {
		cout << "Person的构造函数调用" << endl;
	}
	string m_Name;
	Phone m_Phone;
};
void test() {
	Person p("张三","苹果MAX");
	cout << p.m_Name << "拿着" << p.m_Phone.m_PName<<endl;
	Person p1("李四", "华为");
	cout << p1.m_Name << "拿着" << p1.m_Phone.m_PName << endl;
}
int main()
{
	test();
}