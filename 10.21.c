#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//typedef struct Node {
//	int data;
//	struct Node* next;
//	struct Node* prev;
//}n;
//struct Node* head;
//struct Node* GetNewNode(int x)
//{
//	n* newNode = (n*)malloc(sizeof(n));
//	newNode->data = x;
//	newNode->next = NULL;
//	newNode->prev = NULL;
//	return newNode;
//}
//void InsertAtHead(int x)
//{
//	n* newNode = GetNewNode(x);
//	if (head == NULL) {
//		head = newNode;
//		return;
//	}
//}
//int main()
//{
//	head = NULL;
//}

//void print(char* C)
//{//这里C不是数组，只是一个指向数组基地址的一个指针，
//	//可通过指针的运算来移动指针实现遍历数组
//	//而数组却不能使用运算法则。
//	while (*C != '\0')
//	{
//		printf("%c", *C);
//		C++;
//	}
//	printf("\n");
//}
//int main()
//{
//	/*char C[20] = "HELLO";*/
//	char* C = "HELLO";//也能得到结果
//	print(C);
//	return 0;
//}


//int main()
//{
//	int n;
//	printf("Enter size of array\n");
//	scanf("%d", &n);
//	int* arr = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = i + 1;
//		//printf("%d ", arr[i]);
//	}
//	int* B = (int*)realloc(arr, 2 * n * sizeof(int));
//	for (int i = 0; i < n * 2; i++)
//	{
//		printf("%d\n", B[i]);
//	}
//	
//	printf("\n");
//	free(arr);
//	free(B);
//}

//int* Add(int* a, int* b)
//{
//	int* c = (int*)malloc(sizeof(int));
//	//malloc库函数会返回一个指针，（地址）
//	*c = (*a) + (*b);
//	return c;
//}
//
//int main()
//{
//	int a = 4, b = 2;
//	int* c = Add(&a,&b);
//	printf("%d\n", *c);
//}

//函数指针
//void PrintHello(char* name)
//{
//	printf("Hello %s", name);
//}
//int main()
//{
//	void(*ptr)(char*);
//	ptr = PrintHello;
//	ptr("TMD\n");
//}
//void A()
//{
//	printf("hello\n");
//}
//void B(void (*ptr)())
//{
//	ptr();
//}
//int main()
//{
//	B(A);
//}