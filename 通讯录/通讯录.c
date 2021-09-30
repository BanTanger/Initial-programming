#define _CRT_SECURE_NO_WARNINGS 1

#include"通讯录.h"

//函数实现
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//初始化通讯录，设置最初只有0个元素。
}
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入性别：>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入年龄：>");
		scanf("%s", &ps->data[ps->size].age);
		printf("请输入地址：>");
		scanf("%s", ps->data[ps->size].addr);
		printf("请输入电话：>");
		scanf("%s", ps->data[ps->size].tele);
		/*printf("请输入名字：>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入名字：>");
		scanf("%s", ps->data[ps->size].name);*/

		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//打印标题
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//打印数据
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字：>");
	scanf("%s", name);//数组名就是地址，所以不用取地址
	//1.查找要删除的人在什么位置
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			break;
			//找到位置再跳出
		}
	}
	//2.删除
	if (i == ps->size)
	{
		printf("要删除的人并不存在\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < ps->size - 1;j++)
		//此时i就是要删除人的地址，
		//于是将i赋值给j，即可实现指定位置的操作
		//因为覆盖掉一个元素，所以ps.size - 1
		{
			ps->data[j] = ps->data[j + 1];
			//通过后一个元素将前一个元素所覆盖，这样就可以实现删除
		}
		ps->size--;
		printf("删除成功\n");
	}
}