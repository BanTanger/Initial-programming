#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int tmp = 0;
//	printf("请输入两个整数:>\n");
//	printf("ps:n,m的值都需要在两位数以上！\n");
//	scanf("%d%d", &m, &n);
//	//除10得十位数
//	if (n > m)
//	{
//		 tmp = n;
//		 n = m;
//		 m = tmp;
//	}
//	int i = 0;
//	for (i = n; i < m; i++)
//	{
//		if (i / 10 == 3 || i / 10 == 7)
//		{
//			printf("%d ", i);
//		}
//	}
//	/*else if (n < m)
//	{
//		int i = 0;
//		for (i = n; i < m; i++)
//		{
//			if (i / 10 == 3 && i / 10 == 7)
//			{
//				printf("%d ", i);
//			}
//		}
//	}*/
//	return 0;
//}

//int Count(int x)
//{
//	int count = 1;
//	while (x / 10)
//	{
//		x = x / 10;
//		count++;
//	}
//	return count;
//}
//
//void print(int input)
//{
//	int i = 0;
//	for (i = 1; i <= input; i++)
//	{
//		int j = 0;
//		for (j = 2; j <= (i / 2); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (j > (i / 2))
//		{
//			printf("%d ", i);
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	printf("请输入一个值:>");
//	scanf("%d", &input);
//	int len = Count(input);
//	printf("一共有%d位数\n", len);
//	//printf("素数:>\n%d ",i);
//	print(input);
//	return 0;
//}

#include<string.h>
#include<errno.h>
#include<stdlib.h>
//int main()
//{
//	//向内存申请10个整型空间
//	int* p = malloc(10 * sizeof(int));//可加上（int*）强制类型转换。
//	if (p == NULL)
//	{
//		//打印错误原因，strerror（）头文件是string，errno头文件是errno。
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常开辟空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;//指针往后走，解引用找到指针元素，并赋值给i，更新它
//			printf("%d ", i);
//		}
//	}
//	free(p);//主动归还内存，避免不必要的内存浪费。
//	p = NULL;//归还内存后，p的地址依然没变，要断开联系就要改变指针的地址。即指向空指针。
//	return 0;
//}

//int main()
//{
//	//realloc,更改malloc所开辟的内存。
//	
//	int* p = malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	//通过一个新的指针来接收新开辟的地址
//	int* ptr = realloc(p, 40);
//	if (ptr != NULL)
//	{
//		p = ptr;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//			//动态内存开辟的是随机值。
//			//若要更改，可通过指针移动来更新i变量的方式来打印出数据
//		}
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//动态内存分配常见错误
//int main()
//{
	//1.NULL指针进行解引用
	//int* p = (int*)malloc(10);
	//*p = 40;//若malloc开辟失败，则对空指针进行解引用

	//2.动态内存开辟的越界访问；
	//int* p = (int*)molloc(40);//10个int
	////下标为0——9
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//else
	//{
	//	int i = 0;
	//	for (i = 0; i <= 10; i++)
	//	//一不小心就可能写成i<=10，则会加十次，即十一，造成越界访问
	//	//
	//	{
	//		*(p + i) = i;
	//	}
	//}

	//3.对非动态内存的free释放
	/*int a = 0;
	int* p = &a;
	free(p);
	p = NULL;*/

	//4.使用free释放动态开辟内存的一部分
	//int* p = (int*)malloc(40);
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	*p++ = i;
	//	//通过起始地址加下标的方式去处理
	//	//*（p+i）=i则不会改变p的地址。
	//}
	//free(p);
	////free只能从动态开辟内存的起始位置开始释放空间，
	////不然p指针变化，会导致地址发生改变，这样又会导致free释放的空间不完整，造成越界访问
	//
	//p = NULL;

	//5.对同一块动态内存的多次释放
	//int* p = (int*)malloc(40);
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//free(p);
	////。。。。。。。
	//free(p);//后面没有注意到free写过一次。

	//养成好习惯，free后将p改成空指针
	//p = NULL;

	//6.对动态开辟内存忘记释放，导致内存泄露
	//while (1)
	//{
	//	malloc(1);
	//	//死循环操作来实现多次开辟不释放。
	//	//导致内存被占用
	//}
//	return 0;
//}


//int* test()
//{
//	static int a = 10;//前面加static来延长生命周期。
//	//其实本质上是将a变量从栈区转移到静态区。
//	return &a;//传地址，让指针*t来接收。
//}
//int main()
//{
//	int* t = test();
//	return 0;
//}

//柔性数组的使用。
//随意的使用realloc来开辟新的空间，比较方便
//struct S
//{
//	int n;
//	int arr[];//可以未知大小。-柔性数组成员，大小可变
//	//或者 int arr[0]
//};
//int main()
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));//计算字节时并没有包含柔性数组。
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * (sizeof(int)));
//	//加上自己认为柔性数组应该具有的大小
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;//将指针所过的地址全部初始化成0 1 2 3 4
//		printf("%d ", ps->arr[i]);
//	}
//	struct S* str = realloc(ps, 44);//用结构体指针来接收新开辟的内存空间
//	if (str != NULL)
//	{
//		ps = str;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps);
//	ps = NULL;
//		return 0;
//}

