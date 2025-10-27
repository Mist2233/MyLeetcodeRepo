#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return result;
    }

    void backtrack(int k, int n, int start_num) {
        // 下面这个被注释掉的判断是不必要的，而且是错误的，会让我们的一些情况提前终止。
        // 原因是，我们每一次check的是上一次传入的sum，如果用start_num额外判断，那么就缺少了后面加入result的操作了。
        // if (start_num > 9) {
        //     return;
        // }
        
        if (curr_path.size() == k) {
            if (curr_sum == n) {
                result.push_back(curr_path);
            }
            return;
        }

        for (int i = start_num; i <= 9 - (k - curr_path.size()) + 1; i++) {
            curr_path.push_back(i);
            curr_sum += i;
            backtrack(k, n, i + 1);
            curr_sum -= i;
            curr_path.pop_back();
        }
    }

private:
    vector<int> curr_path;
    int curr_sum = 0;
    vector<vector<int>> result;
};

// 在Gemini指导下，写出的第二版

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return result;
    }

    void backtrack(int k, int target_sum, int start_num) {
        if (target_sum < 0 || curr_path.size() > k) {
            return;
        }
        
        if (curr_path.size() == k) {
            if (target_sum == 0) {
                result.push_back(curr_path);
            }
            return;
        }

        for (int i = start_num; i <= 9 - (k - curr_path.size()) + 1; i++) {
            curr_path.push_back(i);
            backtrack(k, target_sum - i, i + 1);
            curr_path.pop_back();
        }
    }

private:
    vector<int> curr_path;
    vector<vector<int>> result;
};