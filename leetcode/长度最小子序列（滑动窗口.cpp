//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int result = INT_MAX;//防止subLength超过int的最大范围10的九次方。
//        int sum = 0;
//        int i = 0; int j = 0;
//        int subLength = 0;
//        for (j = 0; j < nums.size(); j++) {
//            sum += nums[j];
//            while (sum >= target) {
//                subLength = j - i + 1;
//                result = result < subLength ? result : subLength;
//                //通过三目表达式来更新result，如果subLength超过最大整型长度，就让result保持INT_MAX;
//                sum -= nums[i++];//通过while循环去更新i和subLength
//            }
//        }
//        return result == INT_MAX ? 0 : result;
//        //返回判断，result == INTMAX代表没有更新。说明没有找到这个值，返回零
//    }
//};
