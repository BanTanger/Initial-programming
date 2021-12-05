#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;
//#define MAX 30
//int Count = 0;
////bit位代表在进行哪一层次的计数，如1，2，3.1，2，4.。。。2，3，4.2，3，5
////index代表第三位的数移动。直到移动到n。
//bool isPrime(int sum) {
//	bool flag = true;
//	for (int i = 2; i < sum / 2; i++) {
//		if (sum % i == 0) {
//			flag = false;
//			break;
//		}
//	}
//	if (flag == false) return false;
//	else return true;
//}
//void func(int* arr, int* tmp, int bit, int index, int& n, int& m) {
//	for (int i = index; i < m; i++) {
//		tmp[bit] = arr[i];
//		if (bit < n)
//			func(arr,tmp, bit + 1, i + 1, n, m);
//		if (bit == n - m) {
//			//bit == n - m 是为了让bit从递归中被清除到1.
//			int sum = 0;//进行计数sum
//			for (int j = 0; j < n; j++) 
//				sum += tmp[j];
//			if (isPrime(sum))//统计素数函数
//				Count++;
//		}
//	}
//}
//int main() {
//	int n, m;
//	cin >> n >> m;
//	int arr[MAX];
//	int tmp[MAX] = { 0 };//建立一个数组来存放每一次总和
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	func(arr,tmp, 0, 0,n,m);
//	cout << Count << endl;
//}

int x[20], n, k;//依照题目所设
bool isprime(int n) {//判断是否质数
    int s = sqrt(double(n));
    for (int i = 2; i <= s; i++) 
        if (n % i == 0)
            return false;
    return true;
}
int rule(int choose_left_num, int already_sum, int start, int end) {
    //choose_left_num为剩余的k，already_sum为前面累加的和，
    //start和end为全组合剩下数字的选取范围；
    //调用递归生成全组合，在过程中逐渐把K个数相加，
    //当选取的数个数为0时，直接返回前面的累加和是否为质数即可
    if (choose_left_num == 0)
        return isprime(already_sum);
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += rule(choose_left_num - 1, already_sum + x[i], i + 1, end);
    }
    return sum;
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cout << rule(k, 0, 0, n - 1) << endl;//调用递归解决问题
}

//int sushu(int n);
//void fun(int n, int m);
//
//int a[22], b[21], n, k, t = 0;
//
//int main()
//{
//    int i;
//    scanf("%d%d", &n, &k);
//    for (i = 1; i <= n; i++)
//        scanf("%d", &a[i]);
//    fun(n, k);
//    printf("%d", t);
//}
//
//void fun(int n, int m)//从n里面选m个数字 
//{
//    int i, sum;
//    if (m == 0){
//        sum = 0;
//        for (i = 0; i < k; i++)
//            sum += b[i];
//        if (sushu(sum))
//            t++;
//        return;
//    }
//    for (i = n; i >= m; i--){
//        b[m - 1] = a[i];
//        fun(i - 1, m - 1);
//    }
//}
//int sushu(int n)
//{
//    int i;
//    for (i = 2; i < n; i++)
//        if (n % i == 0)
//            break;
//    if (i == n || n == 2)
//        return 1;
//    else
//        return 0;
//}