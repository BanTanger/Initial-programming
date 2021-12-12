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
//push_back().尾插
//pop_back().尾删
//insert.插入
//erase.删除
//clear.清空
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
	printVector(v8);//清除所有元素 == v8.clear（）
}

void test5() {
	vector<int>v9;
	for (int i = 0; i < 10; i++) {
		v9.push_back(i);
	}
	printVector(v9);
	vector<int>v10;
	for (int i = 10; i > 0; i--) {
		v10.push_back(i);
	}
	printVector(v10);

	cout << "交换" << endl;

	v9.swap(v10);
	printVector(v9);
	printVector(v10);
}

void test6() {
	//swap的实际用途。用来收缩空间
	
	vector<int>v11;
	for (int i = 0; i < 1000000; i++) {
		v11.push_back(i);
	}
	cout << v11.capacity() << endl;
	cout << v11.size() << endl;

	//格式
	vector<int>(v11).swap(v11);//使得容量和大小一样。匿名对象。
	cout << v11.capacity() << endl;
	cout << v11.size() << endl;
}

void test7() {
	vector<int>v12;

	//利用reserve预留空间
	v12.reserve(1000000);
	int num = 0, * p = NULL;
	for (int i = 0; i < 1000000; i++) {
		v12.push_back(i);

		if (p != &v12[0]) {
			p = &v12[0];
			num++;
		}
	}
	cout << num << endl;

}
int main() {
	//test();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	//test7();
}
