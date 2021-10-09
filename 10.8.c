#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	printf("******************************************\n");
//	printf("                 very good                \n");
//	printf("******************************************\n");
//	return 0;
//}

//void toBinary(unsigned long n);
//int main()
//{
//	unsigned long num = 0;
//	printf("enter an intager(q to quit):\n");
//	while (scanf("%ul", &num) == 1)
//	{
//		printf("binary equivalent:");
//		toBinary(num);
//		putchar('\n');
//		printf("enter an integer(q to quit):\n");
//	}
//	return 0;
//}
//void toBinary(unsigned long n)
//{
//	int r;
//	r = n % 2;
//	if (n >= 2)
//		toBinary(n / 2);
//	putchar(r ? '1':'0');
//}

//int main()
//{
//	int nights;
//	while (scanf("%d", &nights) != 1)
//	{
//	/*	scanf("%*s");*/
//		printf("please enter an intager,such as 2.\n");
//	}
//
//	return 0;
//}

//void intexchange(int* u,int* v);
//int main()
//{
//	int x = 5;
//	int y = 10;
//	printf("originary : x=%d,y=%d\n", x, y);
//	intexchange(&x, &y);
//	printf("now : x=%d,y=%d\n", x, y);
//	return 0;
//}
//void intexchange(int* u, int* v)
//{
//	int tmp;
//	tmp = *u;
//	*u = *v;
//	*v = tmp;
//}

//========c99Ьиад===========
//int main()
//{
//	int arr[6] = { [5] = 212 };
//	printf("%d", arr[5]);
//	return 0;
//}

void sup(int* x, int* y);
int main()
{
	int a = 5;
	int b = 10;
	printf("orginally:%d %d\n", a, b);
	sup(&a,&b);
	printf("now:%d %d\n", a, b);
}
void sup(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	/*printf("%d %d", x, y);*/
}
