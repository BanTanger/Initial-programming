//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<malloc.h>
///*编写一个C程序，实现以下功能：
//动态申请长度为5的整数空间数组，用户输入5个整数；动态扩展数组空间为8，用户另外输入3个整数，最后输出扩展后的全部数组元素。
//*/
//int main() {
//	int* arr = (int*)malloc(sizeof(int) * 5);
//	for (int i = 0; i < 5; i++)
//		scanf("%d", &arr[i]);
//	arr =(int*)realloc(arr,sizeof(int) * 8);
//	for (int i = 5; i < 8; i++)
//		scanf("%d", &arr[i]);
//	for (int i = 0; i < 8; i++)
//		printf("%d", arr[i]);
//}