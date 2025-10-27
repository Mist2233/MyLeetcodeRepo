#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        unordered_map<char, int> letters_count;
        for (char c: ransomNote) {
            letters_count[c] ++;
        }

        for (char c: magazine) {
            letters_count[c] --;
        }

        for (auto it = letters_count.begin(); it != letters_count.end(); it++) {
            if (it->second > 0) {
                return false;
            }
        }
        return true;
    }
};