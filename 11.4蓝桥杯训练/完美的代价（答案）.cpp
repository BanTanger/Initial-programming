#define _CRT_SECURE_NO_WARNINGS 1
//#include<bits/stdc++.h>//万能头要第三方库
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n; string s;
	cin >> n;
	cin >> s;
    int j = n - 1;
    int res = 0; //res用来统计交换的次数
    int flag = 0; //flag用来统计出现奇数次数的字符个数

    for (int i = 0; i < j; i++) //i指针从头遍历到倒数第二个字符
    {
        for (int k = j; k >= i; k--) //k指针从后面往前一直到i寻找和s[i]相同的s[k]
        {
            if (k == i) //如果找不到相同的
            {
                flag++;
                if (n % 2 == 0 || flag == 2) //impossible的两种情况
                {
                    cout << "Impossible" << endl;
                    return 0;
                }
                res += n / 2 - i; //n为奇数时唯一一个奇数次出现的字符移到中间的次数
         //n/2-i一定大于0即这个数是在整体的左边位置，如果在右边遍历前面的i时就已经把它移到中间了，如aaaad  
            }
            else if (s[i] == s[k])
            {
                for (int l = k; l < j; l++)
                //k也是指针走过的距离，只要记录k的值就可以做到循环来使指针移动
                {
                    swap(s[l], s[l + 1]);//把s[k]换到s[j]处  
                    res++;//统计交换次数
                }
                j--; //将一个字符调到末尾后j减一即将末尾指针往前移一位
      //方便下次交换到末尾且i和j相等时此时已经是回文数第一个for循环就结束了
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}

