#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 20
/*编写一个C程序，实现以下功能：
编写一个常规的函数和一个递归函数，两个函数均能将输入的一个字符串以按反序形式的字符串作为返回值。
在main函数中输入一行字符串，分别调用两个函数，输出反序后的字符串。
*/
void funcRecursion(char* str, int n) {

}
void func(char *str,int n) {
	int p, q;
	p = 0, q = n - 1;
	while (p <= q) {
		char tmp = str[p];
		str[p] = str[q];
		str[q] = tmp;
		p++; q--;
	}
	for (int i = 0; i < n; i++) {
		printf("%s", str[i]);
	}
}
int main() {
	char str[MAX];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c", &str[i]);
	}
	func(str,n);
	//funcRecursion(str,n);
}