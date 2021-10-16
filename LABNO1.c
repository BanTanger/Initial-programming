#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	double H = 0.00;
//	int n = 0;
//	double ret = 0.00;
//	int d = 0;//控制循环跳出的变量
//	printf("the initial height is ");
//	scanf("%lf", &H);
//	scanf("%d", &n);//跳多少次
//
//	while (H > 0)
//	{
//		ret += H;
//		H /= 2;
//		d++;
//		if (n == d)//达到循环就跳出
//			break;
//	}
//	/*if (H == 0 || n != d)
//		printf("H值过小或n过大\n");
//	else
//	{ */
//		printf("the tatal of road is %.6lf\n", ret);
//		printf("the tenth is %.6lf\n", H);
//	/*}*/
//	return 0;
//}
//void test();
//int main()
//{
//	test();
//	return 0;
//}
//void test()
//{
//	//双方都定义一个速度
//	int v1 = 3;//英雄速度为3
//	int v2 = 9;//步兵速度为9
//	int n = 0;
//	int t = 0;
//	printf("time:(s)");
//	scanf("%d", &n);
//	//作为一个最大值存在，到时候不断加10加10.
//	
//	int j = 0;//多给一个变量用来多加时间
//	int s1 = 0, s2 = 0;
//	for (t = 0; t <= n; t += 10)
//	{
//		if (s2 > s1)
//		{
//			v2 = 0;
//			j = 30;
//			if(t+j<n)
//				t += j;//避免影响t变量
//			s1 += v1 * j;
//		}
//		else
//		{
//			j = 10;
//			v2 = 9;
//			s1 += v1 * j;
//			s2 += v2 * j;
//		}
//	}
//	if ((t - 10)< n)
//	{
//		j = (n - (t-10));
//		s1 += v1 * j;
//		s2 += v2 * j;
//	}
//	if (s2 > s1)
//		printf("infantry %d", s2);
//	else
//		printf("hero %d", s1);
//}
//
//#include<stdio.h>
//int main()
//{
//    int T = 0;
//    int s2 = 0, s1 = 0;
//    scanf("%d", &T);
//    T -= 1;
//    int t = 0;
//    while (t <= T)
//    {
//        t++;
//        s2 += 9;
//        s1 += 3;
//        //逢十检查一次
//        if (t % 10 == 0 && s2 > s1)
//        {
//            //英雄跑
//            int i = t;
//            while (t <= T && t < 30 + i)
//            {
//                t++;
//                s1 += 3;
//            }
//        }
//    }
//    if (s1 > s2)
//        printf("hero %d", s1);
//    else if (s2 > s1)
//        printf("infantry %d", s2);
//    else 
//        printf("平局 ", s2);
//    return 0;
//}
//
//#include<stdio.h>
//#include<windows.h>
//#include<string.h>
//#include<math.h>
//#include<stdlib.h>
//#include<time.h>
//
//void game()
//{
//	int guess = 0;
//	int ret = 0;
//	ret = rand() % 100 + 1;
//	//生成1到100之间的随机数（取模）
//	//printf("%d\n",ret);
//	//猜数字（循环猜测）
//	while (1)
//	{
//		printf("请猜数字(在1到100之间):>");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			printf("GAME OVER!!\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned)time(NULL));//NULL空指针，不需要返回任何一个值时使用
//	int input = 0;
//	game();
//	return 0;
//}
//
////switch
//int main()
//{
//	int n = 0;
//	int d = 0;
//	printf("请输入（1/0）(1代表升序):");
//	scanf("%d", &n);
//	int ch[20];
//	int i = 0;
//	int index = 0;
//	//将值存入数组，循环来实现
//	for (index = 0; index <= 10; index++)
//	{
//		scanf("%d", &ch[index]);
//		/*	printf("%d ", ch[i]);*/
//	}
//		//两层for嵌套
//		for (i = 0; i < 10 - 1; i++)//多少次
//		{
//			int j = 0;
//			for (j = 1; j < 10 - i - 1; j++)//多少次
//			{
//				if (ch[j] > ch[j + 1])
//				{
//					int tmp = ch[j];
//					ch[j] = ch[j + 1];
//					ch[j + 1] = tmp;
//				}
//			}
//		}
//		for (i = 0; i < 10; i++)
//			printf("%d ", ch[i]);
//	
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int a[20];
//	int i; 
//	int n = 0;
//	printf("请输入（1/0）(1代表升序):");
//	scanf("%d", &n);
//	printf("10<=a<=20");
//	for (i = 1; i <= 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	int m = 10;
//	if (n == 1)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			for (i = 0; i < m - j; i++)
//			{
//				if (a[i] > a[i + 1])
//				{
//					int tmp = a[i];
//					a[i] = a[i + 1];
//					a[i + 1] = tmp;
//				}
//			}
//		}
//		for (i = 1; i <= 10; i++)
//		{
//			printf("%d ", a[i]);
//		}
//	}
//	else
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			for (i = 0; i <= m - j; i++)
//			{
//				if (a[i] < a[i + 1])
//				{
//					int tmp = a[i];
//					a[i] = a[i + 1];
//					a[i + 1] = tmp;
//				}
//			}
//		}
//		for (i = 1; i <= 10; i++)
//		{
//			printf("%d ", a[i]);
//		}
//	}
//}
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char a[5], b[5], c[5], d[5];
//	gets(a);
//	gets(b);
//	gets(c);
//	//d是用来拷贝的
//	if (strcmp(a, b) > 0)
//	{
//		strcpy(d, a);
//		strcpy(a, b);
//		strcpy(b, d);
//	}
//	if (strcmp(a, c) > 0)
//	{
//		strcpy(d, a);
//		strcpy(a, c);
//		strcpy(c, d);
//	}
//	if (strcmp(b, c) > 0)
//	{
//		strcpy(d, b);
//		strcpy(b, c);
//		strcpy(c, d);
//	}
//	printf("排序后的结果\n");
//	printf("\n%s\n\n%s\n\n%s\n\n", a,b,c);
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	printf("输入一个整数：");
//	scanf("%d", &n);
//	int arr[] = { 0 };
//	for (int i = 0; n > 0; i++)
//	{
//		arr[i] = n % 10;
//		n /= 10;
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
	//int shour, x;
	//int time, smin;
	//scanf("%d%d", &time, &x);
	//if (time % 100 > 60 || time > 2400)
	//	printf("输入错误\n");
	//shour = x / 60;//流失多少个小时
	//int chour = (time / 100) * 100;
	//smin = x % 60;//流失多少分钟；
	//int cmin = time % 100;//原有的分钟
	//if ((smin + cmin) > 60)
	//{
	//	shour += 1;
	//	cmin = (smin + cmin) % 60;
	//	chour += shour * 100 + cmin;
	//}
	//else if((smin + cmin) < 60&& (smin + cmin)>0)
	//{
	//	cmin = (smin + cmin) % 60;
	//	chour += shour * 100 + cmin;
	//}
	//else
	//{
	//	chour += shour * 100 + smin - 20;
	//}
	//int h, time, min, x,min_x,h_x;
	//scanf("%d%d", &time, &x);
	//h = (time / 100) * 100;
	//min = time % 100;
	//min_x = x % 60;
	//h_x = x / 60;
	//if (time > 2400 || time % 100 > 60)//非法判断
	//	printf("输入非法！！！");
	//
	//printf("%d\n", );
	//return 0;
//}

//int main()
//{
//	char a, b, c,tmp;//三个自输入变量，加一个交换变量
//	scanf("%c\n%c\n%c",&a,&b,&c);
//	/*if (a > b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a > c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b > c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}*/
//	//优化，三目
//	char max = (a > b && a > c) ? a : ((b > c && b > a) ? b : c);
//	char min = (c < b && c < a) ? c : ((a < c && a < b) ? a : b);
//	char mid = (a + b + c) - (min + max);
//	printf("\n%c\n\n%c\n\n%c\n\n",min,mid,max);
//	return 0;
//
//}

//加减法位运算
//int	test(int a, int b)
//{
//	if (b == 0)
//		return a;
//	int Nsum = a ^ b;
//	int Osum = (a & b) << 1;
//	return test(Nsum,Osum);
//}


int	test(int a, int b)
{
	if (b == 0)
		return a;
	int Nsum = a ^ b;
	int Osum = (a & b) << 1;
	return test(Nsum, Osum);
}
//int test2(int a,int b)
//{
//	int count = a;
//	//printf("%p", &count);
//	if (b < 2)
//		return count;
//	else
//	{
//		test(b, -1);
//		//printf("%p", &count);
//		return test(count, a);
//	}
//}
int multiply(int x, int y)
{
	int count = 0,i = 1;
	if (x < 0)
	{
		x = -x; i = -i;
	}
	if (y < 0)
	{
		y = -y; i = -i;
	}
	while (y)
	{
		count = test(count,x);
		y = test(y, -1);
	}
	count = (i < 0) ? -count : count;
	return count;
}
int division(int x, int y)
{
	int end = 0, i = 1;
	if (x < 0)
	{
		x = -x; i = -i;
	}
	if (y < 0)
	{
		y = -y; i = -i;
	}
	if (x < y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	int d = -y;//定义一个固定的负值，模拟减法
	while ((x = test(x, d))>=0)
	{
		/*end = test(x, d);*/
		end = test(end, 1);
	}
	end = (i < 0) ? -end : end;
	return end;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a < b)//让b作为循环的量
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	//int count = multiply(a, b);
	int end = division(a, b);
	//int ret = test(a,b);
	/*int ret2 = test2(a,b);*/
	printf("%d", end);
	return 0;
}