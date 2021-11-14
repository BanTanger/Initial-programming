//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//#define MAX 20
//int main()
//{
//	int arr[MAX][MAX];
//	int i, j,n,m,ans = 0,x = 0,y = 0;//ans是步数
//	cin >> n >> m;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < m; j++) {
//			cin >> arr[i][j];
//		}
//	}
//	while (ans < n * m) {
//		while (x < n && arr[x][y] != -1) {//下走
//			cout << arr[x][y] << " ";
//			arr[x][y] = -1;
//			ans++;
//			x++;
//		}
//		x--; y++;//x遍历回弹，y自增往右走
//		while (y < m && arr[x][y] != -1) {//右走
//			cout << arr[x][y] << " ";
//			arr[x][y] = -1;
//			ans++;
//			y++;
//		}
//		y--; x--;//x--向上走
//		while (x >= 0 && arr[x][y] != -1) {//上走
//			cout << arr[x][y] << " ";
//			arr[x][y] = -1;
//			ans++;
//			x--;
//		}
//		x++; y--;//x回弹
//		while (y >=0 && arr[x][y] != -1) {//左走
//			cout << arr[x][y] << " ";
//			arr[x][y] = -1;
//			ans++;
//			y--;
//		}
//		x++; y++;
//	}
//}