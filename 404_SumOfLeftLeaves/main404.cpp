#include<queue>

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum_of_left_leaves = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            TreeNode* curr_node = nodes.front();
            nodes.pop();

            if (curr_node->left != nullptr) {
                if (curr_node->left->left == nullptr && curr_node->left->right == nullptr) {
                    sum_of_left_leaves += curr_node->left->val;
                }
                nodes.push(curr_node->left);
            }

            if (curr_node->right != nullptr) {
                nodes.push(curr_node->right);
            }
        }

        return sum_of_left_leaves;

    }
};