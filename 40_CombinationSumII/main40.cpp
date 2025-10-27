#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(),
             [](int a, int b) { return a < b; });

        backtrack(candidates, target, 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int start_idx) {
        if (target == 0) {
            result.push_back(ans);
            return;
        }

        for (int i = start_idx; i < candidates.size(); i++) {
            // 看看下面注释里的代码，和没有注释的代码的区别。
            // 注释里的代码，表示整个数组中，重复的数字都会被跳过；
            // 没被注释的代码，表示只跳过同一层中重复的数字。
            // 仔细体会其中的区别！
            // if (i != 0 && candidates[i] == candidates[i - 1]) continue;
            if (i > start_idx && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;
            ans.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1);
            ans.pop_back();
        }
    } 
private:
    vector<int> ans;
    vector<vector<int>> result;
};