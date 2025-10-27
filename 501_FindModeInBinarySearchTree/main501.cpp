#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
存在重复数字的BST，要找其中的众数。（如果有多个众数，那么全部都要返回）

统计所有数字出现的次数，然后从高到低排列，输出最高的那几个就行。

问题在，怎么统计？如果直接遍历，那么和普通的树就无区别了，怎么体现BST的性质呢？

中序遍历，得到一个递增的序列。按照递增的顺序统计，统计到一个新的数字时，前一个数字的个数一定已经统计完了。

用map来储存，然后找map中最大的value（应该可以用标准库中的某些函数）
*/
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inorderFindMode(root);

        int max_count = 0;
        vector<int> answer;
        for (auto it = numCounts.begin(); it != numCounts.end(); it++) {
            if (it->second > max_count) max_count = it->second;
        }

        for (auto it = numCounts.begin(); it != numCounts.end(); it++) {
            if (it->second == max_count) answer.push_back(it->first);
        }
        return answer;
    }

    void inorderFindMode(TreeNode* node) {
        if (node == nullptr) return;

        inorderFindMode(node->left);

        auto num_it = numCounts.find(node->val);
        if (num_it == numCounts.end()) {
            numCounts[node->val] = 1;
        }
        else {
            numCounts[node->val]++;
        }

        inorderFindMode(node->right);
    }

private:
    unordered_map<int, int> numCounts;
};

/*
利用中序遍历得到的非递减序列。

BST中序遍历的单调性真的很重要，好几道题目都用到了。
*/
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inorderFindMode(root);

        return result;
    }

    void inorderFindMode(TreeNode* node) {
        if (node == nullptr) return;

        inorderFindMode(node->left);

        if (node->val != curr_val) { // 遇到新数字
            curr_val = node->val;
            curr_count = 1;
        }
        else {  // 遇到老数字
            curr_count ++;
        }

        if (curr_count > max_count) {
            max_count = curr_count;
            result = vector<int>(); // 若max_count更新，则之前所得的众数作废，全部清空。
        }

        if (curr_count == max_count) {
            result.push_back(node->val); // 若max_count == curr_count，则将当前数字添加到result中
        }

        inorderFindMode(node->right);
    }

private:
    int curr_val = -100001;
    int curr_count = 0;
    int max_count = 0;
    vector<int> result;
};