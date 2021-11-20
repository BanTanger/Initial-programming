//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//void myPoint(int val) {
//	cout << val << endl;
//}
//void test01() {
//	vector<int> v;
//
//	//插入数据
//	v.push_back(10);v.push_back(50);v.push_back(40);v.push_back(30);
//
//	//通过迭代器来访问容器数据
//	vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器第一个元素
//	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器最后一个的下一个
//
//	//数据的输出
//	/*while (itBegin != itEnd) {
//		cout << *itBegin << endl;
//		itBegin++;
//	}*/
//
//	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//		cout << *it << endl;*/
//
//	//遍历算法；#include<algorithm>标准算法头文件
//	for_each(v.begin(), v.end(), myPoint);
//	//起始点，终点，操作函数名。
//}
//int main()
//{
//	test01();
//}