//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int n, arr[1000], i = 0, count = 0,j = 0;
//	scanf("%d", &n);
//	while (n) {
//		arr[i] = n % 10;
//		n /= 10;
//		i++;
//	}
//	for (int z = 0; z < i; z++) {
//		for (j = z; j < i - 1; j++) {
//			if (arr[j] == arr[i - 1]) {
//				count++;
//			}else {
//				continue;
//			}
//		}
//	}
//	if (count == 0)
//		printf("NO");
//	else
//		printf("YES");
//}