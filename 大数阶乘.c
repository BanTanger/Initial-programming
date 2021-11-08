#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define MAX 100000000
int main()
{
	int a[MAX];
	int temp, digit, n, j, i;
	//temp 每次得数，digit每次位数
	scanf("%d", &n);
	a[0] = 1;//从一开始;
	digit = 1;//位数从一开始;
	for (i = 2; i <= n; i++) {
		//位数循环
		int num = 0;
		for (j = 0; j < digit; j++) {
			temp = a[j] * i + num;
			a[j] = temp % 10;//更新a[j]保证每次都是个位，高位通过num加回；
			//将一个属的每一位利用数组加回；
			num = temp / 10;
		}
		while (num) {
			a[digit] = num % 10;
			num /= 10;
			digit++;
		}
	}
	for (i = digit - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	printf("\n");

}