//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
////引用做函数参数
////void Swap(int& a, int& b) {
////	int tmp = a;
////	a = b;
////	b = tmp;
////}
////
////int main()
////{
////	int a = 10, b = 20;
////	Swap(a, b);//引用传递，形参会修饰实参
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////}
//
//
////引用做函数的返回值
////1.不要返回局部变量。
////int& test01() {
////	int a = 10;//局部变量，值保存在栈区，函数调用之后就会被释放，
////	return a;
////}
////
//////2.函数的调用可以作为左值
////int& test02()
////{
////	static int a = 10;//static使局部变量变成全局变量；
////	return a;
////}
////int main() {
////	int& ref1 = test01();//创建一个引用别名去接收函数的值；
////	cout << "ref1 = " << ref1 << endl;
////	cout << "ref1 = " << ref1 << endl;
////
////	int& ref2 = test02();
////	cout << "ref2 = " << ref2 << endl;
////	cout << "ref2 = " << ref2 << endl;
////
////	//作为左值
////	test02() = 1000;
////	cout << "ref2 = " << ref2 << endl;
////	cout << "test02 = " << test02() << endl;
////}
//
////打印数据函数，只是打印，不希望去改变实际值；
//void showValue(const int &a)
//{
//	//a = 1000;
//	cout << a;
//}
//
////常量引用 用来修饰形参防止误操作；
//int main()
//{
//	//int a = 10;
//	//语法糖 int temp = 10，const int& ref = temp;
//	//const int& ref = 10;
//	//int& ref = 10;//引用必须要有一块合法内存；
//	//ref = 20;
//	
//
//	int a = 100;
//	showValue(a);
//}