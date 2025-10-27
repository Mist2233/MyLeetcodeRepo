

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
 数完全二叉树的节点个数，需要怎么做？
 我能想到的方法就是层序遍历所有节点。
 但事实上，我们只需要数出最后一层的节点数，再用高度计算前面的节点数，就可以了。
 也就是说，我该怎么数出“相比于满二叉树，完全二叉树缺少的节点个数”呢？
 算了，我先写一个层序遍历的代码吧。

 诶，感觉可以直接用递归写一个代码，我看看先。
 但是，递归代码的问题在于，它完全没有用上“完全二叉树”这个条件，而是对所有的二叉树都满足。
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

#include<queue>

// 和前面的问题一样：完全没有用到满二叉树的条件。
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> nodes;
        int count = 0;

        nodes.push(root); count ++;

        while(!nodes.empty()) {
            TreeNode* curr_node = nodes.front();
            nodes.pop();

            if (curr_node->left != nullptr) {
                nodes.push(curr_node->left);
                count++;
            }

            if (curr_node->right != nullptr) {
                nodes.push(curr_node->right);
                count++;
            }
        }
        return count;
    }
};

// 利用完全二叉树性质的解法
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = 1, right_depth = 1;

        TreeNode* curr_node = root;

        while (curr_node->left != nullptr) {
            left_depth++;
            curr_node = curr_node->left;
        }

        curr_node = root;
        while (curr_node->right != nullptr) {
            right_depth++;
            curr_node = curr_node->right;
        }


        if (left_depth == right_depth) {
            // return pow(2, left_depth) - 1;     
            return (1 << left_depth) - 1;   // 用二进制移位运算来代替直接的pow更好，因为不涉及浮点数运算。
        }
        else { 
            // 注意：在left_depth > right_depth的情况下，root的左子树和右子树，必然有一个为满二叉树。
            // 可以这样理解：最后一层的节点从左向右一个个填充，要么把左子树先全部填满，变成满二叉树；要么右子树一个都没沾到，右边保持满二叉树不变。
            return 1 + countNodes(root->left) + countNodes(root->right);
        }

        return 0;
    }
};