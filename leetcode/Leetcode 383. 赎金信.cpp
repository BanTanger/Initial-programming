#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = { 0 };
        for (int i = 0; i < magazine.size(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            record[ransomNote[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] < 0) {
                return false;
            }
        }
        return true;

    }
};