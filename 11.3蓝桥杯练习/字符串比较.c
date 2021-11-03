#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int compare(char* str1, char* str2)
//{
//	char* p = str1, *q = str2;
//	//1.
//	if (strlen(str1) != strlen(str2)) return 1;
//	//2.3.4.
//	else if (strlen(str1) == strlen(str2)){
//		while (*p != '\0'&&*q != '\0')
//		{
//			if (*p == *q) {
//				p++;
//				q++;
//			}
//			else if (*p == '\0' && *q == '\0')	return 2;
//			else if (*(p + 32) == *q || *(q + 32) == *p || *(q - 32) == *p || *(p - 32) == *q)	return 3;
//			else return 4;
//		}
//		
//	}
//
//}
//int main()
//{
//	char* str1;
//	char* str2;
//	str1 = (char*)malloc(sizeof(100));
//	str2 = (char*)malloc(sizeof(100));
//	gets(str1);
//	gets(str2);
//	int x = compare(str1, str2);
//	printf("%d", x);
//}

//int main()
//{
//	int i, x = 2, n;
//	char a[10], b[10];
//	gets(a); gets(b);
//	n = strlen(a);
//	if (strlen(b) != n)x = 1;
//	else {
//		for (i = 0; i < n; i++) {
//			if (a[i] + 32 == b[i] || a[i] == b[i] || a[i] == b[i] + 32)
//			{
//				if (a[i] != b[i]) {
//					x = 3;
//					break;
//				}
//				else {
//					x = 2;
//					break;
//				}
//			}
//			else {
//					x = 4;
//					break;				
//			}
//		}
//	}
//	printf("%d", x);
//}