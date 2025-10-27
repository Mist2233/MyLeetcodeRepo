#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

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
inorder: left - root - right
postorder: left - right - root

因此，在后序遍历中的最后一个值，就是根节点的值。

基本思路：用递归
- 每次在postorder中找到最后一个值，那是root的值。
- 根据root的值，将inorder分成两部分。前一部分代表左子树inorder_left，后一部分代表右子树inorder_right。
- 根据inorder的两部分，将postorder也分成两部分（这一步有点难），postorder_left和postorder_right。
- 然后，左子树和右子树各自递归构造，得到left_node和right_node。
- 最后，和root合并，大功告成。

我之前想的太复杂了。将inorder分成左子树和右子树之后，根据vector的大小，就可以将postorder分成两个部分，而不用去找所谓的分割点。
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        
        if (inorder.size() == 1) {
            return new TreeNode(inorder[0]);
        }

        int root_val = postorder.back();
        TreeNode* root  = new TreeNode(root_val);

        auto root_it = find(inorder.begin(), inorder.end(), root_val);

        // 学会用vector的构造函数来初始化vector，而不是用容易错的循环！
        vector<int> inorder_left(inorder.begin(), root_it);
        vector<int> inorder_right(root_it + 1, inorder.end());

        vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
        vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end() - 1); // 排除末尾的根节点。
        
        TreeNode* left_node = buildTree(inorder_left, postorder_left);
        TreeNode* right_node = buildTree(inorder_right, postorder_right);

        root->left = left_node;
        root->right = right_node;

        return root;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 用一个哈希表记录val->index的映射，可以加速查找。
        unordered_map<int, int> inorder_map;
        
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        // 当你写出区间时，心里要想明白，这个区间的开闭情况如何？
        // 比如说，这里我明明是闭区间，一开始却用了开区间的写法，导致index out of range.
        return build(inorder, 0, inorder.size() - 1,
                    postorder, 0, postorder.size() - 1,
                    inorder_map);
    }
    // 构造一个新的函数，将vector用引用来传递，并且规定每一次的序列范围
    // 这样，就可以减少内存和计算的开销。
    TreeNode* build(vector<int>& inorder, int in_start, int in_end,
                    vector<int>& postorder, int post_start, int post_end,
                    unordered_map<int, int>& inorder_map) {
        if (in_start > in_end || post_start > post_end) {
            return nullptr;
        }

        int root_val = postorder[post_end];
        int root_index = inorder_map[root_val];

        TreeNode* root = new TreeNode(root_val);

        TreeNode* left_node = build(inorder, in_start, root_index - 1,
                                    postorder, post_start, post_start + root_index - 1 -in_start,
                                    inorder_map);
        TreeNode* right_node = build(inorder, root_index + 1, in_end, 
                                     postorder, post_end - in_end + root_index, post_end - 1, // 这里别忘记排除最后一个root的值！！！
                                     inorder_map);
                
        root->left = left_node; root->right = right_node;

        return root;
    }
};

