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
根据给定的区间修剪BST，要求各个节点之间的关系不能变化，怎么做？

如果某个节点的值比low更小，那么它的左子树的所有节点都要被剪掉，然后向它的右边搜索。
同样地，如果某个节点的值比high更大，那么它的右子树的所有节点都要剪掉，然后向它的左边搜索。
如果某个节点的值在[low, high]之中，那么它的左右子树都需要递归处理。

这其实是一个“剪枝+递归”的过程。

我能否用前两天学到的“通过返回值来修改树的结构”来完成这道题？尝试一下。

契约：trimBST这个函数，将在以root为根节点的子树中，根据区间[low, high]修剪子树，并返回修剪后子树的根节点。
*/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val < low) {
            return trimBST(root->right, low, high);
        }

        if (root->val > high) {
            return trimBST(root->left, low, high);
        }

        // 第三种情况：root的值在low和high之间，那么这时候不用舍弃root，而是需要更新root的左右子树。
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

/*
尝试用迭代法解决。
*/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 如果根节点的值不符合要求，那么我们先找到一个符合要求的根节点。
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) {
                root = root->right;
            }
            else if (root->val > high) {
                root = root->left;
            }
        }

        // 没找到合适的根节点，整棵树都被剪完了。
        if (root == nullptr) {
            return nullptr;
        }

        // 下面处理root->val已经在[low, high]中的情况。
        // 分别处理左子树和右子树，我们先处理左子树
        TreeNode* curr = root;
        while (curr != nullptr && curr->left != nullptr) {
            if (curr->left->val < low) {
                curr->left = curr->left->right; // 如果左节点不合格，那么左节点的位置需要由原本左节点的右节点来接替。这里容易犯的错误是直接把左子树整个删掉。
            }
            else {
                curr = curr->left;
            }
        }
        curr = root;
        while (curr != nullptr && curr->right != nullptr) {
            if (curr->right->val > high) {
                curr->right = curr->right->left;
            }
            else {
                curr = curr->right;
            }
        }
        return root;


    }
};