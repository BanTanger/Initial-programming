//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//int n;
//void* FuncAn(int x)
//{
//	int i = 1;
//	if (x == 1) cout << "sin(" << x << ")";
//	else {
//		for (i = 1; i <= x; i++) {
//			cout << "sin(" << i;
//			if (i % 2 == 0) {
//				cout << "+";
//			}
//			else{
//				cout << "-";
//			}
//			if (i == x)
//				cout <<"sin(" << i << ")";
//		}
//	}
//	//cout << "\n";
//	return FuncAn;
//}
//void FuncSn(void* FuncAn(int x))
//{
//	int j = 1;
//	for (int i = n; i >= 1; i--)
//	{
//		cout << "(" ;
//		void* p = FuncAn(j);
//		cout << p;
//		cout << "+" << i;
//		cout << ")";
//		if (i == 1)
//			break;
//		j++;
//	}
//}
//int main()
//{
//	cin >> n;
//	//FuncAn(n);
//	FuncSn(FuncAn);
//}

//void FuncAn(int x)
//{
//	int i = 1;
//	if (x == 1) cout << "sin(" << x << ")";
//	else {
//		for (i = 1; i <= x; i++) {
//			cout << "sin(" << i;
//			if (i % 2 == 0) {
//				cout << "+";
//			}
//			else {
//				cout << "-";
//			}
//			if (i == x - 1) {
//				cout << "sin(" << i + 1 << "))";
//				break;
//			}
//		}
//	}
//	//cout << "\n";
//}
//void FuncSn()
//{
//	int j = 1;
//	cout << "((";
//	for (int i = n; i >= 1; i--)
//	{
//		FuncAn(j);
//		if (i == 1)
//			cout << ")";
//		cout << "+" << i;
//		cout << ")";
//		if (i == 1) {
//			cout << "\b";
//			break;
//		}
//		j++;
//	}
//}
//int main()
//{
//	cin >> n;
//	//FuncAn(n);
//	FuncSn();
//}