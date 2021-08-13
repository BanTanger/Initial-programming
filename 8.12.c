#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

//int main()//算法有问题，逻辑错误
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if ((i % 1 == 0) || (i % i == 0))
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\n一共有%d个素数\n", count);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++){
//		//判断i是否为素数
//		//素数的判断规则：
//		//1.试除法：13  拿2-12的数来除它，若余数！=0则成功
//		int j = 0;
//		for (j = 2; j < i; j++){
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i){
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n在100到200中，所有的素数有%d个\n", count);
//	return 0;
//}

//int main(void)
//{
//    printf("床前明月光，\n");
//    printf("疑是地上霜。\n");
//    printf("举头望明月，\n");
//    printf("低头思故乡。\n");
//
//}

//===============================打印闰年==================================
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++){
		//判断闰年
		//1.能被4整除并不能被100整除是闰年
		//2.能被400整除是闰年
		/*if (year%4==0 && year%100!= 0){	
			printf("%d ", year);
			count++;
		}
		else if (year % 400 == 0){
			count++;
			printf("%d ", year);
		}*/
		//============================另一种优化写法=============================
		/*if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 400 == 0)))
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\n从1000年到2000年共有的闰年个数为：%d\n", count);
	return 0;
}*/

//===============================求最大公约数===============================
//int main()
//{
//	int i = 0; 
//	int m = 0; int n = 0;
//	scanf("%d %d", &m, &n);
//	for (; i == 0;)
//	{
//		i = m % n;
//	    m = n;  n = i;
//	}
//	printf("最大公约数为：%d\n", n);
//	return 0;
//}

//=======================打印三的倍数===============================
//int main()
//{
//	int i = 0;
//	for (; i < 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//=======================比较三个数的大小===========================
//int main(void)
//{
//	int a; int b; int c;
//	a = 0, b = 0, c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	int min= a < b && a < c ? a : (b < a && b < c ? b : c);
//	int max= a > b && a > c ? a : (b > a && b > c ? b : c);
//	int mid = (a + b + c )- (max + min);
//	printf("%d %d %d\n",max,mid,min);
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if(a < b)
//	{
//		int tmp = a;
//		 a = b;
//		 b = tmp;
//	}
//    if(a<c)
//	{
//		int tmp = a;
//		 a = c;
//		 c = tmp;
//	}
//	if(b < c)
//	{
//		int tmp = b;
//		 b = c;
//		 c = tmp;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 3;
//	if (a > b)
//	{
//		printf("a\n");
//	}
//}

//int main(){
//	printf("您共有3次输入机会\n");
//	int i = 1;
//	char password[20] = { 0 };
//	for (; i <= 3; i++){
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "1290288968") == 0){
//			printf("登录成功\n");
//				break;
//		}
//		else{
//			printf("密码错误\n");
//			if (i <= 3){
//				int j = 3 - i;
//				printf("您还剩下%d次机会\n", j);
//			}
//			if (i == 3)
//				printf("三次密码均错误，退出程序\n");
//		}
//	}
//	return 0;
//}
// 
// int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (; i <= 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		//scanf返回取值需要用到取地址&，但password本身就是地址，所以不用
//		if (strcmp(password, "1290288968") == 0)
//			//等号不能用来判读两个字符串相对，应该使用库函数-strcmp
//		{
//			printf("登录成功\n");
//				break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//		printf("三次密码均错误，退出程序\n");
//		return 0;
//}

//int main()
//{
//	char arr1[] = "My Name Is BanTanger!!!!";
//	char arr2[] = "########################";
//	int n = sizeof(arr1) / sizeof(arr1[0]);
//	int left = 0;
//	int right = n - 2;//字符串自带'\0',但不需要'\0'，所以下标要减去2.
//	//int right = strlen(arr1) - 1;//strlen专门计算字符长度
//	//while (left <= right)
//	//{
//	//	arr2[left] = arr1[left];
//	//	arr2[right] = arr1[right];
//	//	printf("%s\n", arr2);
//	//	Sleep(1000);//休息一秒，单位为毫秒。引用头文件windows
//	//	left++;
//	//	right--;
//	//}
//	
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);//休息一秒，单位为毫秒。引用头文件windows
//		system("cls");//clean sceen
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;//寻找7
//	int sz = sizeof(arr) / sizeof(arr[0]);//元素共有多少个
//	int left = 0;//左下标
//	int right = sz-1;//右下标。sz为元素个数。sz-1即为最右的下标
//	while(left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了：%d\n", mid);
//			break;
//		}
//		if (left > right)
//			printf("找不到\n");
//	}
//	return 0;
//}

//====================无法理解的代码=======================已理解==========
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;//写一个代码，在arr有序数组里找到7的下标
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//
//	}
//	if (i == sz)
//	{
//		printf("很抱歉，您输入的值过大\n");
//	}
//	return 0;
//}
// 
// int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;//写一个代码，在arr有序数组里找到7的下标
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (k == arr[i]);
//		printf("找到了，下标是：%d\n", i);
//		break;
//	}
//	if (i == sz)
//	{
//		printf("很抱歉，您输入的值过大\n");
//	}
//	return 0;
//}
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

//int main()//优化
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for(n = 1;n <= 3;n++)
//	{
//		ret = ret * n;
//		sum = ret+ sum;	
//	}
//	printf("累加的和为：%d\n", sum);
//	return 0;
//}
//// 
//// int main()
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for(n = 1;n <= 3;n++)
//	{
//		ret = 1;
//	 for (i = 1; i <= n; i++)
//	 {
//		ret = ret * i;//for循环重复这一步。但需要初始重置ret的值。
//	 }
//		sum = ret+ sum;
//		
//	}
//	printf("累加的和为：%d\n", sum);
//	return 0;
//}