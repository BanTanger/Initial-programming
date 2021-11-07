//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//
////int main()
////{
////	string digits[10] = {"","","shi","bai","qian","wan","bai","qian","yi","shi"};
////	string number[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
////	string str ;//下标对应就行。减一操作？
////	cin >> str;
////	int l = str.length();
////	for (int i = 0; i < l; i++) {
////		int num = str[i] - '0';//字符转化成数值
////		if (num == 0) {
////			if (i + 1 < l && str[i + 1] != '0')
////				cout << number[num] << " ";
////		}
////		else if ((l - i == 2 || l - i == 8 || l - i == 10)&& num == 1)
////			cout << digits[l - i] << " ";
////		else
////			cout << number[num] << " " << digits[l - i]<<" ";
////	}
////
////}
//
//int main()
//{
//	string digits[11] = { "","","十","百","千","万","十","百","千","亿","十" };
//	string number[10] = { "〇","壹","贰","叁","肆","伍","陆","柒","仈","玖" };
//	string str;//下标对应就行。减一操作？
//	cin >> str;
//	int len = str.length();
//	for (int i = 0; i < len; i++) {
//		int num = str[i] - '0';//字符转化成数值
//		//int num = str[i] ;//字符转化成数值
//		//num == 0的特殊处理。
//		if (num == 0) {
//			//多位有零只读一次。
//			if (i + 1 < len && str[i + 1] != '0')
//				cout << number[num] << " ";
//		}
//		else if ((len - i == 2 || len - i == 6 || len - i == 10) && num == 1)
//			cout << digits[len - i] << " ";//len - i控制位数指针移动。
//		else
//			//数字加位数.
//			cout << number[num] << " " << digits[len - i] << " ";
//	}
//
//}