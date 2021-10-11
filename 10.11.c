#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40
int main(int argc, char* argv[])
{
	FILE* out, * in;//声明两个文件指针
	int ch;
	char name[LEN];//存储输入文件名
	int count = 0;
	//检查命令行参数
	if (argc < 2)
	{
		fprintf(stderr, "usage:%s filename\n", argv[0]);
		exit(1);//异常退出
	}
	//实现输入
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "i couldn't open the file \"%s\"\n",argv[1]);
		exit(2);
	}
	//实现输出
	strcpy(name, argv[1]);//把文件名复制到数组中
	strcat(name, ".red");//文件名后加后缀“red.”
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "can't create output file.\n");
		exit(3);
	}
	//复制数据 
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	//收尾工作
	if (!fclose(in) || !fclose(out))
		fprintf(stderr, "error in closing files\n");
	return 0;
}
