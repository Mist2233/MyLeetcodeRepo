#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(const vector<int>& nums, int start_idx) {
        if (ans.size() > 1) {
            result.push_back(ans);
        }

        for (int i = start_idx; i < nums.size(); i++) {
            // 跳过重复元素，但是不能跳过第一个碰到的元素
            if (i > start_idx && nums[i] == nums[i - 1]) {
                continue;
            }

            // 如果是ans是空集，那么先push一个元素进去
            if (ans.empty()) {
                ans.push_back(nums[i]);
                backtrack(nums, i + 1);
                ans.pop_back();
            }
            // 如果ans不是空集，那么push元素的条件是“非递减”
            else {
                if (nums[i] >= ans.back()) {
                    ans.push_back(nums[i]);
                    backtrack(nums, i + 1);
                    ans.pop_back();
                }
            }
        }
    }

private:
    vector<int> ans;
    vector<vector<int>> result;
};

class SolutionRevised {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(const vector<int>& nums, int start_idx) {
        if (ans.size() > 1) {
            result.push_back(ans);
        }

        unordered_set<int> used_num; // 本层去重：一旦找到和起点相同的数字，不会再做一次起点。
        for (int i = start_idx; i < nums.size(); i++) {
            if (!ans.empty() && nums[i] < ans.back()) {
                continue;
            }
            if (used_num.count(nums[i])) {
                continue;
            }
            used_num.insert(nums[i]);

            ans.push_back(nums[i]);
            backtrack(nums, i + 1);
            ans.pop_back();
        }
    }
        
private:
    vector<int> ans;
    vector<vector<int>> result;
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 1, 1};
    vector<vector<int>> result = sol.findSubsequences(nums);
    for (const auto& seq : result) {
        cout << "[";
        for (size_t i = 0; i < seq.size(); ++i) {
            if (i) cout << ", ";
            cout << seq[i];
        }
        cout << "]\n";
    }
    return 0;
}