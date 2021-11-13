#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 20
//int main()
//{
//	int arr[MAX][MAX], i, j, k = 2;
//	for (i = 0; i < MAX ; i++) {
//		arr[0][0] = 1;
//		for (j = 0; j < MAX - i; j++) {
//			if ((i + j) % 2 == 0) {//偶数
//				//进位原则是下一个数为行进1，列减1
//				arr[i + 1][j - 1] = k;
//				k++;
//			}
//			else if ((i + j) % 2 == 1 ) {//奇数
//				//下一个数行减1，列加1
//				arr[i - 1][j + 1] = k;
//				k++;
//			}
//		}
//	}
//	for (i = 0; i < MAX ; i++) {
//		for (j = 0; j < MAX - i ; j++){
//			printf("%-4d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}

int main()
{
	int arr[MAX][MAX];
	int i, j, dirt = -1, k = 1;
	for (i = 0; i < MAX; i++) {
		if (dirt == 1) {
			for (j = 0; j <= i; j++) {
				arr[j][i - j] = k;
				k++;
			}
		}
		else{
			for (j = 0; j <= i; j++) {
				arr[i - j][j] = k;
				k++;
			}
		}
		dirt *= -1;
	}
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX - i; j++) {
			printf("%-4d", arr[i][j]);
		}
		printf("\n");
	}
}