#include <bits/stdc++.h>

using namespace std;

class Solution {
/*
将一个只包含数字的字符串 s ，复原成所有可能的有效 IP 地址，并返回这些 IP 地址。
*/
public:
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 4, 0);
        return result;
    }

    void backtrack(const string& s, int part_num, int start_idx) {
        // end case
        if (s.length() - start_idx < part_num || s.length() - start_idx > 3 * part_num) {
            return;
        }

        if (part_num == 0 && start_idx == s.length()) {
            ans.pop_back();
            result.push_back(ans);
            ans.push_back('.');   
            return;
        }
        for (int len = 1; len <= 3; len++) {
            if (start_idx + len - 1 < s.length()) {
                string sub_str = s.substr(start_idx, len);
                // if the part's length is larger than 1, then it should not start with zero.
                if (len > 1 && sub_str[0] == '0') {
                    break;
                }
                // the part number should not be larger than 255
                int ip_part_num = stoi(sub_str);
                if (ip_part_num > 255) {
                    break;
                }
                
                // choose and backtrack
                ans.append(s.substr(start_idx, len));
                ans.append(".");
                backtrack(s, part_num - 1, start_idx + len);
                ans.pop_back();     // remove the '.'
                // remove the previous numbers
                for (int i = 0; i < len; i++) {
                    ans.pop_back();
                }
            }
        }
    }

private:
    string ans;
    vector<string> result;
};