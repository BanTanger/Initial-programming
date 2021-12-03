#define _CRT_SECURE_NO_WARNINGS 1
/*编写一个C程序，实现以下功能：
编写一个sort函数，实现对5个字符串按从大到小进行排序。
在主程序中输入5字符串，调用sort(s,n)函数对n个字符串s进行排序，
然后输出排序后的结果。例如：输入字符串Li Xiao Wang Zhang Yu，
输出：Zhang Yu Xiao Wang Li。提示：使用字符指针数组。
*/
#include<stdio.h>
#define N 5
#define M 10
void sort(int* s[N],int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(s[j], s[j + 1]) < 0) {
				int* tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}
int main() {
	//五个字符串	
	char str[N][M];
	char* s[N];
	for (int i = 0; i < N; i++) {
		scanf("%s", *(str + i));
		s[i] = *(str+i);
	}
	sort(s,N);
	for (int i = 0; i < N; i++) {
		printf("%s ", s[i]);
	}
}