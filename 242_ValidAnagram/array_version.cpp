#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int count_chars[26] = {0}; // 别忘记初始化数组

        for (char c: s) {
            count_chars[c - 'a']++;
        }

        for (char c: t) {
            count_chars[c - 'a']--;
            if (count_chars[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};