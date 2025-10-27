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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode* great_right = convertBST(root->right);

        curr_sum += root->val;
        TreeNode* great_root = new TreeNode(curr_sum);

        TreeNode* great_left = convertBST(root->left);

        great_root->left = great_left;
        great_root->right = great_right;

        return great_root;
    }


private:
    int curr_sum = 0;
};

/*
上面的解法从头创造了一棵新的树，而更高效的做法通常是原地修改本来的树，所以让我们写一个新的解法。
*/

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root);

        return root;
    }

    void convert(TreeNode* root) {
        if (root == nullptr) return;

        convert(root->right);

        // 直接修改当前节点的值，而不是创建新节点。这样既省时间，又省空间。
        curr_sum += root->val;
        root->val = curr_sum;

        convert(root->left);
    }


private:
    int curr_sum = 0;
};