#include<stdio.h>

int main()
{
	//计算元素个数
	//整个数组所占字节/单个元素所占字节。
	int arr[10] = { 0 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(int);
	printf("%d\n",sz);
}
//int main()
//{
//	int a = 10;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof a);
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof int);
//
//
//}

//int main()
//{
//	//(2进制)位操作
//	//& 按位与
//	//| 按位或
//	//^ 按位异或
//	int a = 3;
//	int b = 5;
//	int c = a & b;
//
//	printf("%d\n", c);
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = a << 1;//<<左移操作符，>>右移操作符。
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	int a = 5 % 2;//取模 打印出来为余数  5/2  打印出来为商
//	printf("%d\n", a);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%d\n", arr[4]);//用下标访问元素
//	//arr[下标]
//	//char ch[20];
//	int i=0;
//	while (i < 10)
//	{
//		printf("%d ",arr[i]);
//		i++;
//	}
//
//	return 0;

//}


//#define _CRT_SECURE_NO_WARNINGS //

//=================================作用域===============================
//int main()
//{
//	int num = 0;
//	{
//		
//		printf("%d\n", num);
//	}
//	
//}
//==============================外部作用域==============================
//int main()
//{
//	//extern int g_val;
//	printf("g_val = %d/n", g_val);
//	return 0;

//}





//=================================计算两个数的和=======================================
//int ADD(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	int sum ;
//	//输入数据 使用输入函数
//	//scanf_s("%d%d", &num1, &num2);//&取地址符号
// sum = ADD(num1, num2);
//	printf("sum = %d\n", sum);
//	return 0;
//}

//int a = 10;
//
//int main()
//{
//	/*{
//		int a = 10;
//	}*/
//	printf("%d\n", a);
//	return 0;
//}
//
////错误原理，局部变量只能在局部范围内使用


//int a = 100;
//
//int main()
//{
//	int a = 10;//名字相同，局部优先。
//	//局部变量和全局变量的名字不要相同。容易出bug
//	printf("%d\n", a);
//
//}
//




//int num = 20;//全局变量 定义在代码块{}之外的变量
//
//int main()//主函数，程序的入口，main'函数有且只有一个
//{
//
//	int num1 = 10;//局部变量，定义在代码块之内


	//short age = 20;
	//float weigth = 95.6f;//系统默认为双精度值，可在数字后加上f
	
	//printf("%d\n", sizeof(char));//字符数据类型		
	//printf("%d\n", sizeof(short));//短整型	
	//printf("%d\n", sizeof(int));//整形
	//printf("%d\n", sizeof(long));//长整型  有可能是4/8  C语言规定long大于等于int
	//printf("%d\n", sizeof(long long));//更长的整形
	//printf("%d\n", sizeof(float));//单精度浮点数
	//printf("%d\n", sizeof(double));//双精度浮点数 


	
	//字节  计算机中的单位  bit 比特位(最小单位)  byte 字节 
	//kb  mb  gb  tb  pb  进制为1024
	
//	return 0;
//
//}







//原则，先写主体
/*  #include<stdio.h>
   int main(void)
{
	return 0
}*/

//int是整型
//printf  库函数，c语库里自带，需要调用，这就需要#include<stdio.h>
//#include<stdio.h>   <>必须要有，不用“；” std标准，standard。i，input 。 o，output

//%d,打印整型
//%c,打印字符
//%f,打印浮点型，小数
//%p,以地址为形式打印
//%x，打印16进制打印

//{
// float f = 5.0;
// printf("%f\n", f);
// 
//
//
// return 0;
//}


//===========================================================
