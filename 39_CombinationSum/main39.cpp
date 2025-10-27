#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int start_idx) {
        // 递归终止条件：目标和为0，说明我们可以结束递归了。
        if (target == 0) {
            result.push_back(ans);
            return;
        }

        sort(candidates.begin(), candidates.end(), [] (int a, int b) {return a < b;}); // 先排序，后面就可以使用剪枝操作，加速
        for (int i = start_idx; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            }
            ans.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);  // 注意，这里传入递归部分的参数是i，而不是i+1，这是因为题目允许我们使用重复的数字。
            ans.pop_back();
        }

    }

private:
    vector<int> ans;
    vector<vector<int>> result;
};