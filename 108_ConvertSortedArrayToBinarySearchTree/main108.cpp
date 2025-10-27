#include<bits/stdc++.h>

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


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        // 这里，base case的处理可以更加精炼一些，不过我这样写问题也不大。
        // 更简洁的写法是只写一个 if (low > high) return nullptr; 因为 其他的情况都被后续我的递归处理覆盖了。
        if (low > high || low < 0 || high >= nums.size()) return nullptr;
        if (low == high) return new TreeNode(nums[low]);

        int mid = low + (high - low) / 2;
        TreeNode* curr_root = new TreeNode(nums[mid]);

        curr_root->left = sortedArrayToBST(nums, low, mid - 1);
        curr_root->right = sortedArrayToBST(nums, mid + 1, high);

        return curr_root;
    }
};