#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current_path;
        vector<vector<int>> result;
        backtrack(n, k, 1, current_path, result);
        return result;
    }

    void backtrack(const int& n, const int& k, int start_num, vector<int>& current_path, vector<vector<int>>& result) {
        // 递归终止条件：当前路径的长度符合我们的需求时，即可停止。
        if (current_path.size() == k) {
            result.push_back(current_path);
            return;
        }

        // 用一个for循环来遍历所有的可能性
        // 这里有一个小小的剪枝优化
        for (int i = start_num; i <= n - (k - current_path.size()) + 1; i++) {
            // 回溯三部曲：选择-探索-撤销
            current_path.push_back(i);
            backtrack(n, k, i + 1, current_path, result);
            // 为什么这里只需要pop最后一位即可？难道我们不是放了很多东西到current_path中吗？
            // 答案是：每一次递归调用的for循环结束之后，都有一个pop_back的操作，因此回到本层循环时，只需要pop一个即可。
            current_path.pop_back();
        }
        // 上面是一个经典的回溯算法结构，需要好好记住！
    }
};