#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n, m, i = 0, j = 0, L = 0;
//	cout << "输入行和列";
//	cin >> n >> m;
//	int arr[3][3];
//	//int barr[200];
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	while (L < m * n) {//L作为计数变量。
//		//向下； 
//		for (i = 0; arr[i][j] > 0 && i < m;) {
//			//barr[n] = arr[i][j];
//			cout << arr[i][j] << " ";
//			arr[i][j] = 0;//每次打印完就清除；
//			L++; i++;
//		}
//		j++;
//		//向右； 
//		for (j = 0; arr[i][j] > 0 && j < n;) {
//			//barr[n] = arr[i][j];
//			cout << arr[i][j] << " ";
//			arr[i][j] = 0;//每次打印完就清除；
//			L++; j++;
//		}
//		i++;
//		for (i = n; arr[i][j] > 0 && i >= 0;) {
//			//向上； 
//			//barr[n] = arr[i][j];
//			cout << arr[i][j] << " ";
//			arr[i][j] = 0;//每次打印完就清除；
//			L++; i--;
//		}
//		j--;
//		for (j = m; arr[i][j] > 0 && j >= 0;) {
//			//向左；
//			//barr[n] = arr[i][j];
//			cout << arr[i][j] << " ";
//			arr[i][j] = 0;//每次打印完就清除；
//			L++; j--;
//		}
//		i++;
//	}
//	return 0;
//}

/*
基础练习 回形取数
问题描述
　　回形取数就是沿矩阵的边取数，若当前方向上无数可取或已经取过，则左转90度。一开始位于矩阵左上角，方向向下。
输入格式
　　输入第一行是两个不超过200的正整数m, n，表示矩阵的行和列。接下来m行每行n个整数，表示这个矩阵。
输出格式
　　输出只有一行，共mn个数，为输入矩阵回形取数得到的结果。数之间用一个空格分隔，行末不要有多余的空格。
样例输入
3 3
1 2 3
4 5 6
7 8 9
样例输出
1 4 7 8 9 6 3 2 5
样例输入
3 2
1 2
3 4
5 6
样例输出
1 3 5 6 4 2
*/
#include <stdio.h>
#include <string.h>

#define MAX_N 200
int m, n;
int a[MAX_N][MAX_N], b[MAX_N][MAX_N];//新定义一个数组;
int s = 0;
void solve(int i, int j)
{
    if (i < m && i >= 0 && j < n && j >= 0 && b[i][j] == 0)
    {
        printf("%d ", a[i][j]);
        b[i][j] = 1;
    }
    else
    {
        s++;
        return;
    }
    if (s % 4 == 0)
        solve(i + 1, j);
    if (s % 4 == 1)
        solve(i, j + 1);
    if (s % 4 == 2)
        solve(i - 1, j);
    if (s % 4 == 3)
        solve(i, j - 1);
    if (s % 4 == 0)
        solve(i + 1, j);
    if (s % 4 == 1)
        solve(i, j + 1);
    if (s % 4 == 2)
        solve(i - 1, j);
    if (s % 4 == 3)
        solve(i, j - 1);

    return;
}

int main()
{
    memset(b, 0, sizeof(b));//清空数组；
    scanf("%d%d", &m, &n);
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    solve(0, 0);
    puts("");
    return 0;
}