#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int compare(int a, int b)
{
	int x = 0;
	return x = (a > b) ? b : a;
}
int test(int* arr, int n, int (*compare)(int, int))
{
	int max = arr[0];
	for (int i = 0; i < n; i++)//Ñ­»·nÌË£»
	{
		int mul = 1; int weight = 1;
		for (int j = i; j < n; j++)
		{
			weight = j - i;
			int len = compare(arr[i], arr[j]);
			if (weight == 0)
				mul = len * (weight + 1);
			else
				mul = len * weight;
			if (mul > max)
				max = mul;
		}
	}
	return max;
}
int main()
{
	int arr[20] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int sz = 12;
	int x = test(arr, sz, compare);
	printf("%d", x);
}