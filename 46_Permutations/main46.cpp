#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(vector<int>& nums, int start_idx) {
        if (start_idx == nums.size() - 1) {
            result.push_back(nums);
        }
        
        for (int i = start_idx; i < nums.size(); i++) {
            swap(nums[i], nums[start_idx]); // 交换
            backtrack(nums, start_idx + 1); // 递归
            swap(nums[i], nums[start_idx]); // 换回来，相当于回溯
        }
    }

private:
    vector<vector<int>> result;
};

