#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>
#ifndef LIST_H
#define LIST_H

//特定于本程序的定义
#define TSIZE 45
#define CLP const List* plist
#define LP List* plist
struct film
{
	char title[TSIZE];
	int rating;
};
//将结构体一般定义类型
typedef struct film Item;

//结构体嵌套
typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node* List;
void InitalizeList(LP);//初始化链表
bool ListIsEmpty(CLP);//确定链表是否为空，plist指向一个已初始化的链表
bool ListIsFull(CLP);//确定链表是否满了
unsigned int ListItemCount(CLP);//确定链表项目个数
bool AddItem(Item item, LP);//增添新项目



