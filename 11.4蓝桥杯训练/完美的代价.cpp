#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
//int main()
//{
//	char* p, * q,temp1,temp2, str[10];
//	cin.getline(str,10);
//	p = q = str;
//	while (*p != '\0')
//		p++;
//	p--;
//	while (q < p) {
//		if (*q != *p) {
//			temp1 = *p;
//			*p = *(p - 1);
//			*(p - 1) = temp1;
//			while (*q == *p) {
//				temp2 = *p;
//				*p = temp1;
//				temp1 = temp2;
//				q++;
//				p--;
//			}
//			p--;
//		}
//		if (*q == *p) {
//			q++;
//			p--;
//			continue;
//		}
//	}
//	printf("%s", p);
//}

//==========贪心算法=========
//int main()
//{
//	//双指针从左往右遍历，然后从右往左遍历去查找相同元素，之后将相同元素转移到最后面。
//	char* p, * q, **temp1, temp2, str[10];
//		cin.getline(str,10);
//		p = q = str;
//		
//		while (*p != '\0')
//			p++;
//		p--;
//		**temp1 = *p;
//		while (q < p)
//		{
//			if (*q == *p) {	
//
//				*p = temp2;
//				p--; 
//				q++;
//			}	
//			else {
//				while (*q != *p) {
//					p--;
//				}
//			}
//		}
//		printf("%s", p);
//}
