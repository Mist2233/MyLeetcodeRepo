#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    void backtrack (const vector<int>& nums, int start_idx) {
        result.push_back(ans);

        for (int i = start_idx; i < nums.size(); i++) {
            // 新增一个跳过机制
            if (i > start_idx && nums[i] == nums[i - 1]) {
                continue;
            }
            ans.push_back(nums[i]);
            backtrack(nums, i + 1);
            ans.pop_back();
        }
    }

private:
    vector<int> ans;
    vector<vector<int>> result;
};