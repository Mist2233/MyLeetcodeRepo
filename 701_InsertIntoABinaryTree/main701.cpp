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
将一个新的值插入BST，只要是插入后为BST，返回一种结果即可。

再次回顾BST的定义：比左子树中的所有节点都大，比右子树中所有节点都小。

我们就采用最简单、最省事的方式：直接插在叶子节点的下面。
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* new_node = new TreeNode(val);

        // 不要忘记考虑特殊情况！
        if (root == nullptr) {
            return new_node;
        }

        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->val > val) {
                if (curr->left == nullptr) {
                    curr->left = new_node;
                    break;
                }
                else {
                    curr = curr->left;
                }
            }

            if (curr->val < val) {
                if (curr->right == nullptr) {
                    curr->right = new_node;
                    break;
                }
                else {
                    curr = curr->right;
                }
            }
        }
        
        return root;
    }
};

/*
递归版本
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        if (root->val > val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
            }
            else {
                insertIntoBST(root->left, val);
            }
        }

        if (root->val < val) {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
            }
            else {
                insertIntoBST(root->right, val);
            }
        }


        return root;
    }
};

// 更纯粹的递归解法：
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base Case: 找到了插入点（一个空指针），
        // 创建新节点并将其作为新的子树根节点返回。
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Recursive Step: 根据大小关系，决定去哪边递归
        if (val < root->val) {
            // 去左子树插入，并用返回的结果更新我的左孩子指针
            root->left = insertIntoBST(root->left, val);
        } 
        else { // val > root->val
            // 去右子树插入，并用返回的结果更新我的右孩子指针
            root->right = insertIntoBST(root->right, val);
        }

        // 返回当前节点（它本身没有改变，但它的子树可能已经被更新了）
        return root;
    }
};