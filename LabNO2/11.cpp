//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<stdio.h>
//#include<queue>
//using namespace std;
//int main(int argc,char *argv())
//{
//	queue<int> Qx, Qy;
//	int n, m, i, j, x, y,tmp;
//	int arr[100][100];
//	int count = 0;//计入细胞。
//
//	scanf("%d%d", &n, &m);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			//printf("%d ", arr[i][j]);
//		}
//		//printf("\n");调试
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			if (arr[i][j] != 0)
//			{
//				tmp = arr[i][j];
//				Qx.push(i);
//				Qy.push(j);
//				arr[i][j] = 0;
//				while (!Qx.empty())
//				{
//					x = Qx.front(); Qx.pop();
//					y = Qy.front(); Qy.pop();
//					
//					if ( (y + 1 < m) && (arr[x][y + 1] != 0))//向右走检索同元素
//					{
//						Qx.push(x); Qy.push(y + 1);//将该坐标压入栈区
//						arr[x][y+1] = 0;//清空该位置
//					}
//					if ((x + 1 < m) && (arr[x + 1][y] != 0))//向右走检索同元素
//					{
//						Qx.push(x+1); Qy.push(y );//将该坐标压入栈区
//						arr[x+1][y] = 0;//清空该位置
//					}
//					if ((y - 1 < m) && (arr[x][y - 1] != 0))//向右走检索同元素
//					{
//						Qx.push(x); Qy.push(y - 1);//将该坐标压入栈区
//						arr[x][y-1] = 0;//清空该位置
//					}
//					if ((x - 1 < m) && (arr[x - 1][y] != 0))//向右走检索同元素
//					{
//						Qx.push(x - 1); Qy.push(y);//将该坐标压入栈区
//						arr[x - 1][y] = 0;//清空该位置
//					}
//				}
//				
//			}
//			count++;
//		}
//
//		printf("%d\n",count);
//		return 0;
//	}
//}