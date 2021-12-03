//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#define MAX 33
///*编写一个C程序，实现以下功能：
//编写一个函数decTobin(int n)，该函数能将一个十进制数n转换成二进制数，输入13 输出 1101。
//在main函数中输入整数n,调用函数，输出它的二进制数。
//*/
//char s[MAX];
//void decTobin(int n) {
//	int i = 0;
//	while(n > 0)
//	{
//		if (n % 2 == 1) {
//			s[i] = 1;
//			i++;
//		}
//		else {
//			s[i] = 0;
//			i++;
//		}
//		n /= 2;
//	}
//	for(int j = i - 1;j>=0;j--)
//		printf("%d", s[j]);
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	decTobin(n); 
//}