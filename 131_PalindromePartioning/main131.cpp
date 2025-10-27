#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }

    void backtrack(const string& s, int start_idx) {
        if (start_idx == s.length()) {
            result.push_back(ans);
            return;
        }

        for (int i = start_idx; i < s.length(); i++) {
            string substring = s.substr(start_idx, i - start_idx + 1);  // 用string类的substr方法，获取字符串的子串，第一个参数是起始所部，第二个是子串的长度。注意这里需要从start_idx开始获取子串，我一开始不小心从i开始获取，结果子串的起点就跟着一起变，忽略了一些情况……
            if (checkPalindrome(substring)) {  // 检查子串是否为回文串
                ans.push_back(substring);
                backtrack(s, i + 1);
                ans.pop_back();
            }
        }
    }

    bool checkPalindrome(const string& s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
        }

        return true;
    }

   private:
    vector<string> ans;
    vector<vector<string>> result;
};

// 优化版本：使用动态规划预处理回文状态
class SolutionOptimized {
   public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        // 预处理：dp[i][j] 表示 s[i...j] 是否为回文（这个dp的定义很重要！）
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 填充dp表
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;  // 先从对角线开始，即单个字符是回文的情况。
        }

        // 开始填充其他位置，这里是怎么做的？
        // 从substring的长度开始遍历。
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = (len == 2) || dp[i + 1][j - 1]; // 这就是dp的精髓啊，状态转移方程。
                }
            }
        }

        result.clear();
        ans.clear();
        backtrack(s, 0, dp);
        return result;
    }

    void backtrack(const string& s, int start_idx,
                   const vector<vector<bool>>& dp) {
        if (start_idx == s.length()) {
            result.push_back(ans);
            return;
        }

        for (int i = start_idx; i < s.length(); i++) {
            // 使用预处理的dp表，O(1)时间判断回文
            if (dp[start_idx][i]) {
                string substring = s.substr(start_idx, i - start_idx + 1);
                ans.push_back(substring);
                backtrack(s, i + 1, dp);
                ans.pop_back();
            }
        }
    }

   private:
    vector<string> ans;
    vector<vector<string>> result;
};

// 进一步优化版本：双指针回文检查
class SolutionV2 {
   public:
    vector<vector<string>> partition(string s) {
        result.clear();
        ans.clear();
        backtrack(s, 0);
        return result;
    }

    void backtrack(const string& s, int start_idx) {
        if (start_idx == s.length()) {
            result.push_back(ans);
            return;
        }

        for (int i = start_idx; i < s.length(); i++) {
            // 直接使用索引检查回文，避免创建子串
            if (isPalindrome(s, start_idx, i)) {
                string substring = s.substr(start_idx, i - start_idx + 1);
                ans.push_back(substring);
                backtrack(s, i + 1);
                ans.pop_back();
            }
        }
    }

    // 双指针回文检查，更高效
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

   private:
    vector<string> ans;
    vector<vector<string>> result;
};