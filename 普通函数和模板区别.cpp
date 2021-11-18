//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////自动类型推导不可以发生隐式类型转换
////显示指定推导可以
//
////普通函数优先调用，函数模板想要调用需要空模板
//void test(int a,int b) {
//	cout << "普通" << endl;
//}
//template<class T>
//void test(T a, T b) {
//	cout << "模板" << endl;
//}
//
//template<class T>
//void test(T a, T b,T c) {
//	cout << "重载模板" << endl;
//}//函数模板重载
//void test03() {
//	int a = 10;
//	int b = 20;
//	//test(a,b);//普通优先调用。
//	//test<>(a, b);//空模板函数模板调用
//	//test(a, b, 100);
//
//	//如果模板能更好匹配，则调用模板。
//	char c1 = 'a';
//	char c2 = 'b';
//	test(c1,c2);
//}
//int main() {
//	test03();
//}