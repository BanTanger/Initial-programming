#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int sum = 0;
	int n = 0;
	scanf("%d", &n);
	sum = n * (n + 1) / 2;
	printf("%d\n", sum);
	return 0;
}