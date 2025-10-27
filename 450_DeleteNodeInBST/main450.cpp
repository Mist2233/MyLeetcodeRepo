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
从BST中删除节点，分成三步：
1. 找到该节点
2. 删除该节点
3. 维持删除后BST的性质

怎么找？直接迭代搜索即可，log n 时间即可完成。

第二步和第三步其实紧密相连，因为删除节点之后，就必须要给被删掉的节点找一个替代的节点。
- 若被删除的为叶子节点，那么什么都不用做。
- 若被删除的节点只有一个子节点，那么用该子节点代替被删除的节点即可。
- 若被删除的节点有两个子节点，那么，这个替代的过程似乎需要不断地向下传递。
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = findNode(root, key);
        return deleteNode(root, target);
    }

    TreeNode* findNode(TreeNode* root, int key) {
        TreeNode* to_be_delete = root;

        while (to_be_delete != nullptr) {
            if (to_be_delete->val > key) {
                to_be_delete = to_be_delete->left;
            }
            else if (to_be_delete->val < key) {
                to_be_delete = to_be_delete->right;
            }
            else {
                break;
            }
        }

        return to_be_delete;
    }

    TreeNode* deleteNode(TreeNode* root, TreeNode* target) {
        if (target == nullptr) {
            return root;
        }

        if (target->left == nullptr && target->right == nullptr) {
            delete target;
            target = nullptr;
            return root;
        }

        if (target->left == nullptr) {
            TreeNode* temp = target->right;
            delete target;
            target = temp;
            return root;
        }

        if (target->right == nullptr) {
            TreeNode* temp = target->left;
            delete target;
            target = temp;
            return root;
        }

        /*
        这里，涉及三个节点：target, target->left和target->right。

        我印象中，数据结构课上教我们，需要将target先换到叶子节点的位置，然后再删掉。
        具体方法是什么“左旋”和“右旋”之类的……但我记不清楚了。

        我凭着自己理解：要保持BST的性质，就是不考虑target节点的情况下，在“我”左边的节点一直在“我”左边，在“我”右边的节点一直在“我”右边。
        
        或者，不用非要换到叶子节点，只需要让target的子节点个数变成一个即可。

        我思考了下，还是决定将target和某一个节点换位，而找到这个节点的方式，就类似BST中的查找，但是查找到节点相应的子节点为空就结束。
        */
        TreeNode* temp_left = target->left, *temp_right = target->right;

        TreeNode* cur = temp_right;

        while (cur != nullptr) {
            // 这里只有两种情况，不会出现相等的情况，因为BST中没有重复元素
            if (cur->val > target->val) {
                if (cur->left == nullptr) break;
                cur = cur->left;
            }
            else if (cur->val < target->val) {
                if (cur->right == nullptr) break;
                cur = cur->right;
            }
        }

        // 交换target和cur的位置，现在target就至多一个子节点，而cur换上去之后，也能满足BST的性质。
        swap(target, cur);
        // 递归调用一次。
        return deleteNode(root, target);
    }
};

/*
从BST中删除节点，分成三步：
1. 找到该节点
2. 删除该节点
3. 维持删除后BST的性质

怎么找？直接迭代搜索即可，log n 时间即可完成。

第二步和第三步其实紧密相连，因为删除节点之后，就必须要给被删掉的节点找一个替代的节点。
- 若被删除的为叶子节点，那么什么都不用做。
- 若被删除的节点只有一个子节点，那么用该子节点代替被删除的节点即可。
- 若被删除的节点有两个子节点，那么，这个替代的过程似乎需要不断地向下传递。
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = findNode(root, key);
        return deleteNode(root, target);
    }

    TreeNode* findNode(TreeNode* root, int key) {
        TreeNode* to_be_delete = root;

        while (to_be_delete != nullptr) {
            if (to_be_delete->val > key) {
                parent = to_be_delete;
                flag = true; // true表示to_be_delete作为左节点存在
                to_be_delete = to_be_delete->left;
            }
            else if (to_be_delete->val < key) {
                parent = to_be_delete;
                flag = false; // false 表示to_be_delete作为右节点存在
                to_be_delete = to_be_delete->right;
            }
            else {
                break;
            }
        }

        return to_be_delete;
    }

    TreeNode* deleteNode(TreeNode* root, TreeNode* target) {
        if (target == nullptr) {
            return root;
        }

        if (target->left == nullptr && target->right == nullptr) {
            delete target;
            return root;
        }

        if (target->left == nullptr) {
            TreeNode* temp = target->right;
            delete target;
            if (flag) {
                parent->left = temp;
            }
            else {
                parent->right = temp;
            }
            return root;
        }

        if (target->right == nullptr) {
            TreeNode* temp = target->left;
            delete target;

            if (flag) {
                parent->left = temp;
            }
            else {
                parent->right = temp;
            }
            
            return root;
        }

        /*
        这里，涉及三个节点：target, target->left和target->right。

        我印象中，数据结构课上教我们，需要将target先换到叶子节点的位置，然后再删掉。
        具体方法是什么“左旋”和“右旋”之类的……但我记不清楚了。

        我凭着自己理解：要保持BST的性质，就是不考虑target节点的情况下，在“我”左边的节点一直在“我”左边，在“我”右边的节点一直在“我”右边。
        
        或者，不用非要换到叶子节点，只需要让target的子节点个数变成一个即可。

        我思考了下，还是决定将target和某一个节点换位，而找到这个节点的方式，就类似BST中的查找，但是查找到节点相应的子节点为空就结束。
        */
        TreeNode* temp_left = target->left, *temp_right = target->right;

        TreeNode* cur = temp_right;

        while (true) {
            // 这里只有两种情况，不会出现相等的情况，因为BST中没有重复元素
            if (cur->val > target->val) {
                if (cur->left == nullptr) break;
                cur = cur->left;
            }
            else if (cur->val < target->val) {
                if (cur->right == nullptr) break;
                cur = cur->right;
            }
        }

        // 交换target和cur的位置，现在target就至多一个子节点，而cur换上去之后，也能满足BST的性质。
        int temp_val = target->val;
        target->val = cur->val;
        cur->val = temp_val;
        // 递归调用一次。
        return deleteNode(root, cur);
    }
private:
    TreeNode* parent = nullptr;
    bool flag = false;
};

/*
上面两个版本的代码都是错误的，我需要一个“真”递归版本，即通过递归的返回值赋值，来完成对树的修改。

对deleteNode(Treenode* root, int key)新的契约：
    这个函数会从以 root 为根的树中删除值为 key 的节点，并返回删除后新的树（或子树）的根节点。
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        // 核心情况：当前节点就是我们需要的节点
        // 现在，root 就是我们要删除的节点。我们在这里执行真正的删除操作，并决定应该返回什么来替代 root 的位置。
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        
        // 找替身（最重要的一点，我就是忘记了这个，导致这道题不会做！！！）：右子树中的最小值，或者左子树中的最大值，都可以替代当前根节点
        TreeNode* successor = root->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        root->val = successor->val;
        // 更新对应子树
        root->right = deleteNode(root->right, successor->val);

        return root;
    }
};