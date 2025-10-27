#include<queue>
#include<stdexcept>

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
该怎么检查是不是最后一层呢？我需要确定，
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> nodes;
        TreeNode* target_node = nullptr;
        nodes.push(root);

        while(!nodes.empty()) {
            int size = nodes.size();
            
            target_node = nodes.front();

            for (size_t i = 0; i < size; i++) {
                TreeNode* curr_node = nodes.front();
                nodes.pop();

                if (curr_node->left != nullptr) {
                    nodes.push(curr_node->left);
                }

                if (curr_node->right != nullptr) {
                    nodes.push(curr_node->right);
                }
            }

        }

        return target_node->val;
    }
};