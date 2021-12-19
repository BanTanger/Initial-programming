//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int totalFruit(vector<int>& tree) {
//        unordered_map<int, int> basket;//无序哈希容器。用来存放不同的值
//        //存储键值对 <key, value> 类型的元素，其中各个键值对键的值不允许重复，且该容器中存储的键值对是无序的。
//        //相对与map来说，map会自动对数据排序，unordered_map不会。
//        int result = 0, len = 0;
//        int left = 0;
//        for (int i = 0; i < tree.size(); i++) {
//            basket[tree[i]]++;//桶思想。
//            len++;
//            while (basket.size() > 2) {//超过两个桶的时候的减桶操作。
//                basket[tree[left]]--;
//                if (basket[tree[left]] == 0) basket.erase(tree[left]);//删桶。
//                left++;//桶向左移动一个。
//                len--;//减少长度。
//            }
//            if (result < len) {
//                result = len;
//            }
//        }
//        return result;
//    }
//};
//int main() {
//    int a[] = { 3,3,3,1,2,1,1,2,3,3,4 };
//    vector<int> tree(a, a + sizeof(a) / sizeof(int));
//    Solution solution;
//    cout << solution.totalFruit(tree) << endl;
//}