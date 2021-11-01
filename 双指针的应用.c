#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
//bool plalindrome(char* p)
//{
//	int i;
//	int len = strlen(p);
//	for (i = 0; i < len / 2; i++)
//	{
//		if (p[i] != p[len - i - 1])
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	char p[100];
//	gets(p);
//	if (plalindrome(p))
//		printf("true\n");
//	else
//		printf("false\n");
//}

//通过遍历指针的方式得到左右指针。双指针应用的高级
int main()
{
	char* s1,*s2, *s,temp;
	s1 = (char*)malloc(sizeof(100));
	gets(s1);
	s = s2 = s1;
	while (*s2 != '\0')
		s2++;//遍历指针到末尾元素
	s2--;
	while (s1 < s2)
	{
		temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++;
		s2--;
	}
	printf("%s\n", s);
}