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
我的第一版解法。
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val) return root;

        if (root->val < val) {
            if (root->right == nullptr) {
                return nullptr;
            }
            else {
                return searchBST(root->right, val);
            }
        }

        if (root->val > val) {
            if (root->left == nullptr) {
                return nullptr;
            }
            else {
                return searchBST(root->left, val);
            }
        }

        return nullptr;
    }
};

/*
上面的解法完全没问题，但我们可以再简化一下逻辑。
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // 新增root是否为空的判断。
        if (root == nullptr || root->val == val) return root;

        // 这时候，不用单独考虑root->right是否为空，因为在base case中已经处理了。
        if (root->val < val) {
            return searchBST(root->right, val);
        }

        // 左子树的情况同理
        if (root->val > val) {
            return searchBST(root->left, val);
        }
    }
};

/*
问题的迭代解法
比递归解法更安全，因为不用使用函数调用栈，不用担心栈溢出，其空间复杂度为O(1)
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->val > val) {
                curr = curr->left;
            }
            else if (curr->val < val) {
                curr = curr->right;
            }
            else {
                break;
            }
        }

        return curr;
    }
};