//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	if (n < 10 || m < 10)
//		printf("please input again");
//	int min = n > m ? m : n;
//	int max = n + m - min;
//	int tmp1;
//	for (int i = min; i < max; i++) {
//		tmp1 = i;
//		tmp1 /= 10;
//		tmp1 %= 10;
//		if (tmp1 == 3 || tmp1 == 7)
//			printf("%d ", i);
//	}
//}