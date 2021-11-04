//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<math.h>
//using namespace std;
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	for (int i = a; i <= b; i++){
//		printf("%ld=", i);
//		int m = i, n = 2;
//		while (n <= sqrt(i)){
//			if (m % n == 0) {
//				m /= n;
//				if (m > 1) {
//					printf("%ld*", n);
//					//continue;
//				}
//				if (m == 1)printf("%ld\n", n);
//				//如果m被除尽，就打印最后一次的n终结。
//			}
//			n++;
//		}
//		if (m > 1 && m <= i)printf("%ld\n", m);//被除数打印与素数打印。很精简。
//		if (m == 1)printf("%d\n", i);//1的特殊情况处理
//	}
//}