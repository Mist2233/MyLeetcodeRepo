#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    // 基础结构和第46题完全相同，需要增加的就是跳过的重复数字的部分。
    void backtrack(vector<int>& nums, int start_idx) {
        if (start_idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> used;  // 记录当前层已经处理过的数
        for (int i = start_idx; i < nums.size(); ++i) {
            if (used.count(nums[i])) continue;  // 如果这个数字之前已经处理过，那么跳过。
            used.insert(nums[i]);

            swap(nums[start_idx], nums[i]);
            backtrack(nums, start_idx + 1);
            swap(nums[start_idx], nums[i]);
        }
    }

private:
    vector<vector<int>> result;
};