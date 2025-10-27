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
检查一棵树是否为BST，需要检查子树中的每一个节点。

而这种检查显然是有重复的，我们可以自底向上检查。

每次检查时，保存左子树的最大值和右子树的最小值，拿这两个值和root的值比较。
这两个值能通过比较，就说明root及其以下的部分问题。

怎么确定一个节点是作为右子树存在，还是作为左子树存在？我想，这个就是题解的关键了。

以及怎么自底向上进行检查的过程？我记得之前有一个题目也涉及到自底向上，但我记不起来了……

算了，找不到就不用找了，自己再想一个。
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long max_val = LONG_LONG_MIN, min_val = LONG_LONG_MAX;
        return isValidBST(root, max_val, min_val);
    }

    /*
    因为我不知道当前节点node是其父节点的左孩子还是右孩子，所以我希望保存以node为根的子树中所有节点的最大值和最小值。

    而这里max_val和min_val可以看作是上面传下来的，需要我们在这里更新。这样逐步统计与验证。

    我得增加我的变量个数。

    下面这个函数，一方面需要check子树是否为BST，另一方面要将下面的信息向上传，即更新max_val和min_val
    */
    bool isValidBST(TreeNode* node, long long& max_val, long long& min_val) {
        // base case，空节点，只返回true，不对max_val和min_val做任何修改。
        if (node == nullptr) {
            return true;
        }

        // base case 2，如果当前节点node是叶子节点，那么就看比较node和上面传下来的max_val和min_val，看看是否需要更新。
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val > max_val) {
                max_val = node->val;
            }

            if (node->val < min_val) {
                min_val = node->val;
            }
            return true;
        }
        long long left_max_val = LONG_LONG_MIN, left_min_val = node->val, right_max_val = node->val, right_min_val = LONG_LONG_MAX;

        bool left_check = isValidBST(node->left, left_max_val, left_min_val);
        if (!left_check || left_max_val >= node->val) return false;

        bool right_check = isValidBST(node->right, right_max_val, right_min_val);
        if (!right_check || right_min_val <= node->val) return false;

        if (left_min_val < min_val) min_val = left_min_val;
        if (right_max_val > max_val) max_val = right_max_val;
        return true;
    }
};

/* ------------------------------------------------------------- */
/*
Gemini提示后的解法：非常简洁。

每次都去传递区间，区间代表对节点的限制。每次碰到一个节点，就更新区间的值，这样越往下限制就越严格。这种做法是自顶向下的，BST实际上就是父节点对子节点的约束。这样自顶向下做，就会很简洁。
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 初始区间给一个无穷大的区间。
        return isValid(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }

    // 辅助函数：检查节点node的值是否我们给定的区间中区间中。
    bool isValid(TreeNode* node, long long lower_bound, long long upper_bound) {
        if (node == nullptr) return true;

        // 判断当前节点是否在区间中。如果不在，直接结束递归，返回false
        if (node->val <= lower_bound || node->val >= upper_bound) return false;

        // 用当前节点的值来更新对其子节点的约束区间。
        return isValid(node->left, lower_bound, node->val) && isValid(node->right, node->val, upper_bound);

    }
};

/* ------------------------------------------------------------- */
/*
另一种解法：中序遍历法。

BST的中序遍历left-root-right，一定是一个严格递增序列。我们只需要写出中序遍历方法，并判断它是不是严格递增即可。

比较不需要记录全部值，而是只记录前一个值即可。比较前一个值和当前值，看看是否符合递增序列。
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return inorder_check(root);
    }

    // 本质上是中序遍历，但加入了check BST的部分
    bool inorder_check(TreeNode* node) {
        if (node == nullptr) return true;

        if (!inorder_check(node->left)) return false;

        if (pre_val >= node->val) {
            return false;
        }
        else {
            pre_val = node->val;
        }

        return inorder_check(node->right);
    }
private:
    long long pre_val = LONG_LONG_MIN;
};

/*
递归解法非常简单，因为它需要我们信任“递归函数的契约”，而不是“模拟每一步的执行过程”。

某个节点node的递归函数返回true时，
    - 如果node作为left child存在，那么其parent会继续check自身和right child。
    - 如果node作为right child存在，那么必然是parent和left child都没问题，才能检查到right child，因此check完就可以return 了。

然后，整个过程就会继续下去，直到最后一个节点（最右的node）被check完。
*/