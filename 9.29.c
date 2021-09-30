#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//double check1(double x);
//int main()
//{
//	double input = 0.0;
//	printf("请输入数值:>");
//	scanf("%lf", &input);
//	double ret = check1(input);
//	printf("实际付款w=%lf\n", ret);
//	return 0;
//}
//double check1(double x)
//{
//	double y = 0.00;
//	if (x < 1600)
//	{
//		y = 0.00;
//	}
//	else if (x < 3200)
//	{
//		y = 0.15;
//	}
//	return (x * (1 - y));
//}

/*int main()
{
	int input = 0;
	printf("请输入数值:>");
	scanf("%d", &input);
	double ret = check((double)input);
	printf("实际付款w=%f\n", ret);
	return 0;
}
int check(double x)
{
	double y = 0.00;
	if (x < 1600)
	{
		y = 0.00;
	}
	else if (x < 3200)
	{
		y = 0.15;
	}
	return (double)(x * (1 - y));

}*/

//main()
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入x的值:>");
//	scanf("%d", &x);
//	if (x < 1)
//		y = x;
//	else if (1 <= x <= 10)
//		y = 2 * x - 1;
//	else if (x > 10)
//		y = 3 * x - 1;
//	printf("y=%d", y);
//}

//struct Peo
//{
//	char sex;
//	int tall;	
//	int age;
//	double weight;
//}s;
//
//void menu()
//{
//	printf("************************************************\n");
//	printf("******        1.男          2.女          ******\n");
//	printf("************************************************\n");
//}
//
//main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入性别:>");
//		scanf("%d", &s.sex);
//		printf("请输入年龄:>");
//		scanf("%d", &s.age);
//		printf("请输入身高:>");
//		scanf("%d", &s.tall);
//		printf("请输入体重:>");
//		scanf("%lf", &s.weight);
//	} while (input);
//	
//	//判断男女
//	if (s.sex==1)
//	{
//		if (s.tall > 170 && s.weight > 60.0)
//		{
//			printf("恭喜您，被我司录取！\n");
//			if (18 < s.age < 24)
//			{
//				printf("您被我司分配为销售业务员！\n");
//			}
//			else if (s.age > 24)
//			{
//				printf("您被我司分配为售后服务人员！\n");
//			}
//		}
//		else
//		{
//			printf("您没有被入选！\n");
//		}
//	}
//	else if (s.sex == 2)
//	{
//		if (s.tall > 160 && s.weight > 45.0)
//		{
//			printf("恭喜您，被我司录取！\n");
//			if (18 < s.age < 24)
//			{
//				printf("您被我司分配为销售业务员！\n");
//			}
//			else if (s.age > 24)
//			{
//				printf("您被我司分配为售后服务人员！\n");
//			}
//		}
//		else
//		{
//			printf("您没有被入选！\n");
//		}
//	}
//	
//}

//void menu()
//{
//	printf("=========饮料自动售卖机=======\n");
//	printf("        1 - 苹果汁   6元      \n");
//	printf("        2 - 西瓜汁   5元      \n");
//	printf("        3 - 葡萄汁   4元      \n");
//	printf("        4 - 可乐     3元      \n");
//	printf("        5 - 雪碧     2元      \n");
//	printf("        0 - 退出              \n");
//	printf("==============================\n");
//}
//int main()
//{
//	int input1 = 0;
//	int input2 = 0;
//	do
//	{
//		menu();
//		printf("请输入饮料编号和数量:>");
//		scanf("%d%d", &input1, &input2);
//		switch (input1)
//		{
//			case 1:
//				printf("选择苹果汁！\n");
//				printf("你本次购买%d饮料，需要支付%d元\n", input2, 6 * input2);
//				break;
//			case 2:
//				printf("选择西瓜汁！\n");
//				printf("你本次购买%d饮料，需要支付%d元\n", input2, 5 * input2);
//				break;
//			case 3:
//				printf("选择葡萄汁！\n");
//				printf("你本次购买%d饮料，需要支付%d元\n", input2, 4 * input2);
//				break;
//			case 4:
//				printf("选择可乐！\n");
//				printf("你本次购买%d饮料，需要支付%d元\n", input2, 3 * input2);
//				break;
//			case 5:
//				printf("选择雪碧！\n");
//				printf("你本次购买%d饮料，需要支付%d元\n", input2, 2 * input2);
//				break;
//			case 0:
//				printf("选择结束\n");
//				break;
//			default:
//				printf("输入错误，请重新输入\n");
//				break;
//		}
//	} while (input1);
//	return 0;
//}

void menu()
{
	printf("===============================\n");
	printf("===          值日表         ===\n");
	printf("===============================\n");
}
int main()
{
	int input = 0;
	do
	{
		//menu();
		printf("请输入数字1-7:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			printf("今天周一，老赵值班\n");
			break;
		case 2:
			printf("今天周二，小孙值班\n");
			break;
		case 3:
			printf("今天周三，老周值班\n");
			break;
		case 4:
			printf("今天周四，老钱值班\n");
			break;
		case 5:
			printf("今天周五，小李值班\n");
			break;
		case 6:
			printf("今天周六，小刘值班\n");
			break;
		case 7:
			printf("今天周日，无人值班\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}