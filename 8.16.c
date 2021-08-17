#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//===============================汉诺塔===================================
int hnt(int n, char A, char B, char C)
{
    int count = 0;
    count++;
    /*
    如果是1个盘子
        直接将A柱子上的盘子从A移到C
    否则
        先将A柱子上的n-1个盘子借助C移到B
        直接将A柱子上的盘子从A移到C
        最后将B柱子上的n-1个盘子借助A移到C
    */
    if (1 == n)
    {
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C); //这里的A C不代表具体某个柱子
        return 1;
    }
    else
    {
        hnt(n - 1, A, C, B);
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
        hnt(n - 1, B, A, C);
        return count;
    }
}
int main()
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';//定义三根柱子
    int n;
    printf("请输入要移动盘子的个数：");
    scanf("%d", &n);
   int count= hnt(n, 'A', 'B', 'C');
    printf("总步数:>%d", count);
    return 0;
}

//int A(int n)
//{
//	if (n == 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);//多少层
//	//假定三个柱子
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	a = n;
//	int ret = A(n);
//	printf("%d", ret);
//	return 0;
//}

//===============================斐波那契数列=============================
//======高效=====
//int main()
//{
//	int n = 0;
//	int i = 0;
//	unsigned int a = 1; 
//	unsigned int b = 1;
//	unsigned int c = 0;
//	scanf("%d", &n);
//	for (i = 3; i <= n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	printf("%d\n", c);
//	return 0;
//}

//======低效=====
//int Fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	printf("请输入想查询的斐波那契数:>");
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("第%d个数为%d\n", n,ret);
//	return 0;
//}


//===============================递归求阶乘======================
//fac1(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac1(n - 1);
//}
//
//int main()
//{
//	//求n的阶乘
//	int n = 0;
//	scanf("%d\n", &n);
//	 int ret = fac1(n);
//	 printf("%d\n", ret);
//	 return 0;
//
//}


//=====================模拟strlen===========================
//不能创建临时变量count 
//递归-大事化小
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + my_strlen(str+1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "bit";
//	int len =my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}



/*int my_strlen(char* str)
{
	int count = 0;
while (*str != '\0')
	{	
		count++;
		str++;
	}
	return count;
}

int main()
{
	char arr[] = "bit";
	int len =my_strlen(arr);
	printf("%d\n", len);
	return 0;
}*/