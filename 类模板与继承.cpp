//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
////1.类模板继承，需要在继承父类后加入参数列表
//template<class T>
//class Base {
//public:
//	T m;
//};
//class Son :public Base<int> {
//
//};
//void test02() {
//	Son s1;
//}
////子类变成类模板,灵活指定父类中T的类型
//template<class T1,class T2>
//class Son2 :public Base<T2> {
//	T1 bji;
//};
//void test() {
//	Son2<int,char> s2;
//}
//int main() {
//	test();
//}