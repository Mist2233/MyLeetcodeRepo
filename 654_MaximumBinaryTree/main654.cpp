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
1. 找到最大值。
2. 递归拆解，得到可解决的子问题。

和上一道题目“构造二叉树”类似，这里的数组也是以引用的方式传递。
我可以用一个unordered_map来保存value -> index的映射，因为题目中明确说明“no duplicates”。

问题是，怎么快速找到最大值呢？如果让我来写，我就只会写for循环，一个一个找。我猜，应该有现成的函数。


*/
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        // 使用std::max_element，可以快速找到某个范围内的最大值。
        // 为了使用它，需先将序列号转为对应的iterator。
        auto start_it = nums.begin() + start;
        auto end_it = nums.begin() + end;
        auto max_it_in_range = max_element(start_it, end_it + 1); //注意区间是左闭右开，所以要+1.

        int max_val = *max_it_in_range;
        int max_idx = distance(nums.begin(), max_it_in_range); // 用distance来高效获取索引值。

        TreeNode* root = new TreeNode(max_val);

        TreeNode* left_node = constructMaximumBinaryTree(nums, start, max_idx - 1);
        TreeNode* right_node = constructMaximumBinaryTree(nums, max_idx + 1, end);
        
        root->left = left_node;
        root->right = right_node;

        return root;
    }
};