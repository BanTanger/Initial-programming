#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
//

int main()
{
	char arr1[] = " ÎÒ    ½Ð     Áõ     ×Ó      ²Ó ";
	char arr2[] = " ****************************** ";
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int left = 0;
	int right = sz - 2;
	while (left<=right)
	{
		arr2[left] = arr1[left];
		//arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(500);
		system("cls");
		left++;
		//right--;
	}
	return 0;
}
