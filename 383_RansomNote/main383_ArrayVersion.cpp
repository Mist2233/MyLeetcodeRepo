#include<string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        // if you use array, you must initialize it.
        int letters_count[26] = {0};

        for (char c: ransomNote) {
            letters_count[c - 'a'] ++;
        }

        for (char c: magazine) {
            letters_count[c - 'a'] --;
        }

        for (size_t i = 0; i < 26; i++) {
            if (letters_count[i] > 0) {
                return false;
            }
        }
        return true;
    }
};