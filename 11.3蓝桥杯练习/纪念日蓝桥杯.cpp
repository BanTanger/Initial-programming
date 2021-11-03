//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n, m;
//	int days = 0;
//	cout << "输入年份的格式是20030914\n";
//	cin >> n >> m;
//	int year1 = n / 10000, year2 = m / 10000;
//	//先计算这些年有多少天，包含闰年和平年。
//	for (int i = year1+1; i <= year2; i++) {
//		//闰年判断
//		if (((i % 100 != 0) && (i % 4 == 0)) || (i % 400 == 0))
//			days += 366;
//		else days += 365;
//	}
//	//相隔的天数
//	int day1 = n % 10000, day2 = m % 10000;
//	//四位数判断，若首位是零就会自动忽略，这是为了避免有10月以上出现
//	int Sub = day1 > day2 ? (day1 - day2) : (day2 - day1);
//	days -= Sub;
//	int time = days * 24 * 60;
//	cout << time;
//}