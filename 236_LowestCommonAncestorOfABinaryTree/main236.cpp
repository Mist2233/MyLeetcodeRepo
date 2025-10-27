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
找最近的公共祖先，那么需要怎么办？

溯源。首先，找到它们各自的层级；然后，让层级低的向上走，看看什么时候能找到公共祖先。

问题在，怎么溯源？这里并没有所谓parent这样的属性。

需要找父节点之间的关系，但是不让我直接从子节点回去，我们需要另想办法。

我的想法：
- 从根节点出发，搜索到p和q，并记录路径。最后，比较这两个路径之间的公共部分的最后一个值。

用什么记录？用栈记录吧。
*/

/*
关键思想：一个节点node（非p和q自身）是p和q的公共子节点，等价于p和q各自在node的左右子树。

那么，如果p和q都在node的同一支，我们就需要继续向下找。

写了一个最朴素的方法，里面存在大量的重复运算，比如每一次向下find操作时。

我需要优化这个方法。
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p && find(root, q) || root == q && find(root, p) || find(root->left, p) && find(root->right, q) || find(root->left, q) && find(root->right, p)) return root;

        if (find(root->left, p)) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return lowestCommonAncestor(root->right, p, q);
    }

    bool find(TreeNode* node, TreeNode* target) {
        if (node == nullptr || target == nullptr) return false;

        if (node == target) return true;

        return find(node->left, target) || find(node->right, target);
    }
};

/*
上面那个解法的问题在于，find只返回了一个bool值，表示是否找到；我需要设计新的find函数，使得一旦找到就能直接返回需要的LCA。

怎么设计：
“请在以 current_node 为根的子树中寻找 p 或 q。
- 如果什么都没找到，请返回 nullptr。
- 如果只找到了 p 或者 q 中的一个，请返回你找到的那个节点 (p 或 q)。
- 如果你同时找到了 p 和 q（即，它们一个在你左子树，一个在你右子树），那么你自己就是 LCA，请返回你自己 (current_node)。”
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_result = lowestCommonAncestor(root->right, p, q);

        if (left_result != nullptr && right_result != nullptr) {
            return root;
        }
        
        if (left_result == nullptr && right_result != nullptr) {
            return right_result;
        }

        if (left_result != nullptr && right_result == nullptr) {
            return left_result;
        }

        return nullptr;
    }
};
