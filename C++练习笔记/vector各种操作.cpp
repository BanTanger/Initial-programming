#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//封装打印函数的接口
//这里引用的原因涉及到引用本质，是const指针，可以防止对指向的修改
//用上引用之后比如写判断语句的==，如果少写一个=就会报错。
//使用引用也可以执行速度。节省空间
void printVector(vector<int>&v1) {
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}
void test() {
	vector<int>v1;//默认构造 无参构造

	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	//通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());
	//传入两个迭代器来输出中间的值
	printVector(v2);

	//n个elem方式构造
	vector<int>v3(10, 100);//pos1 = 个数，pos2 = 赋值
	//10个100的初始化；
	printVector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}

//赋值函数assign
void test2() {
	vector<int>v5;
	for (int i = 0; i < 10; i++) {
		v5.push_back(i);
	}
	printVector(v5);

	vector<int>v6;
	v6.assign(10, 100);
	printVector(v6);

	v6.assign(v5.begin(),v5.end());
	printVector(v6);
}

//capacity函数，调查vector容量
//size，调查vector大小
//resize，重新指定vector的大小
//empty，判断容器是否为空
void test3() {
	vector<int>v7;
	for (int i = 0; i < 10; i++) {
		v7.push_back(i);
	}
	printVector(v7);

	if (v7.empty())//为真 代表容器为空
		cout << "v7为空" << endl;
	else
	{
		cout << "v7不为空" << endl;
		cout << "v7的容量为：" << v7.capacity() << endl;
		cout << "v7的大小为：" << v7.size() << endl;
	}

	//重新指定大小。
	v7.resize(15,100);//利用重载版本，可以指定默认填充值，参数二必须是常量而不是变量
	printVector(v7);//如果重新指定的比原来长了，默认用0来填充
}

//插入和删除
void test4() {
	vector<int>v8;
	for (int i = 0; i < 10; i++) {
		v8.push_back(i);
	}
	printVector(v8);

	//尾删
	v8.pop_back();
	v8.pop_back();
	printVector(v8);

	//插入 参数1是迭代器，参数2是插入元素
	//如果有参数3，就是重载版本，此时参数2是插入元素的个数，参数3是插入元素值
	v8.insert(v8.begin(), 100);
	printVector(v8);

	v8.insert(v8.begin(), 2, 1000);
	printVector(v8);

	//删除
	v8.erase(v8.begin());
	printVector(v8);

	v8.erase(v8.begin(), v8.end());
	printVector(v8);//清除所有元素
}
int main() {
	//test();
	//test2();
	//test3();
	test4();
}