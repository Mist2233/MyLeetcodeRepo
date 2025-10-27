#include<queue>
#include<stdexcept>
#include<vector>
#include<numeric>

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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;

        checkPathSum(root, targetSum, 0, flag);

        return flag;
    }

    void checkPathSum(TreeNode* node, int targetSum, int currentSum, bool& flag) {
        if (node == nullptr) {
            return;
        }

        currentSum += node->val;
        if (node->left == nullptr && node->right == nullptr && currentSum == targetSum) {
            flag = true;
            return;
        }

        checkPathSum(node->left, targetSum, currentSum, flag);
        checkPathSum(node->right, targetSum, currentSum, flag);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        vector<int> path;
        checkPathSum(root, targetSum, path, flag);

        return flag;
    }

    void checkPathSum(TreeNode* node, int targetSum, vector<int>& currentPath, bool& flag) {
        if (node == nullptr) {
            return;
        }

        currentPath.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            int currentSum = accumulate(currentPath.begin(), currentPath.end(), 0);
            if (currentSum == targetSum) {
                flag = true;
                return;
            }
        }

        checkPathSum(node->left, targetSum, currentPath, flag);
        checkPathSum(node->right, targetSum, currentPath, flag);

        currentPath.pop_back();
    }
};


/*
最简洁的解法：利用化归的思想，将问题拆分到子问题。
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        
        // 直接更新targetSum的值，用于子问题计算。这种思路比我用currentSum来一个个记录，要更好。
        targetSum -= root->val;

        if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
            return true;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};