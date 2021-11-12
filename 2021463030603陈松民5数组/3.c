//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int n, j, i = 0;
//	int arr[20];
//	scanf("%d", &n);
//	j = n;
//	for (i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	for (int z = 0; z < n; z++) {
//		for (i = z; i < n; i++) {
//			if (arr[i] % 2 == 0 && arr[n - 1] % 2 != 0) {//Å¼ÊýÅÐ¶Ï
//				int tmp = arr[i];
//				arr[i] = arr[n - 1];
//				arr[n - 1] = tmp;
//				n--;
//			}
//			else {
//				i--;
//				n--;
//			}
//		}
//	}
//	for (i = 0; i < j; i++)
//		printf("%d ", arr[i]);
//}