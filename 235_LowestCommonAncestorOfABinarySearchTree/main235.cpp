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
今天要找BST的最近公共祖先。

这个题用昨天写的找二叉树的最近公共祖先的代码就可以。可是，显然可以优化。

还是先想想中序遍历，怎么利用BST中序遍历有序的性质。

昨天我们说到，对某个节点curr，如果p在curr的左子树，而q在curr的右子树（或者两边交换一下），那么curr就是p和q的最近公共祖先。

在BST中，怎么体现左子树和右子树的概念？我想到可以用大小来看。

但是，大小只能判断是在“左边”还是“右边”，却无法体现父子关系。

有个办法可以排除父子关系的判断：我们从root开始往下查找，这样一级一级排查，上面被查过的节点就不用考虑了。
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) 
            return root;

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

/*
还可以再简化一些，把base case中的一些内容和最后的内容合并。

但是，这样虽然代码变短了，但是效率也变低了，因为一些简单的情况没有直接判断，而是多了几个if判断
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) 
            return root;

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

/*
迭代解法版：如果递归中存在“不断向左或向右”的逻辑，那么很容易就能修改成迭代的解法，直接利用while循环即可。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
                continue;
            }

            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
                continue;
            }

            return curr;
        }

        return nullptr;
    }
};