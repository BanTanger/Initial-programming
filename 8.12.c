#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 10; i++)
//	{
//		for(j=0; j < 10;j++ )
//		{
//			printf("hehe\n");
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i)
//	{
//		i++;
//	}
//}
//
//int main()
//{
//	int j = 0;
//	int i = 0;
//	int n = 1;
//	while (n)
//	{
//		i = n++;
//		j = i * n;
//		printf("%d \n", j);
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//    scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//	}
//	printf("阶乘为 = %d\n", ret);
//	return 0;
//}

int main()
{
	int n = 0;
	int i = 0;
	int ret = 1;
	int sum = 0;
	for(n = 1;n <= 10;n++)
	{
	 scanf("%d", &n);
	 for (i = 1; i <= n; i++)
	 {
		ret = ret * i;
	 }
		sum = ret+ sum;
		printf("累加的和为：%d\n", ret);
	}
	
	return 0;
}