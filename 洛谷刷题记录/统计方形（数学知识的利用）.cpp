//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//int main(){
//	int n, m;
//	cin >> n >> m;
//	//所有的方形数
//	int SquarenessAll = n * m * (n + 1) * (m + 1) / 4;
//	//所有正方形
//	int SquareAll = 0;
//	//正方形的个数是最小边界min（n,m）×最大边界max（n,m），通过for循环去递减边长
//	//正方形边长一开始定义成最小边界，然后不断递减到1.
//	for (int i = 0; i < n; i++) 
//		SquareAll += (min(n, m) - i) * (max(n, m) - i);
//	//所有长方形
//	int RectangleAll = SquarenessAll - SquareAll;
//
//	cout << SquareAll << " " << RectangleAll << endl;
//}