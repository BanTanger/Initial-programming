//#define _crt_secure_no_warnings 1
//#include<iostream>
//using namespace std;
////
////class myclass {
////public:
////	myclass() {}
////	myclass(int i) { value = new int(i); }
////	int* value;
////};
////int main() {
////	int var = 12;
////	int arr[3] = { 1,2,3 };
////	int* ptr = arr; // &符号解析了var的地址
////	// 使用指针访问变量的地址
////	cout << arr << " in address: " << ptr << endl;
////	// 使用指针访问变量的内容
////	cout << *ptr << endl;
////	// 使用指针修改变量的内容
////	*ptr = 13;
////	for(int i = 0;i<3;i++)
////		cout << *(arr+i) << endl;
////	// 修改指针本身的内容（修改指向）
////	//ptr = arr;// 数组的首地址就是用数组名来存储的
////	//cout << *ptr++ << ' ' << *ptr++ << ' ' << *ptr << endl;
////}
//
//class MyClass {
//public:
//	MyClass(int a) {
//		cout << a << " Constructor" << endl;
//		x = a;
//	}
//	~MyClass() { cout << x << " Destructor" << endl; }
//	void Show(MyClass my) {
//		cout << "Function:x = " << my.x << endl;
//	}
//private:
//	int x;
//};
//int main() {
//	int y = 10;
//	do {
//		y--;
//	} while (--y);
//	cout << y-- << endl;
//}