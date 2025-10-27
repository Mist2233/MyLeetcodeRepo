#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int min_counts[26] = {0};

        vector<string> common_chars;
        for (char c: words[0]) {
            min_counts[c - 'a']++;
        }

        for (size_t i = 1; i < words.size(); i++) {
            int temp_counts[26] = {0};
            for (char c: words[i]) {
                temp_counts[c - 'a']++;
            }

            for (size_t j = 0; j < 26; j++) {
                min_counts[j] = min(min_counts[j], temp_counts[j]);
            }

        }

        for (size_t i = 0; i < 26; i++) {
            for (size_t _ = 0; _ < min_counts[i]; _++) {
                common_chars.push_back(string(1, i + 'a'));
            }
        }
        return common_chars;
    }
};