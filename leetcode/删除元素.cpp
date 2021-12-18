//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //快慢指针
//        int slowIndex = 0;
//        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
//            if (nums[fastIndex] != val) {
//                nums[slowIndex++] = nums[fastIndex];
//                //快指针覆盖慢指针，在锁定到val的时候！
//            }
//        }
//        return slowIndex;
//    }
//};
//int main() {
//    Solution solution;
//    int a[] = { 1,2,2,4,5,3,7,8,1,0,5,7,2,4,2 };
//    vector<int> nums (a, a + sizeof(a) / sizeof(int));
//    cout << "原本长度" << sizeof(a) / sizeof(int) << endl;
//    cout << "之后长度" << solution.removeElement(nums, 2) << endl;
//}