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

        for (char c: magazine) {
            letters_count[c - 'a'] ++;
        }

        for (char c: ransomNote) {
            letters_count[c - 'a'] --;

            if (letters_count[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};