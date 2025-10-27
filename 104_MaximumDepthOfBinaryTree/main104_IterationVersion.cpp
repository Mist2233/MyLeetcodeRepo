#include<algorithm>
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

/*
 * 层序遍历求解二叉树的高度。
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> nodes;
        int depth = 0;
        nodes.push(root);

        while (!nodes.empty()) {
            int level_size = nodes.size();
            for (size_t _ = 0; _ < level_size; _++) {
                TreeNode* curr_node = nodes.front();
                nodes.pop();
                if (curr_node->left != nullptr) {
                    nodes.push(curr_node->left);
                }
                if (curr_node->right != nullptr) {
                    nodes.push(curr_node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};