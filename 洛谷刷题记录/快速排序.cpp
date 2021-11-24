#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define MAX 20000

int n, a, b[MAX];
int main() {
	cin >> n ;
	for (int i = 0; i < n; i++) 
		cin >> a, ++b[a];
	for (int i = 0; i < MAX; i++) {
		while (b[i]--)
			cout << i << " ";
	}
}