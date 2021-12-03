//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#define MAX 500
///*编写一个C程序，实现以下功能：
//用一个函数实现两个字符串的比较，即自己写一个strcmp函数，函数原型为：
//int strcmp(char *p1,char *p2);
//设p1指向字符串s1，p2指向字符串s2，要求当s1=s2时，函数返回值为0；如果s1≠s2，返回它们二者第一个不相同字符的ASCII码差值（如“BOY”与“BAD”，第二个字母不相同，“O”与“A”之差为79-65=14）；如果s1>S2，则输出正值；如s1<s2则输出负值。
//*/
//
//int strcmp(char* p1, char* p2) {
//	int max = strlen(p1) > strlen(p2) ? strlen(p1) : strlen(p2);
//	int min = strlen(p1) + strlen(p2) - max;
//	int p;
//	p = 0;
//	//长度
//	if (strlen(p1) == strlen(p2))
//	{
//		for (int i = 0; i < max; i++) {//这里用max还是min还是strlen都一样
//			//字母的ascii
//			if (p1[p] != p2[p])
//				return abs(p1[p] - p2[p]);
//			else {
//				p++;
//			}
//		}
//		return 0;
//	}
//	else
//	{
//		while (p != min) {
//			if (p1[p] != p2[p])
//				return abs(p1[p] - p2[p]);
//			p++;
//		}
//	}
//}
//int main() {
//	char str01[MAX], str02[MAX];
//	gets(str01);
//	gets(str02);
//	char tmp = strcmp(str01,str02);
//	printf("%d", tmp);
//}