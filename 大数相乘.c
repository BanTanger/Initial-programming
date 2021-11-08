//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#define MAX 100000000
//char arr[MAX], arr1[MAX];
//int num[MAX], num1[MAX], num2[MAX];
//
//int main()
//{
//	gets(arr);
//    gets(arr1);
//	int n = strlen(arr);
//	int m = strlen(arr1);
//	int i, k = 0;
//	for (i = n - 1; i >= 0; i--) {
//		num[k] = arr[i] - '0';//将char改成int
//		k++;
//	}
//	k = 0;
//	for (i = m - 1; i >= 0; i--) {
//		num1[k] = arr1[i] - '0';//将char改成int
//		k++;
//	}
//	int enter, tmp;
//	int j = 0;
//	memset(num2, 0, sizeof(num2));//初始化
//	for (i = 0; i <= n ; i++) {
//		k = i;
//		enter = 0;//进位清零，必须是局部变量。
//		for (j = 0; j <= m; j++) {
//			tmp = num2[k];
//			num2[k] = (num[i] * num1[j] + enter + tmp) % 10;
//			enter = (num[i] * num1[j] + enter + tmp) / 10;
//			k++;
//		}
//	}
//	tmp = 0;//输出num2，如果前几位是0，就不输出。
//	for (; k >= 0; k--) {
//		if (num2[k] == 0 && tmp == 0)
//			continue;
//		else
//			tmp = 1;
//		printf("%d", num2[k]);
//	}
//
//}