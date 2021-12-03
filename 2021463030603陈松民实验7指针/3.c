//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
///*编写一个C程序，实现以下功能：
//   编写一个函数strmcpy(s,t,m)，该函数将字符串t中从m个字符开始的全部字符复制到字符串s中去。在主程序中输入一个字符串t和一个开始位置m，调用strmcpy(s,t,m)函数，然后输出字符串s的结果。例如：输入字符串liwangzhajinxiao和开始位置2，输出：wangzhajinxiao。
//*/
//#define MAX 500
//char s[MAX], t[MAX];
//void strmcpy(char* s, char* t, int m) {
//	int q = m;
//	int i = 0;
//	while (t[q] != '\0') {
//		s[i++] = t[q++];
//	}
//	s[i] = '\0';
//}
//int main() {
//	int m;
//	scanf("%d", &m);
//	getchar();
//	gets(t);
//	strmcpy(s, t, m);
//	printf("%s", s);
//}