//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<string>
//using namespace std;
//
//assign赋值函数
//void test() {
//	string str1;
//	str1.assign("wdnmd");
//
//	string str2;
//	str2.assign("hello C++", 5);
//	cout << str1 << str2 << endl;
//}
//字符拼接append函数。
//void test2() {
//	string str3 = "我";
//	str3 += "爱玩游戏";
//	cout << str3 << endl;
//
//	string str4 = "I";
//	str4.append(" love ");
//	cout << str4 << endl;
//
//	str4.append("game ajdkwn", 4);
//	cout << str4 << endl;
//
//	str4.append(str3);
//	cout << str4 << endl;
//
//	string str2 = "LOL DNF";
//	str4.append(str2, 0, 3);//从str3的第0个元素开始，截取三个元素
//	cout << str4 << endl;
//
//	str4.append(str2, 4, 3);
//	cout << str4 << endl;
//	相当与python里面的元组用法
//}
//
//查找find
//void test3() {
//	string str5 = "abcdefgde";
//	int position = str5.find("de");
//	if (position == -1)
//		cout << "没有找到";
//	cout << position << endl;
//
//	rfind从右往左遍历
//	find从左往右遍历
//	position = str5.rfind("de");
//	cout << position << endl;
//}
//
//替换
//void test4() {
//	string str6 = "abcdefg";
//
//	从1号位置起，3个字符，替换成12345
//	str6.replace(1, 3, "12345");
//	cout << str6 << endl;
//}
//
//比较函数compare（）
//void test5() {
//	string str7 = "hello";
//	string str8 = "hello";
//
//	if (str7.compare(str8) == 0)
//		cout << "等于" << endl;
//	else if(str7.compare(str8)>0)
//		cout << "大于" << endl;
//
//	重点判断字符串是否相等。
//	strcmp不能比较string
//}
//
//at访问单个元素
//void test6() {
//	string str8 = "hello";
//	通过[]来访问单个元素
//	for (int i = 0; i < 5; i++) {
//		cout << str8[i] << " ";
//	}
//	cout << endl;
//	通过at来访问
//	for (int i = 0; i < 5; i++) {
//		cout << str8.at(i) << " ";
//	}
//	cout << endl;
//	修改单个字符
//	str8[0] = 'X';
//	cout << str8 << endl;
//
//	str8.at(1) = 'X';
//	cout << str8 << endl;
//}
//
//字符串的插入和删除
//void test7() {
//	string str9 = "hello";
//
//	插入
//	str9.insert(1, "111");
//	cout << str9 << endl;
//
//	删除
//	str9.erase(1, 3);
//	cout << str9 << endl;
//}
//
//substr函数获取字符串字串，切片操作。
//void test8() {
//	string str10 = "abcdef";
//
//	string subStr = str10.substr(1, 3);
//
//	cout << subStr << endl;
//}
//
//实际使用substr切片操作的场景。
//void test9() {
//	string email = "zhangsanlisi@qq.com";
//
//	int pos = email.find("@");
//	cout << pos << endl;
//
//	string usrName = email.substr(0, pos);
//	cout << usrName << endl;
//}
//int main() {
//	test();
//	test2();
//	test3();
//	test4();
//	test5();
//	test6();
//	test7();
//	test8();
//	test9();
//}