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

/* 更好的方法：回溯法(Backtracking)/携带路径的深度优先搜索(DFS with Path)
核心思想：不再让递归函数返回一个路径列表，而是把最终的结果列表和一个当前的路径作为参数，一路传递下去

用引用将我们最终的结果列表传递下去，这样每一次递归都能在最终的结果列表中添加内容了。

新方法的好处：不用储存大量的vector，而只在一个vector上修改，节约内存。
*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths_from_root;
        vector<int> initial_path;

        findPaths(root, initial_path, paths_from_root);

        return paths_from_root;
    }


    void findPaths(TreeNode* node, vector<int>& path, vector<string>& all_paths) {
        if (node == nullptr) return;

        // get into current node if current node is not nullptr.
        path.push_back(node->val);

        // find the leaf node, get a string of this path.
        if (node->left == nullptr && node->right == nullptr) {
            string path_str;
            for (size_t i = 0; i < path.size(); i++) {
                path_str += to_string(path[i]);
                if (i != path.size() - 1) {
                    path_str += "->";
                }
            }

            all_paths.push_back(path_str);
        }

        if (node->left != nullptr) {
            findPaths(node->left, path, all_paths);
        }

        if (node->right != nullptr) {
            findPaths(node->right, path, all_paths);
        }

        // get out current node to trace back.
        path.pop_back();
    }
};