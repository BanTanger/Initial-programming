#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#define MAX 20
/*编写一个C程序，实现以下功能：
编写一个函数，该函数能判断一个英文句子str(不带空格)中是否含有某个单词w,如“Howoldareyou?”含有“old”。
在main函数中输入一个英文句子，再输入一个单词，如果英文句子中含有那个单词，则输出“YES”，否则输出“NO”。
*/

void Estimate(char *str,char* word,int n) {
	char p;
	p = str;
	bool flag;
	flag = false;
	int i = 0;
	for (int i = 0; i < n && p != '\0'; i++)
	{
		if (str[p] == word[i]) {
			p++;
			i++;
			flag = true;
		}
		else
			flag = false;
	}
	if (!flag)
		printf("Yes");
	else
		printf("No");
}
int main() {
	char str[MAX];
	char word[MAX];
	gets(str);
	gets(word);
	Estimate(str, word, strlen(word)-1);
}