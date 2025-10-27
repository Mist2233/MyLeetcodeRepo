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
用DFS和Recursion的方法解决问题。
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int max_depth = -1;
        int result = 0;

        dfs(root, 0, max_depth, result);

        return result;
    }

    // 规定dfs的顺序是先走左子树，再走右子树，那么我们在新的深度发现的第一个节点，就必然是该深度最左边的节点。
    // 这就解决了如何确定某个节点是否是最左的情况了。
    void dfs(TreeNode* node, int current_depth, int& max_depth, int& result) {
        if (node == nullptr) {
            return;
        }
        
        // 如果当前深度比最大深度更大，那么说明到达新的一层，需要更新内容。
        if (current_depth > max_depth) {
            result = node->val;
            max_depth = current_depth;
        }

        dfs(node->left, current_depth + 1, max_depth, result);
        dfs(node->right, current_depth + 1, max_depth, result);
    }

};