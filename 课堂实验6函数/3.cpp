//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#define MAX 20
///*编写一个C程序，实现以下功能：
//编写一个函数jugde(int b[],int n)，
//该函数能将一个一维整型数组调整为左右两边，
//凡是奇数均放左边，凡是偶数均放在右边。
//(注：奇、偶数的个数不一定相等）。
//*/
//
//void jugde(int b[],int n) {
//	int a[MAX];//a数组用来接收b数组的数（先奇数再偶数）
//	int j = 1;
//	for (int i = 1; i < n + 1; i++) {
//		if (b[i] % 2 != 0) {
//			a[j] = b[i];
//			j++;
//		}
//	}
//	for (int i = 1; i < n + 1; i++) {
//		if (b[i] % 2 == 0) {
//			a[j] = b[i];
//			j++;
//		}
//	}
//	for (int i = 1; i < n + 1; i++) {
//		printf("%d ", a[i]);
//	}
//}
//int main() {
//	int b[MAX];
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &b[i]);
//	}
//	jugde(b,n);
//}