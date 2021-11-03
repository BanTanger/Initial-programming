//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//这里root做成局部变量，不然全局变量会导致出错。
//struct BstNode {
//	int data;
//	BstNode* left;
//	BstNode* right;
//};
//BstNode* GetNewNode(int data)
//{
//	BstNode* newNode = new BstNode();
//	newNode->data = data;
//	newNode->right = newNode->left = NULL;
//	return newNode;
//}
//BstNode* Insert(BstNode* root,int data)
//{
//	//函数调用迭代处理
//	if (root == NULL)
//		root = GetNewNode(data);
//	else if (data <= root->data)
//		root->left = Insert(root->left, data);
//	else
//		root->right = Insert(root->right,data);
//	return root;
//}
//bool Search(BstNode* root,int data)
//{
//	if (root == NULL) return false;
//	else if (data == root->data) return true;
//	else if (data <= root->data) return Search(root->left, data);
//	else return Search(root->right, data);
//}
//int main()
//{
//	BstNode* root = NULL;
//	root = Insert(root, 12); root = Insert(root, 15); root = Insert(root, 14);
//	root = Insert(root, 11); root = Insert(root, 20); root = Insert(root, 25);
//	int number;
//	cout << "请输入数值\n";
//	cin >> number;
//	if (Search(root, number) == true)cout << "Found\n";
//	else cout << "Not Found\n";
//}