#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;

//void Insert(int x,int n);
struct Node* Insert(struct Node* head, int data);
void Print(struct Node* p);
void ReversePrint(struct Node* p);
void Delect(int n);
void Reverse();
int main()
{
	//int a, b, c;

	head = NULL;
	/*struct Node* head = NULL;*///局部变量写法

	//printf("Please input want to change figure and position\n");
	//scanf("%d%d", &a, &b);
	//Insert(a,b);
	/*Insert(3,1);
	Insert(5,2);
	Insert(5,3);*/
	/*head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);*/

	/*Print(head);
	ReversePrint(head);*/

	//scanf("%d", &c);
	//Delect(c);
	
	//Reverse();
	//Print();
	return 0;
}
//void Insert(int x,int n)
//{
//	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
//	temp1->data = x;
//	temp1->next = NULL;
//	if (n == 1)//空表设置，head为NULL
//	{
//		temp1->next = head;
//		head = temp1;
//		return;
//	}
//	struct Node* temp2 = head;//创建第二个结构体变量用来定位和遍历链表。
//	for (int i = 0; i < n - 2; i++)//定位到需要插入的位置的前一个。
//		temp2 = temp2->next;//指针前进操作。
//	temp1->next = temp2->next;//temp1是要插入的元素；
//	temp2->next = temp1;
//}
//void Print()
//{
//	struct Node* temp1 = head;
//	while (temp1 != NULL)
//	{
//		printf("%d ", temp1->data);
//		temp1 = temp1->next;
//	}
//	printf("\n");
//}

//=============递归============
void Print(struct Node* p)//传参传的是地址
{
	if (p == NULL) //退出条件
	{
		printf("\n");
		return;
	}
	printf("%d ",p->data);
	Print(p->next);//递归传地址
}
void Reverse(struct Node* p)
{
	if (p->next = NULL)//退出条件
	{
		head = p;
		return;
	}
	Reverse(p->next);
	//通过释放递归不断更新NULL和指针变量的位置。
	struct Node* q = p->next;
	q->next = p;
	//减少变量的一种难懂写法；
	p->next->next = p;
	p->next = NULL;
}

//void ReversePrint(struct Node* p)
//{
//	if (p == NULL)
//	{
//		printf("\n");
//		return;
//	}
//	ReversePrint(p->next);
//	printf("%d ", p->data);
//}
//struct Node* Insert(struct Node* head, int data)
//	//局部变量需要返回head的地址，指针函数写法
//{
//	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//	temp->data = data;
//	temp->next = NULL;
//	if (head == NULL)head = temp;
//	else {
//		struct Node* temp1 = head;
//		while (temp1->next != NULL)
//			temp1 = temp1->next;
//		temp1->next = temp;
//	}
//	return head;
//}
//void Delect(int n)
//{
//	struct Node* temp1 = head;
//	if (n == 1)
//	{
//		head = temp1->next;
//		free(temp1);
//	}
//	for (int i = 0; i < n - 2; i++)
//		temp1 = temp1->next;
//	struct Node* temp2 = temp1->next;//这里位置一定是在循环后面，
//	temp1->next = temp2->next;
//	free(temp2);
//}
//void Reverse()
//{
//	struct Node* current, * next, * prev;
//	prev = NULL;
//	current = head;
//	while (current != NULL)
//	{
//		next = current->next;
//		current->next = prev;
//		prev = current;
//		current = next;
//	}
//	head = prev;
//}