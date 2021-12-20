//#include<iostream>
//using namespace std;
//
//class MyListNode {
//public:
//	struct ListNode {
//		int val;
//		ListNode* Next;
//		ListNode(int v) :val(v), Next(NULL) {}
//	};
//	//链表的初始化
//	MyListNode(){
//		_dummyHead = new ListNode(0);
//		_size = 0;
//	}
//	//获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
//	int get(int index) {
//		if (index > (_size - 1) || index < 0) {
//			return -1;
//		}
//		ListNode* cur = _dummyHead->Next;
//		while (index--) { // 如果--index 就会陷入死循环
//			cur = cur->Next;
//		}
//		return cur->val;
//	}
//	//头节点插入元素
//	void AddOfHead(int val) {
//		ListNode* newNode = new ListNode(val);
//		newNode->Next = _dummyHead->Next;
//		_dummyHead->Next = newNode;
//		_size++;
//	}
//	//尾节点插入元素
//	void AddOfTail(int val) {
//		ListNode* newNode = new ListNode(val);
//		ListNode* current = _dummyHead;
//		while (current->Next != NULL) {
//			current = current->Next;
//		}
//		current->Next = newNode;
//		//这里因为在构造函数中已经构造出节点默认指向是NULL,所以可以不用像C那样写出指向NULL
//		_size++;
//	}
//	//索引添加元素
//	void AddOfIndex(int index, int val) { 
//		//index合法性检验
//		if (index > _size) {
//			return;
//		}
//		ListNode* newNode = new ListNode(val);
//		ListNode* current = _dummyHead;
//		//将current节点指向虚拟头节点，达到index==0时插入的元素在头节点之后。
//		while (index--) {
//			current = current->Next;
//		}
//		newNode->Next = current->Next;
//		current->Next = newNode;
//		_size++;
//	}
//	//删除操作
//	void deleteIndex(int index) {
//		//对删除的位置判断
//		if (index > _size || index < 0) {
//			return;
//		}
//		ListNode* current = _dummyHead;
//		while (index--) {
//			current = current->Next;
//		}
//		ListNode* tmp = current->Next;
//		current->Next = current->Next->Next;
//		delete tmp;
//		_size--;
//	}
//	//打印链表
//	void PrintListNode() {
//		ListNode* current = _dummyHead;
//		while (current->Next != NULL) {
//			cout << current->val << " ";
//			current = current->Next;
//		}
//		cout << endl;
//	}
//private:
//	int _size;
//	ListNode* _dummyHead;
//};