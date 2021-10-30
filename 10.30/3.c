#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char ch;
	char p = 0;
	int count = 0;
	char str[5] = {0,0,0,0,'\0'};
	int i = 0;
	while ((ch = getchar()) != '\n')
		{
			if (!isspace(ch))
				p = ch;
			if (p == 'D' || p == 'G' || p == 'U' || p == 'T')
				str[i] = p;
			i++;
		}
	//scanf("%s", &str);
	if (strcmp(str,	"DGUT") == 0)
		printf("能组成DGUT\n");
	else
		printf("检索的字母中不能组成DGUT\n");
	return 0;
}
