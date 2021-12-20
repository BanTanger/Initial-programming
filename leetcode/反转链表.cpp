//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int v) :val(v), next(NULL) {}
//};
//class Solution {
//public:
//    //迭代版本
//    ListNode* reverseList(ListNode* head) {
//        ListNode* cur = head;
//        ListNode* pre = NULL;
//        while (cur) {
//            ListNode* tmp = cur->next;//保存后节点，之后要覆盖。
//            cur->next = pre;
//            pre = cur;//pre向后移动一格
//            cur = tmp;//得到之前保存的cur.next
//        }
//        return pre;//此时pre位于前链表的最后位置，新链表的头位置。
//    }
//    //递归版本
//    ListNode* reverse(ListNode* prev, ListNode* cur) {
//        if (cur == NULL)return prev;//归
//        ListNode* tmp = cur->next;
//        cur->next = prev;
//        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
//        // prev = cur;
//        // cur = tmp;
//        return reverse(cur, tmp);
//    }
//    ListNode* reverseList(ListNode* head) {
//        // 和双指针法初始化是一样的逻辑
//        // ListNode* cur = head;
//        // ListNode* pre = NULL;
//        return reverse(NULL,head);
//    }
//};