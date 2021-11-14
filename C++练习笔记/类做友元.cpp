//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
////类做友元
//class Building building;
//class GoodGay {
//public:
//	GoodGay();
//	void visit();//参观函数，访问Building的属性
//	Building* building;
//};
//class Building {
//	friend class GoodGay;
//public:
//	Building();
//
//public:
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
////类外写成员函数
//Building::Building() {
//	m_SittingRoom = "客厅";
//	m_BedRoom = "卧室";
//}
//GoodGay::GoodGay() {
//	building = new Building;
//}
//void GoodGay::visit() {
//	//：：意思是在某个作用域下的函数定义
//	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
//	cout << "好基友类正在访问：" << building->m_BedRoom << endl;
//}
//int main() {}