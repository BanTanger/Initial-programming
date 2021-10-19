#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//===============头节点插入数值==============
//struct Node
//{
//	int data;//数值
//	struct Node* next;//存放下一个节点的地址
//};
//struct Node* head;//全局变量，所有函数都可见，比较方便
//
//void Insert(int x);
//void Print();
//int main()
//{
//	head = NULL;//创建空链表
//	printf("how many numbers?\n");
//	int n, i, x;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		printf("Enter the number\n");
//		scanf("%d", &x);
//		Insert(x);
//		Print();
//	}
//}
//void Insert(int x)
//{
//	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//	//创建一个节点。用malloc，参数是一个结构体指针的大小，sizeof(struct Node).
//	temp->data = x;//数值更改，也就是要插入的数值
//	//temp->next = NULL;//下一个节点指向空地址，为链表末端。
//		//只有链表为空的时候才会实现的语句。
//		//因为head是不断更新的，所以temp.next= head其实包括了这条语句。
//	 
//		//head = temp;//头文件去指向第一个节点，代表这个链表为空。
//	//if (head != NULL)
//	temp->next = head;//链表不为空时这样设置。可实现链表的连接
//	//将新建的节点Node连接到头节点/
//	head = temp;
//}
//void Insert(int x)
//{
//	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//	temp->data = x;
//	temp->next = head;
//	//head在main函数里已经被初始化成null了，所以这里开始是空链表。
//	head = temp;//head更新。
//}
//void Print()
//{
//	struct Node* temp = head;
//	//设置一个临时变量，它第一个指向头文件的地址，
//	//之后循环使用temp来实现，避免改变头文件的值导致无法寻址
//	printf("List is:");
//	while (temp != NULL)
//	{
//		printf(" %d", temp->data);//打印值。
//		temp = temp->next;//更新节点。
//	}
//	printf("\n");
//}

//struct Node {
//	int data;
//	struct Node* next;
//};
//struct Node* head;
//
//void Insert(int data,int n);
//void Print();
//int main()
//{
//	head = NULL;
//	Insert(3,1);
//	Insert(1,2);
//	Insert(8,3);
//	Print();
//	return 0;
//}
//void Insert(int data, int n)
//{
//	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
//	temp1->data = data;
//	temp1->next = NULL;
//	if (n == 1)
//	{
//		temp1->next = head;
//		head = temp1;
//		return;
//	}
//	struct Node* temp2 = head;
//	for (int i = 0; i < n - 2; i++)
//		temp2 = temp2->next;//变量是可以随便赋的，可多个。
//	temp1->next = temp2->next;
//	temp2->next = temp1;//下一个节点存储temp1本身地址。
//	//节点地址不等于节点指向地址。
//}
//void Print()
//{
//	struct Node* temp = head;
//	while (temp != NULL)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//	printf("\n");
//}

