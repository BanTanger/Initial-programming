//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
///*编写C语言代码，实现以下功能：
//编写一个函数isPrime(int n),函数的功能是判断整数n是否是一个素数，
//当n为素数时，返回值为1，否则返回0。
//在主函数输入两个整数a和b,输出a和b之间（包含a，b）的所有素数。
//*/
//
//int isPrime(int n) {
//	int i = 0;
//	for (i = 2; i <= n / 2; i++) {
//		if (n % i == 0)
//			break;
//	}
//	if (i > n / 2 && i != 2) return 1;
//	else return 0;
//}
//int main() {
//	int a, b;
//	scanf("%d%d",&a,&b);
//	for (int i = a; i < b; i++) {
//		int flag = isPrime(i);
//		if (flag == 1)
//			printf("%d ", i);
//	}
//}