//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());//升序排序
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > 0) return result;//返回0 0 0情况
//
//            if (i > 0 && nums[i] == nums[i - 1]) { continue; }//去重处理
//            //为了保证 -1 -1 2 的情况不忽略，所以用nums[i] == nums[i-1];
//            //这样能保证nums中出现多个一样的值至少算一次的情况，
//            //如果是nums[i] == nums[i+1] 连一次都算不了
//
//            //设置双指针。
//            int left = i + 1;
//            int right = nums.size() - 1;
//            while (left < right) {
//                if (nums[left] + nums[right] + nums[i] > 0) {
//                    //三者值大了，移动right指针
//                    right--;
//                }
//                else if (nums[left] + nums[right] + nums[i] < 0) {
//                    //三者值小了，移动left指针
//                    left++;
//                }
//                //找到值
//                else {
//                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
//                    // 去重逻辑应该放在找到一个三元组之后
//                    while (right > left && nums[right] == nums[right - 1]) right--;
//                    while (right > left && nums[left] == nums[left + 1]) left++;
//
//                    // 找到答案时，双指针同时收缩
//                    right--;
//                    left++;
//                }
//            }
//        }
//        return result;
//    }
//
//};
//int main() {
//	
//}

#include<iostream>
using namespace std;

int main() {
	int a[][3] = { 1,2,3,4,5,6,7 };
	static int b[][3] = { 1,2,3,4,5,6,7 };
	cout << a[2][2] << b[2][2];
}