#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//完全缓冲与型缓冲的完全对应
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
//}
//把任何传递的东西都复制到屏幕上

//213page简单函数
//自动居中
//#include<string.h>
//#define NAME "BanTanger"
//#define ADDRESS "松山湖东莞理工"
//#define PLACE "915爹舍"
//#define WIDTH 40
//#define SPACE ' '
//
//void show_n_char(char ch, int num);
////void starbar(void);
//int main()
//{
//
//	show_n_char('*', WIDTH);
//	putchar('\n');
//	show_n_char(SPACE, (WIDTH - strlen(NAME))/2);
//	printf("%s\n", NAME);
//
//	show_n_char(SPACE, (WIDTH - strlen(ADDRESS))/2);
//	printf("%s\n", ADDRESS);
//	
//	show_n_char(SPACE, (WIDTH - strlen(PLACE))/2);
//	printf("%s\n", PLACE);
//
//	show_n_char('*', WIDTH);
//	putchar('\n');//相当于printf
//	/*starbar();
//	printf("%s", NAME);
//	printf("%s", ADDRESS);
//	printf("%s", PLACE);
//	starbar();*/
//}
//void show_n_char(char ch, int num)
//{
//	int count;
//	for (count = 0; count <= num; count++)//循环的次数由传递的参数来确定
//		putchar(ch);
//}
//void starbar()
//{
//	int count;
//	for (count = 0; count < WIDTH; count++)
//	{
//		putchar('*');
//	}
//	putchar('\n');
//}

//int main() {
//	int c = 4; int b;
//	b = (++c) + (c++) + (c++);
//	printf("b= %d ", b);
//	return 0;
//}  //运行结果是15， 

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0, c = 0;
//	b = a++;
//	c = ++a;
//	printf("%d %d", b, c);
//}

//void up_and_down(int num);
//int main()
//{
//	up_and_down(1);
//
//	return 0;
//}
//void up_and_down(int num)
//{
//	printf("%d:n 地址 %p\n", num, &num);
//	if (num < 4)
//		up_and_down(num + 1);
//	printf("%d:n 地址 %p\n", num, &num);
//}
//void add(int a);
//int main()
//{
//	int a = 0;
//	add(a);
//	return 0;
//}
//void add(int a)
//{
//	int b, c;
//	b = a++;
//	c = ++a;
//	printf("%d%d", b, c);
//}
//long fact(int n);
//long rfact(int n);
//int main()
//{
//	int num;
//	while ((scanf("%d", &num)) == 1)
//	{
//		if (num < 0)
//		{
//			printf("输入错误，请重新输入\n");
//		}
//		else if (num > 12)
//		{
//			printf("仅支持输入13以下的数字\n");
//		}
//		else
//		{
//			printf("loop: %d factorial = %ld\n", num, fact(num));
//			printf("recursion: %d factorial = %ld\n", num, rfact(num));
//		}
//	}
//	return 0;
//}
//void fact(int n)
//{
//	long
//}


//#include<ctype.h>
//int main()
//{
//	char ch;
//	char p;
//	int count=0;
//	while ((ch = getchar()) != '\n')
//	{
//		if (!isspace(ch))
//			p = ch;
//		if (p == 'D' || p == 'G' || p == 'U' || p == 'T')
//			count++;
//	}
//	if(count == 4)
//		printf("能组成DGUT\n");
//	else
//		printf("检索的字母中不能组成DGUT\n");
//	return 0;
//}

int main()
{
	int H = 0;
	int n = 0;
	int ret=0;
	int count=0;
	printf("定义本次实验的米数");
	scanf("%d", &H);

	printf("定义本次实验在多少次停止统计");
	scanf("%d", &n);

	while (H > 0)
	{
		H /= 2;
		ret += H;
		count++;
		if (n == count)
			break;
	}
	if (H == 0 || n != count)
		printf("H值过小或n过大\n");
	else
		printf("在%d次时走过的路程是%d,第%d次反弹的高度是%d", n, ret, n, H);
	return 0;
}