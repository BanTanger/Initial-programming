#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
//  no.1
//int main()
//{
//	int ch[] = { 1,5,48,1,3,46,12,5,1,0 };
//	int i;
//	int sz = sizeof(ch) / sizeof(ch[0]);
//
//	for (i = 1; i < sz; i++)
//	{
//		if (ch[i] < ch[i+1] && ch[i] < ch[i-1])
//			printf("%d ", i);
//		if (ch[i] > ch[i+1] && ch[i] > ch[i-1])
//			printf("%d ", i);
//	}
//	return 0;
//}

// no.2
//int main()
//{
//	bool ch[10] = { 0 };
//	int input;
//	printf("Please input a intage(no to ten):");
//	scanf("%d", &input);
//	//将整数的所有位放在一个数组中
//	do
//	{
//			int i = 0;
//			int n = input % 10;//得到个位
//			//判断
//			if (ch[n] == 1)
//			{
//				printf("YES!");
//				break;
//			}
//			ch[n] = 1;
//			//从个位开始不断更新，若有重复则可以通过更新的值来把他捕捉
//			input /= 10;//下一位。
//	} while (input);
//	
//	if (input == 0)
//		printf("NO!");
//	return 0;
//}

int main()
{
	int arr[] = { 1,5,4,9,3,1,2,5,6,66,112 };

	return 0;
}