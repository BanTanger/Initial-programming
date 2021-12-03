//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<math.h>
//#include<algorithm>
//using namespace std;
///*编写一个C程序，实现以下功能：
//输入n个人的身高，然后从n个人中选出身高差值最小的两个人作为礼仪（如果差值相同的话，选取其中最高的两个人），要求输出两个礼仪的身高。
//*/
//#define MAX 500
//void func(int* arr, int n, int* a, int* b) {
//	int min = abs(a - b);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			//差值不同
//			if (abs(arr[i] - arr[j]) < min) {
//				min = abs(arr[i] - arr[j]);
//				*a = arr[i];
//				*b = arr[j];
//			}
//			//差值相同
//			else
//			{
//				*a = arr[n - 2];//记住‘\0’的存在
//				*b = arr[n - 1];
//			}
//		}
//	}
//}
//int main() {
//	int n, arr[MAX];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	int a, b;//定义两个差值最小的人，假定为数组的0和1元素
//	a = arr[0], b = arr[1];
//	sort(arr, arr + n);
//	func(arr, n,&a,&b);
//	printf("%d %d", a, b);
//}