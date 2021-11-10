//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
////函数默认参数
//
////如果传入自己的数据，就用自己的，如果没有用默认值
////语法 ：类型 函数名（形参 = 默认值）
//int func(int a,int b = 10)
//{
//	//cout << "you are beautiful" << endl;
//	return a + b;
//}
//
//int func2(int a, int b = 50, int c = 20) {
//	return a + b + c;
//}
//
////如果某个位置有默认参数，那这个位置往后也一定要默认；
//int func2(int a, int b = 50, int c) {
//	return a + b + c;
//}
//
////若函数声明有默认参数，那函数实现就不能有默认参数
////声明和实现只能有一个有默认参数。
//int func3(int a = 10, int b = 20);
//
//int func3(int a, int b) {
//	return a + b;
//}
//int main()
//{
//	int x = func(10, 10);
//	cout << x << endl;
//	int y = func2(10);
//	cout << y << endl;
//	int z = func3();
//	cout << z << endl;
//}
//
////函数重构
////1.在同一作用域（全局区，堆区，栈区，代码区）
////2.函数名称相同
////3.函数参数不同或者是个数不同，顺序不同。
////注意，不能是返回值不同。