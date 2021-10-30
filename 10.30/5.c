//#define _CRT_SECURE_NO_WARNINGS 1
//int main()
//{
//	int H = 0;
//	int n = 0;
//	int ret = 0;
//	int count = 0;
//	printf("定义本次实验的米数");
//	scanf("%d", &H);
//
//	printf("定义本次实验在多少次停止统计");
//
//	scanf("%d", &n);
//
//	while (H > 0)
//	{
//		H /= 2;
//		ret += H;
//		count++;
//		if (n == count)
//			break;
//	}
//	if (H == 0 || n != count)
//		printf("H值过小或n过大\n");
//	else
//		printf("在%d次时走过的路程是%d,第%d次反弹的高度是%d", n, ret, n, H);
//	return 0;
//}