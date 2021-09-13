#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int cmp(const void* e1, const void* e2)
//{
//	return ((int)((float*)e1 - (float*)e2));
//}
//
//int test1()
//{
//	float f[] = { 5.0,6.8,7.5,2.9,4.5,7.3,4.1 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", f[i]);//浮点数的打印是%f
//	}
//}
//int main()
//{
//	test1();
//	return 0;
//}
struct Stu
{
	char name[10];
	int age[20];
};

int cmp(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->age, ((struct Stu*)e2)->age);
}

void test3()
{
    struct Stu s[3] = { {"张三",30} ,{"李思思",60} ,{"二麻子",45} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%")
	}
}

int main()
{
	test3();
	return 0;
}