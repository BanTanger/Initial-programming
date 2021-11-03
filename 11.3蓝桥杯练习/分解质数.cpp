#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		printf("%d=", i);
		/*if (i % 400 == 0 || (i % 100 != 0) && (i % 4 == 0))
			printf("%d = %d", i, i);
		else
		{
			for (int j = 2; j < b; j++)
			{
				if(i%j==0)
			}
		}*/
		int m = i, n = 2;
		while (n <= sqrt(i))
		{
			if (m % n == 0) {
				
			}
		}
	}
}