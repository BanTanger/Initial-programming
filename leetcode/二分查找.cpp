//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int right = nums.size() - 1;
//        int left = 0;
//        while (left <= right) {
//            int middle = left + (right - left) / 2;
//            if (nums[middle] > target) {
//                right = middle - 1;
//            }
//            else if (nums[middle] < target) {
//                left = middle + 1;
//            }
//            else {
//                return middle;
//            }
//        }
//        return -1;
//    }
//};
//int main() {
//    int a[] = { 0,2,4,7,8,6,1,-2,-5,9 };
//    sort(a,a + sizeof(a) / sizeof(int));
//    vector<int> nums(a,a+sizeof(a)/sizeof(int));
//    int target = 6;
//    Solution solution;
//    cout << solution.search(nums, target) << endl;
//}