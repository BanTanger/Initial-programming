#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//==================简单结构体===================
//#define MAXTITL 41
//#define MAXNAME 31
//
//struct book {
//	char title[MAXTITL];
//	char author[MAXNAME];
//	float value;
//};
//int main()
//{
//	struct book library;//library作为book类型的变量
//	printf("please enter the book title.\n");
//	gets(library.title);//通过指针访问结构体成员/
//	printf("now enter the author.\n");
//	gets(library.author);
//	printf("now enter the value.\n");
//	scanf("%f", &library.value);
//	printf("%s by %s:$%.2f\n",library.title, library.author, library.value);
//	printf("%s:\"%s\"($%.2f)\n", library.author,library.title,library.value);
//	printf("done.\n");
//	return 0;
//}

//======================结构体数组=======================
//#define MAXTITL 40
//#define MAXAUTL 40
//#define MAXBXS 2//一百本书
//struct book {
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float value;
//};
//int main()
//{
//	struct book library[MAXBXS];//book类型的数组
//	int count = 0;
//	int index;//下标
//
//	//创建书本
//	printf("please enter thet book title.\n");
//	printf("press [enter] at the start of a line to stop.\n");
//	while (count < MAXBXS && gets(library[count].title) != NULL
//		&&library[count].title[0]!='\0')
//	{
//		printf("now enter the author.\n");
//		gets(library[count].author);
//		printf("now enter the value.\n");
//		scanf("%f", &library[count++].value);
//		while (getchar() != '\n')
//			continue;//清空输入行
//		if (count < MAXBXS)
//			printf("enter the next title.\n");
//	}
//	//检索书本
//	if (count > 0)
//	{
//		printf("here is the list of your books :\n");
//		for (index = 0; index < count; index++)
//			printf("%s by %s: $%.2f\n",
//				library[index].title,
//				library[index].author,
//				library[index].value);
//	}
//	else
//		printf("no book? too bad.\n");
//	return 0;
//}

//===================邀请函小代码==================
//#define LEN 20
//const char* msgs[5] =
//{
//	"    Thank you for the wonderful evening, ",
//	"You certainly prove that a ",
//	"is a special kind of guy. We must get together",
//	"over a delicious ",
//	" and have a few laughs"
//};
//struct names {
//	char first[LEN];
//	char last[LEN];
//};
//struct guy {
//	struct names handle;
//	char favfood[LEN];
//	char job[LEN];
//	float income;
//};//结构体嵌套，为了实现名和性分开打的需求
//int main()
//{
//	struct guy fellow = {//初始化变量
//		{"Ewen","BanTanger"},
//		"grilled salmon",
//		"personalit coach",
//		58112.00
//	};//结构体初始化里面的值都不能用；来操作。
//	printf("Dear %s,\n\n", fellow.handle.first);
//	printf("%s%s.\n", msgs[0], fellow.handle.first);
//	printf("%s%s.\n", msgs[1], fellow.handle.last);
//	printf("%s.\n", msgs[2]);
//	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
//	if (fellow.income > 150000.0)
//		puts("!!");
//	else if (fellow.income > 75000.0)
//		puts("!");
//	else
//		puts(".");
//	printf("\n%40s%s\n", " ", "see you again, ");
//	printf("%40s%s\n", " ", "Shalala");
//	return 0;
//}

//==========结构体指针==========
//=银行账户
//#define FUNDLEN 50
//struct funds {
//	char bank[FUNDLEN];
//	double bankfund;
//	char save[FUNDLEN];
//	double savefund;
//};
////double sum(double, double);传参声明
////double sum(const struct funds*);指针声明
//double sum(struct funds money);//参数是个结构
//int main()
//{
//	struct funds stan = {
//	"Garlic-Melon Bank",
//	3024.72,
//	"Lucky's Savings and Loan",
//	9237.11
//	};
//
//	/*printf("Stan has a total of $%.2f.\n",
//		sum(stan.bankfund,stan.savefund));*/
//	/*printf("Stan has a total of $%.2f.\n",
//		sum(&stan));*/
//	printf("Stan has a total of $%.2f.\n",
//		sum(stan));//不必取地址
//	return 0;
//}
//
////普通传递结构体成员
////double sum(double x, double y)
////{
////	return (x + y);
////}
//
////指针传递
////double sum(const struct funds*money)
////{
////	return (money->bankfund + money->savefund);
////}
//
////结构传递
//double sum(struct funds money)
//{
//	return (money.bankfund + money.savefund);
//	//不能使用->，只能使用.  理论上只有指针可以用->
//}

//=========getinfo()=========
//struct namect {
//	char* fname;
//	char* lname;
//	int letters;
//};
//void getinfo(struct namect* pst)
//{
//	char temp[81];
//	printf("please enter your first name.\n");
//	gets(temp);
//	//用来存放名字的内存
//	pst->fname = (char*)malloc(strlen(temp) + 1);
//	strcpy(pst->fname, temp);
//	//把名字复制到已分配的内存中。牛批
//	printf("please enter your last name.\n");
//	gets(temp);
//	pst->lname = (char*)malloc(strlen(temp) + 1);
//	strcpy(pst->lname, temp);
//}