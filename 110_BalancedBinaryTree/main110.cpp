#include<iostream>

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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
 判断一棵树是否平衡，要看每个节点的左子树和右子树的高度之差。
 最直白的方法：写一个函数，检测每个节点的高度，然后比较。
 但这样会产生大量冗余计算。
 我们可以同时计算节点的高度并比较其两边的高度大小。

 现在有一个想法：把所有的高度存下来，这样就不用重复计算了。
 但问题是这个高度怎么对应到节点？
 可以写一个前序遍历的算法，让每次出来的节点和高度一一对应，即可。
 复习一下前序遍历的算法：只记得需要用到栈，其他不懂了……
 */


 // 解题的关键在于，用一个返回结果表示两种情况。
 // 定义getHeightAndCheck函数。如果返回值为-1，说明子树不平衡；如果返回值为非负数，说明子树平衡，并且该非负数表示子树的高度。

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int result = getHeightAndCheck(root);

        if (result == -1) {
            return false;
        }

        return true;
    }
    
    // 学习这种思想：用一个返回值表示两种结果，用正负作为区分。
    int getHeightAndCheck(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_result = getHeightAndCheck(root->left), right_result = getHeightAndCheck(root->right);

        if (left_result == -1 || right_result == -1 || abs(left_result - right_result) > 1) {
            return -1;
        }

        return 1 + max(left_result, right_result);
    }
};