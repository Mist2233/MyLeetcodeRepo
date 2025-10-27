#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 4, 0);
        return result;
    }

    void backtrack(const string& s, int part_num, int start_idx) {
        if (s.length() - start_idx < part_num || s.length() - start_idx > 3 * part_num) {
            return;
        }

        if (part_num == 0) {
            ans.pop_back();
            result.push_back(ans);
            ans.push_back('.');   
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (start_idx + len - 1 < s.length()) {
                string sub_str = s.substr(start_idx, len);
                int ip_part_num = stoi(sub_str);
                if (ip_part_num > 255) {
                    break;
                }
                if ()
                ans.append(s.substr(start_idx, len));
                ans.append(".");
                backtrack(s, part_num - 1, start_idx + len);
                ans.erase(start_idx, len + 1);
            }
        }
    }

private:
    string ans;
    vector<string> result;
};