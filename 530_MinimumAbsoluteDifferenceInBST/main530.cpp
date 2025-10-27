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

/* ------------------------------------------------------------- */

/*
这道题让我们找BST中任意两个节点值的绝对最小差。

看着很容易，因为我们刚刚才学习过：一棵二叉树树为BST 当且仅当 其中序遍历序列严格递增。

那么，最小差一定在中序遍历中相邻的两个节点中产生。而哪一些节点在中序遍历中存在相邻关系呢？
答案是：BST中存在父子关系的节点，在中序遍历中为相邻关系，反之亦然。❌
（注意：上面的说法是不正确的，可能存在某个节点的右节点和父节点更近）
*/
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        get_min_diff(root);
        return min_diff;
    }

    void get_min_diff(TreeNode* node) {
        if (node == nullptr) return;

        if (node->left != nullptr && node->val - node->left->val < min_diff) {
            min_diff = node->val - node->left->val;
        }

        if (node->right != nullptr && node->right->val - node->val < min_diff) {
            min_diff = node->right->val - node->val;
        }

        get_min_diff(node->left);
        get_min_diff(node->right);
    }

private:
    int min_diff = INT32_MAX;
};

/* ------------------------------------------------------------- */
/*
决定直接复用第98题的代码，用中序遍历解决。
*/
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        inorder_find(root);

        return min_diff;
    }

    void inorder_find(TreeNode* node) {
        if (node == nullptr) return;

        inorder_find(node->left);

        if (node->val - pre_val < min_diff) {
            min_diff = node->val - pre_val;
        }
        pre_val = node->val;

        inorder_find(node->right);
    }
private:
    int pre_val = -100001;
    int min_diff = 100001;
};