#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define MAX 20000

//void compare(int* b,int m) {
//	for (int j = 0; j < m - 1; j++) {
//		for (int i = 0; i < m - 1 - j; i++) {
//			if (b[i] > b[i + 1])
//			{
//				int tmp = b[i + 1];
//				b[i + 1] = b[i];
//				b[i] = tmp;
//			}
//		}
//	}
//	for (int i = 0; i < m; i++)
//		cout << b[i]<<" ";
//}
//int main()
//{
//	int arr[MAX],b[MAX];//b数组用来筛选垃圾数字
//	int n, m,j = 0;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> arr[i];
//		if (arr[i] <= n) {
//			b[j] = arr[i];
//			j++;
//		}
//	}
//	compare(b,m);
//}

//桶排
//int n, m, a, b[MAX];
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) 
//		cin >> a, ++b[a];
//	for (int i = 0; i < MAX; i++)
//		while (b[i]--)
//			cout << i << " ";
//}