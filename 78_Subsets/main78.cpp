#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    给一个数列，返回它的所有子集。
    其实是个很简单的题目，不要想复杂了。
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(const vector<int>& nums, int start_idx) {
        // 因为需要记录所有的子集，所以这里每一次都需要push_back。
        result.push_back(ans);

        for (int i = start_idx; i < nums.size(); i++) {
            ans.push_back(nums[i]);
            backtrack(nums, i + 1);
            ans.pop_back();
        }
    }
private:
    vector<int> ans;
    vector<vector<int>> result;
};