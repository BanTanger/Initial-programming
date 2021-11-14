//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Building {
//	friend void goodGay(Building* building);//友元
//public:
//	Building() {
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	}
//public:
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//};
////全局函数
//void goodGay(Building* building) {
//	//*或者&，意思是传入一个对象，去访问他的属性
//	//其实本质上就是指针，所以调用函数应该传递地址
//	cout<<"好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
//	cout<<"好基友全局函数 正在访问：" << building->m_BedRoom << endl;
//}
//void test01()
//{
//	Building building;
//	goodGay(&building);
//}
//int main() { test01(); }