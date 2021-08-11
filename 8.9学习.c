#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	int day = 0;
//	(void)scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("工作日\n");
//		break;
//	case 6:
//	case 7:
//		printf("休息日\n");
//		break;
//	default:
//		printf("输入错误\n");
//		break;
//	}
//
//	return 0;
//}

/*int main()
{
	int day = 0;
	(void)scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期天\n");
		break;
	}

	return 0;
}*/

//============练习======错误一======
//int main()
//{
//	int num = 1;
//	while (num <= 100)
//	{
//		printf("%d\n",num);
//		num++;
//	}
//	if (num % 2 == 0)
//		printf("所输的值为偶数:%d\n",num);
//	else
//		printf("所输的值为奇数:%d\n",num);
//	return 0;

//int main()
//{
//	int num = 1;
//	while (num <= 100)
//	{
//		/*if (num % 2 == 1)*/
//			printf("%d  ", num);
//		num+=2;
//	}
//	return 0;
//}
/*int main()
{
	int num = 1;
	while (num <= 100)
	{
		if (num % 2 == 1)
			printf("%d  ", num);
		num++;
	}
	return 0;
}*/
//}int main()
//{
//	int num = 0;
//	while (num < 100)
//	{
//		/*printf("%d\n", num);*/
//		num++;
//
//		if (num % 2 == 0)
//			/*printf("所输的值为偶数:%d\n", num);*/
//			printf("\n");
//		else
//			printf("所输的值为奇数:%d\n", num);
//	}
//	return 0;
//}



//int main()
//{
//	int num = 4;
//	if (num = 5)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//int main()
//{
//	if (condition)
//	{
//		return x;
//	}
//	return y
//}
//
//int main()
//{
//	if (conditon)
//	{
//		return x;
//	}
//	else
//	{
//		return y;
//	}
//
//}

//int main()
//{
//	int a = 0;
//	int b = 2;
//	if (a == 1)
//		if (b == 2)
//			printf("hehe\n");
//    else
//			printf("haha\n");
//	return 0;
//}

//int main()
//{
//	int age = 0;
//	if (age < 18)
//		printf("未成年\n");
//	//else if(18 <= age < 28)
//	else if (age >= 18 && age < 28)
//		printf("青年\n");
//	else if (age >= 28 && age < 50)
//		printf("壮年\n");
//	else if (age >= 50 && age < 90)
//		printf("老年\n");
//	else if (age >= 90 && age < 100)
//		printf("老不死\n");

	//else
	//	printf("成年\n");
	/*return 0;*/
	
//int main()
//{
//	int age = 0;
//	if (age < 18)
//	{
//		printf("未成年\n");
//		printf("不能谈恋爱\n");
//	}
//	//else if(18 <= age < 28)
//	else
//	{
//		if (age >= 18 && age < 28)
//			printf("青年\n");
//		else if (age >= 28 && age < 50)
//			printf("壮年\n");
//		else if (age >= 50 && age < 90)
//			printf("老年\n");
//		else
//			printf("老不死\n");
//	}
//	//else
//	//	printf("成年\n");
//	return 0;
//}
//}int main()
//{
//	int age = 0;
//	if (age < 18)
//		printf("未成年\n");
//	//else if(18 <= age < 28)
//	else
//	{
//		if (age >= 18 && age < 28)
//			printf("青年\n");
//		else if (age >= 28 && age < 50)
//			printf("壮年\n");
//		else if (age >= 50 && age < 90)
//			printf("老年\n");
//		else
//			printf("老不死\n");
//	}
//	//else
//	//	printf("成年\n");
//	return 0;
//}

//int main()
//{
//	double b = 3.14;
//	double* pd = &b;
//	*pd = 5.5;
//	printf("%lf\n", b);
//	return 0;
//}


//==============================结构体变量=============================
//struct BOOK
//{
//	char name[20];
//	short price;
//};
//
//int main()
//{
//	struct BOOK bl = { "C语言程序设计",55 };
//	struct BOOK* pb = &bl;
//	printf("书名:%s\n",bl.name);
//	printf("价格:%d\n",bl.price);
//	//printf("%d\n", (*pb).price);
//	//printf("%s\n", (*pb).name);
//	printf("%s\n", pb->name);
//	printf("%d\n", pb->price);
//	return 0;
//
//}
