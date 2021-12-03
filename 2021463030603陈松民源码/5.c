//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define MAX 20
///*编写一个C程序，实现以下功能：
//编写一个常规的函数和一个递归函数，两个函数均能将输入的一个字符串以按反序形式的字符串作为返回值。
//在main函数中输入一行字符串，分别调用两个函数，输出反序后的字符串。
//*/
//void funcRecursion(char* str, int n) {
//	int i = 0;
//	i++;
//	int strTmp[MAX];
//	if (n == 1)
//		return printf("%s",str);
//	else {
//		strTmp[i] = str[n];
//		return funcRecursion(str, n - 1);
//	}
//}
//void func(char* str, int n) {
//	int p, q;
//	p = 0, q = n;
//	while (p <= q) {
//		char tmp = str[p];
//		str[p] = str[q];
//		str[q] = tmp;
//		p++; q--;
//	}
//	printf("%s", str);
//}
//int main() {
//	char str[MAX];
//	gets(str);
//	strlen(str);
//	func(str, strlen(str) - 1);
//	printf("\n");
//	funcRecursion(str, strlen(str) - 1);
//}