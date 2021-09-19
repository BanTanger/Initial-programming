#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//void test(char* str)
//{
//	int len = strlen(str);
//	char* left = str;
//	char* right = len - 1 + str;
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--;
//		left++;
//	}
//	
//}
//int main()
//{
//	int arr[365] = { 0 };
//
//	gets( arr);//读取一行，比scanf优秀
//	//倒叙函数的实现
//	test(arr);
//	printf("倒叙之后的字符：%s\n", arr);
//	return 0;
//
//}

//int main()
//{
//	//实现Sn=a+aa+aaa+aaaa的操作
//	int a = 0;
//	int n = 0;
//	scanf("%d%d", &a, &n);
//	int sum = 0;
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//==========水仙花数计算======
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		int sum = 0;
//		int n = 1;
//		int tmp = i;//创建临时变量，避免i的值被机器更改
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2.每一位乘以n的次方
//		tmp = i;
//		while (tmp)
//		{
//			sum +=(int) pow(tmp % 10, n);//膜10得每一位；计算每一位的n次方
//			tmp /= 10;//消掉最后一位，前一位当成最后一位。
//			//比如个位消去，变成十位。
//		}
//		//水仙花数的判断
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

int main()
{
	int a = 0;
	printf("菱形行数:>");
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i < a; i++)
	{
		//上界
		//打印空格
		int j = 0;
		for (j = 0; j < a - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j <2*i+1 ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < a - 1; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <2*(a- 1-i)-1 ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}