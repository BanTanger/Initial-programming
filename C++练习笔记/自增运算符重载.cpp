#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//重载递增运算符

class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger& myint);
public:
	MyInteger() {
		m_Num = 0;
	}
	//重载前置++
	MyInteger& operator++() {
		m_Num++;
		//现在这里进行一次自增的操作，使得返回值加一
		
		return *this;//自身作为返回
		//返回引用&是为了确保一直对一个数据进行递增操作，
	}
	//重载后置++
	MyInteger operator++(int) {//int代表占位参数，可以用于区分前置和后置递增
		//先 记录当时结构，
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//最后将记录结构做返回。
		return temp;
		//这里不能返回引用&，因为*this是放在局部变量temp里的。
		//出了函数之后栈区会被回收，无法寻址再访问回去。
	}

	//后置递增一定要返回值，前置递增一定要返回地址
private:
	int m_Num;
};
//重载左移运算符必须使用全局函数
ostream& operator<<(ostream& cout, MyInteger& myint) {
	cout << myint.m_Num;
	return cout;
}
void test() {
	MyInteger myint;

	cout << ++myint << endl;
	cout << ++(++myint) << endl;
}
void test02() {
	MyInteger myInt;

	cout << myInt++ << endl;
}
int main() {
	//test();
	test02();

}