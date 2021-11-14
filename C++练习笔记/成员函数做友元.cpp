#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Building;
class GoodGay {
public:
	GoodGay();
	void visit();//可以访问私有
	void visit02();//不允许访问私有
	Building* building;
};
class Building{
	friend void GoodGay::visit();
	//成员函数作为友元的写法
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};
Building::Building() {
	m_BedRoom = "卧室";
	m_SittingRoom = "客厅";
}
GoodGay::GoodGay() {
	building = new Building;
}
void GoodGay::visit() {
	cout << "visit正在访问 ：" << building->m_SittingRoom << endl;
	cout << "visit正在访问 ：" << building->m_BedRoom << endl;
}
void GoodGay::visit02() {
	cout << "visit正在访问 ：" << building->m_SittingRoom << endl;
	//cout << "visit正在访问 ：" << building->m_BedRoom << endl;
}
void test() {
	GoodGay gg;
	gg.visit();
	gg.visit02();
}
int main() {
	test();
}