#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define MAX 500
#include<algorithm>
struct people {
	int chinese;
	int english;
	int math;
	int sum;
	int num;//编号
}students[MAX];
//比较函数一般自己构造。结构体部分元素的排序通过sort的比较函数部分实现。
bool compare(people s1, people s2)
{
	if (s1.sum > s2.sum) return 1;
	else if (s1.sum < s2.sum) return 0;
	else
	{
		if (s1.chinese > s2.chinese) return 1;
		else if (s1.chinese < s2.chinese) return 0;
		else
		{
			if (s1.num > s2.num) return 0;
			else return 1;
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		students[i].num = i;
		cin >> students[i].chinese >> students[i].english >> students[i].math;
		students[i].sum = students[i].chinese + students[i].english + students[i].math;
	}
	sort(students+1, students+1 + n, compare);
	for (int i = 1; i <= n ; i++)
		cout << students[i].num << " " << students[i].sum << endl;
}