//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
///*编写一个C程序，实现以下功能：
//   编写递归函数，求解 x^n。其中n为整数，x不等于0。
//在main函数输入x和n，输出x^n的求解结果。
//*/
//
//int fun(int x, int n) {
//	if (n == 1) return x;
//	else return fun(x, n - 1) * x;
//}
//int main() {
//	int x, n;
//	scanf("%d%d", &x, &n);
//	int ans = fun(x,n);
//	printf("%d", ans);
//}