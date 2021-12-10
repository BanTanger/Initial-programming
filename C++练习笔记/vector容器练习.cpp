//#define _crt_secure_no_warnings 1
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
////输入两个数k，x，再输入一些升序的整数存到vector<int>中，
////其中找到与x的差为最小的第k个数并且按照升序输出，
////如果有两个数与x的差值相同，有限选择数据较小的那个，
////k的值为正数，而且总是小于给定排序数组的长度
//int main() {
//	int k, x,i;
//	vector<int> arr(10);//创建数组对象。
//	cin >> x >> k;
//	for (i = 0; i < 10; i++) {
//		cin >> arr[i];
//	}
//	nth_element(arr.begin(), arr.begin() + k, arr.end());
//	int min = arr[0];
//	int minposi = 0;
//	for (i = 0; i < 10; i++) {
//		if (arr[i] - x >= 0 && arr[i] - x <= min) {
//			min = arr[i] - x;
//			minposi = i;
//		}
//	}
//	cout << "第k小的数是" << k + minposi << endl;
//}