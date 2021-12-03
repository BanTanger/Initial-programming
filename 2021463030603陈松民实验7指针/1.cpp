//#define _CRT_SECURE_NO_WARNINGS 1
///*编写C语言代码，实现以下功能：
//从键盘输入10个整数（在main函数中完成这个功能），求这10个整数的最大值和序号（要求编写一个以指针作为参数的函数来完成这个功能，不允许用数组。）。然后在main函数中输出最大值和序号。
//*/
//#include<stdio.h>
//#define MAX 20
//
//void func(int* arr, int n,int* max,int *j) {
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > *max) {
//			*max = arr[i];
//			*j = i;
//		}
//	}
//}
//int main() {
//	int n,m;
//	int arr[MAX];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	int j = 0;
//	func(arr,n,&max,&j);
//	printf("%d %d", max, j);
//}