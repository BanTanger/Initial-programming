//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//struct ListNode {
//	int val;
//	struct ListNode* Next;
//	ListNode(int v) :val(v), Next(NULL) {}//构造函数的设计
//};
//class Solution {
//public:
//	ListNode* removeElements(ListNode* head, int val) {
//		//删除头节点
//		while (head != NULL && head->val == val) { // 注意这里不是if
//			//因为可能有多个头节点值相同，所以这里需要用while循环判断。
//			ListNode* tmp = head;//做一个临时变量来存放头节点，到时候释放临时变量达到删除头节点的效果。
//			head = head->Next;
//			delete tmp;
//		}
//		//删除非头节点
//		ListNode* current = head;
//		while (current->Next != NULL && current != NULL) {
//			//根据链表跳跃性质，需要对当前节点后面和后后面的指向情况做出判断。
//			if (current->Next->val == val) {
//				//当前节点后面节点的值是需要删除的值进入
//				ListNode* tmp = current->Next;
//				current->Next = current->Next->Next;//改变当前节点指向，指向后后节点。
//				delete tmp;//删除后节点。
//			}else {
//				current == current->Next;//链表前进。
//			}
//		}
//		return head;//返回头节点用于后续的打印，插入，逆序等等操作。
//	}
//};
////虚拟头节点的设置
//class Solution {
//	ListNode* removeElements(ListNode* head, int val) {
//		ListNode* dummyHead = new ListNode(0);// 设置一个虚拟头结点
//		dummyHead->Next = head;// 将虚拟头结点指向head，这样方面后面做删除操作
//		ListNode* current = dummyHead;
//		while (current != NULL && current->Next != NULL) {
//			if (current->Next->val == val) {
//				ListNode* tmp = current->Next;
//				current->Next = current->Next->Next;
//				delete tmp;
//			}
//			else {
//				current = current->Next;
//			}
//		}
//		head = dummyHead->Next;
//		delete dummyHead;
//		return head;
//	}
//};
