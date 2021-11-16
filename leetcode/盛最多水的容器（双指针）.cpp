#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int ans = 0;
		while (left < right) {
			int area = min(height[left], height[right]) * (right - left);
			ans = max(ans, area);
			if (height[right] >= height[left])
				++left;
			else
				--right;
		}
		//return ans;
		cout << ans << endl;
	}

};
