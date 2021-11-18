//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//template<class T>
//void mySwap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//template<class T>
//void Sort(T arr[], int len) {
//	for (int i = 0; i < len; i++) {
//		int max = i;
//		for (int j = i + 1; j < len; j++) {
//			if (arr[j] > arr[max])
//				max = j;//更新下标。
//		}
//		if (max != i)
//			mySwap(arr[max],arr[i]);
//	}
//}
//template<class T>
//void Point(T arr[],int len) {
//	for (int i = 0; i < len; i++) 
//		cout << arr[i] << " ";
//	cout << "\n";
//}
//void test() {
//	int arr[] = { 1,5,8,7,3,1,5,6,4,8,9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Sort(arr, len);
//	Point(arr, len);
//}
//void test2() {
//	char arr[] = "jadlnwdlagafe";
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Sort(arr, len);
//	Point(arr, len);
//}
//int main() {
//	test();
//	test2();
//}