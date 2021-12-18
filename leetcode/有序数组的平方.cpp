#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int headIndex = 0; int tailIndex = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        int tail = tailIndex;
        while (headIndex <= tailIndex) {
            if (nums[headIndex] * nums[headIndex]
            > nums[tailIndex] * nums[tailIndex]) {
                result[tail--] = nums[headIndex] * nums[headIndex];
                headIndex++;
            }
            else {
                result[tail--] = nums[tailIndex] * nums[tailIndex];
                tailIndex--;
            }
        }
        return result;
    }
};
int main() {
    int a[] = { -4,-1,0,3,10 };
    vector<int>nums(a, a + sizeof(a) / sizeof(int));
    Solution solution;
    for (int i = 0; i < nums.size(); i++) {
        cout << solution.sortedSquares(nums)[i] << " ";    
    }
    cout << endl;
}