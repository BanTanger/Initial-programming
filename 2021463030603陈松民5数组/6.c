#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 20

int main()
{
	int count = 0,n,i,j;
	int arr[MAX];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	/*for (i = 0; i < n; i++)
		printf("%d ", arr[i]);*/
	int m = n * 0.6;
	if (arr[1] > 60)
		printf("及格线为60");
	else if (arr[m] >= 10)
		printf("及格线是%d", (arr[m] / 10) * 10);
	else
		printf("及格线是%d", arr[m]);
}