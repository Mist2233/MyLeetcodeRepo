#include<vector>
#include<string>
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
有非常多的路径可以选择。
比如，走左边还是走右边。
关键在怎么表示不同的路径。
比如说，一个节点分了两岔，那么怎么把两种分支都表现出来呢？
先不追求输出到叶子节点的路径，先输出到自己子节点的路径。直到没有节点可以继续输出，那就是到了叶节点了。
把所有输出到自己子节点的路径都拼起来，就是一条路径。
但是，最后需要输出一个string组成的vector，这个怎么递归呢？感觉也不难吧。
我们就用递归的思路完成。
*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        if (root->left == nullptr && root->right == nullptr) {
            // 使用to_string函数，将int、double和float类型转为string类型。
            return {to_string(root->val)};
        }
        
        vector<string> path_from_root;

        if (root->right != nullptr) {
            vector<string> path_from_right = binaryTreePaths(root->right);
            for (string path: path_from_right) {
                // 使用“+”来拼接字符串。
                path_from_root.push_back(to_string(root->val) + "->" + path);
            }
        }

        if (root->left != nullptr) {
            vector<string> path_from_left = binaryTreePaths(root->left);
            for (string path: path_from_left) {
                path_from_root.push_back(to_string(root->val) + "->" + path);
            }
        }

        return path_from_root;
    }
};