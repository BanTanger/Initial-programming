#include<stdio.h>

//================数组冒泡排序====================
void bubble_sort(int arr[],int sz)
{//字符个数的计算无法在函数内部实现，于是写在主函数内再传参的方式达成目的。
	int i = 0;
	int flag = 1;//假设这一趟要排序的数据已经有序了.
	for (; i < sz - 1; i++)//每一趟冒泡排序
	{	
		int j = 0;
		for (; j < sz - i - 1; j++)//每趟需要校检的个数
		{
			if (arr[j] > arr[j + 1]);//传值
			{int tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp; 
			flag = 0;}//本趟排序的数据并不完全有序
		}
		if (flag == 1)//通过改变flag的值来选择语句
		{	
			break;
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//对arr进行排序，排成升序
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%c\n", arr[3]);
//	int i = 0;
//	for (; i < (int)strlen(arr); i++)
//		printf("%c ", arr[i]);
//	return 0;
//}



//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (; i < sz; i++)
//		printf("arr[%d]=%p\n", i, &arr[i]);
//	return 0;
//}

//============================二维数组==============================
//int main()
//{
//	int arr[3][4] = { 1,2,3,4,5 };
//	int arr[][4] = { {1,2,3,4},{5,6,7,8} };
//	return 0;
//}

//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8} };
//	int i = 0;
//	for (; i < 3; i++)
//	{
//		int j = 0;
//		for (; j < 4; j++)
//		{	
//			printf("&arr[%d][%d]=%p\n", i, j, &arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*int main()
{
	int arr[3][4] = { {1,2,3,4},{5,6,7,8} };
	int i = 0;
	for (; i < 3; i++)
	{
		int j = 0;
		for (; j < 4; j++)
		{	
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/