//#define _CRT_SECURE_NO_WARNINGS 1
////#include<stdio.h>
////#include<stdbool.h>
////#define MAX 20
////#define MAXi 2
////#define MAXj 2
////int main()
////{
////	int max,maxj,maxi,i,j,count = 0;//通过一个计数变量来记录if的执行情况
////	/*int arr[MAX][MAX];*/
////	int arr[MAXi][MAXj] = { 1,7,4,1 };
////	bool flag;
////	
////	/*scanf("%d%d", &n, &m);
////	for (i = 0; i < n; i++) {
////		for (j = 0; j < m; j++) {
////			scanf("%d", &arr[i][j]);
////		}
////	}*/
////	for (i = 0; i < MAXi; i++) {
////		max = arr[i][0]; maxj = 0; maxi = 0; count = 0;//初始化；
////		for (j = 0; j < MAXj; j++) {
////			if (arr[i][j] > max) {
////				max = arr[i][j];
////				maxj = j;
////				maxi = i;
////				//最大组号和列号保存；
////			}
////		}
////		flag = true;
////		for (int k = 0; k < MAXi; k++) {
////			if (max > arr[k][maxj]) {
////				flag = false;
////				count++;
////				//通过一个计数变量来记录if的执行情况
////			}
////		}
////		if (count == 0)//if执行零次，就代表在列上是最小的。
////			break;
////	}
////	if (flag) {
////		printf("%d %d\n", maxi+1, maxj+1);
////	}
////	else
////		printf("不存在该特征的元素\n");
////}
//
//#include<stdio.h>
//#include<stdbool.h>
//#define MAX 20
//#define MAXi 4
//#define MAXj 4
//int main()
//{
//	int max, maxj, i, j;
//	/*int arr[MAX][MAX];*/
//	int arr[MAXi][MAXj] = { 1 ,7 ,4 ,1 ,4, 8, 3, 6,1, 6, 1, 2,0, 7, 8, 9 };
//	bool flag;
//
//	/*scanf("%d%d", &n, &m);
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}*/
//	for (i = 0; i < MAXi; i++) {
//		max = arr[i][0]; maxj = 0; //初始化；
//		for (j = 0; j < MAXj; j++) {
//			if (arr[i][j] > max) {
//				max = arr[i][j];
//				maxj = j;
//				//最大组号和列号保存；
//			}
//		}
//		flag = true;
//		for (int k = 0; k < MAXi; k++) {
//			if (max > arr[k][maxj]) {
//				flag = false;
//			}
//		}
//		if (flag) {
//			printf("%d %d\n",i + 1, maxj + 1);
//			break;
//		}
//	}
//	if(!flag)
//		printf("不存在该特征的元素\n");
//}