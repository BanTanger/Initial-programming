//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdbool.h>
//#define MAX 20
//int main()
//{
//	int n, m, max,maxj,i,j;
//	int arr[MAX][MAX];
//	bool flag;
//	scanf("%d%d", &n, &m);
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++) {
//		max = arr[i][0]; maxj = 0;//初始化；
//		for (j = 0; j < m; j++) {
//			if (arr[i][j] > max) {
//				max = arr[i][j];
//				maxj = j;
//				//最大组号和列号保存；
//			}
//		}
//		flag = true;
//		for (int k = 0; k < n; k++) {
//			if (max > arr[k][max]) {
//				flag = false;
//				continue;
//			}
//		}
//		
//	}
//	if (flag) {
//		printf("%d %d", i, maxj);
//	}
//	else
//		printf("不存在该特征的元素");
//}