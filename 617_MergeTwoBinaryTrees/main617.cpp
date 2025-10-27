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
合并两棵二叉树，规则为：
1. 如果两棵树对应位置的节点均非nullptr，那么合并后该位置的节点值为两个原始节点的值之和。
2. 如果两棵树对应位置的节点只有一个为nullptr，那么合并后该位置的节点为非nullptr的节点。
3. 如果两棵树对应位置的节点均为nullptr，那么该位置也为nullptr。

返回合并后的二叉树的根节点。
*/

/*
先尝试用递归方法解决。

下面这种简单的递归解法是完全正确的。
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        TreeNode* merged_root = new TreeNode(root1->val + root2->val);
        TreeNode* merged_left = mergeTrees(root1->left, root2->left);
        TreeNode* merged_right = mergeTrees(root1->right, root2->right);

        merged_root->left = merged_left; merged_root->right = merged_right;

        return merged_root;
    }
};

/*
常见的优化方向：
    你能在不创建新树的条件下，原地(in-place)完成这个合并吗？也就是说，将一棵树合并到另一棵树上，以节省内存空间。
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root2 == nullptr) return root1;
        if (root1 == nullptr) return root2;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

/*
利用循环+队列解决，每次处理一对节点。

但是，这种解法是错误的！！！因为我用node1 = node2这个赋值企图修改原本的root1的结构。
可是，node1和node2都只是局部的节点，修改它们无法修改原本root1中node1的父节点的关系，相当于root1中的内容还是断掉了！

来看下面正确的解法。
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root2 == nullptr) return root1;
        if (root1 == nullptr) return root2;

        queue<TreeNode*> nodes;

        nodes.push(root1); nodes.push(root2);

        while (!nodes.empty()) {
            // pop 2 nodes every time
            TreeNode* node1 = nodes.front(); // from root1
            nodes.pop();
            TreeNode* node2 = nodes.front(); // from root2
            nodes.pop();

            if (node1 == nullptr && node2 == nullptr) {
                break;
            }

            if (node1 == nullptr) {
                node1 = node2; // 这一步修改，没有让原始树root1的结果改变！！！
                nodes.push(nullptr); nodes.push(node2->left);
                nodes.push(nullptr); nodes.push(node2->right);
                continue;
            }
            if (node2 == nullptr) {
                nodes.push(node1->left); nodes.push(nullptr);
                nodes.push(node1->right); nodes.push(nullptr);
                continue;
            }

            node1->val += node2->val;
            nodes.push(node1->left); nodes.push(node2->left);
            nodes.push(node1->right); nodes.push(node2->right);
            
        }

        return root1;
    }
};

/*
修改条件，当且仅当两个节点非空时，才入队；否则，单独嫁接处理。
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root2 == nullptr) return root1;
        if (root1 == nullptr) return root2;

        queue<TreeNode*> nodes;

        nodes.push(root1); nodes.push(root2);

        while (!nodes.empty()) {
            // pop 2 nodes every time
            TreeNode* node1 = nodes.front(); // from root1
            nodes.pop();
            TreeNode* node2 = nodes.front(); // from root2
            nodes.pop();

            // 由于我们规定非空节点才能入队，因此这里确定node1和node2都是非空的。
            node1->val += node2->val;
            
            // 先考虑左节点：
            if (node1->left != nullptr && node2->left != nullptr) {
                nodes.push(node1->left);
                nodes.push(node2->left);
            }
            else if (node1->left == nullptr) {
                node1->left = node2->left; // 实现嫁接，后续不再处理，因为这后面的配对相当于一次性完成了。
            } // node2->left == nullptr的情况不用考虑，因为不影响结果。

            // 再考虑右节点，思路相同：
            if (node1->right != nullptr && node2->right != nullptr) {
                nodes.push(node1->right);
                nodes.push(node2->right);
            }
            else if (node1->right == nullptr) {
                node1->right = node2->right;
            }
        }

        return root1;
    }
};




























