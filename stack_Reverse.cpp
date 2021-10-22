#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;
//=========逆转数组============
//void Reverse(char C[], int n)
//{
//	stack<char> S;//<>写数据类型，后面写名字
//	for (int i = 0; i < n; i++)
//	{//loop for push
//		S.push(C[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{//loop for pop
//		C[i] = S.top();
//		S.pop();
//	}
//}
//int main()
//{
//	char C[51];
//	printf("Enter a string:");
//	gets_s(C);
//	Reverse(C,strlen(C));
//	printf("Output = %s", C);
//	printf("\n");
//}

//struct Node {
//	int data;
//	Node* next;
//};
//struct Node* head;
//void Reverse()
//{
//	if (head == NULL)return;
//	stack<struct Node*> S;
//	Node* temp = head;
//	while (temp != NULL)
//	{
//		S.push(temp);
//		temp = temp->next;
//	}
//	temp = S.top(); head = temp;
//	S.pop();
//	while (!S.empty()) {
//		temp->next = S.top();
//		S.pop();
//		temp = temp->next;
//	}
//	temp->next = NULL;
//	//最后一次循环因为内存释放实际上没有指向头节点，
//	//而是指向了倒数第二个节点
//}
//int main()
//{
//	head = NULL;
//}