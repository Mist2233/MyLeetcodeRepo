#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> count_chars;

        for (char c: s) {
            count_chars[c]++; // map创建时默认的值就是0，所以直接修改即可。
        }

        for (char c: t) {
            count_chars[c]--;

            if (count_chars[c] < 0) {
                return false;
            }
        }

        return true;
    }
};