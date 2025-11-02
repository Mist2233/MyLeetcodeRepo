https://leetcode.cn/problems/non-decreasing-subsequences/description/

Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

这个题，感觉我在dp里面也做过。简称非递减子序列为nds。

每一个nds都是由一个更短的nds扩充而来。因此，我们每次选择一个nds，然后以它的最后一个元素为基点，找一个更大的元素，即可。

---
现在的代码如下：
```cpp
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }

    void backtrack(const vector<int>& nums, int start_idx) {
        if (ans.size() > 1) {
            result.push_back(ans);
        }

        for (int i = start_idx; i < nums.size(); i++) {
            // 跳过重复元素，但是不能跳过第一个碰到的元素
            if (i > start_idx && nums[i] == nums[i - 1]) {
                continue;
            }

            // 如果是ans是空集，那么先push一个元素进去
            if (ans.empty()) {
                ans.push_back(nums[i]);
                backtrack(nums, i + 1);
                ans.pop_back();
            }
            // 如果ans不是空集，那么push元素的条件是“非递减”
            else {
                if (nums[i] >= ans.back()) {
                    ans.push_back(nums[i]);
                    backtrack(nums, i + 1);
                    ans.pop_back();
                }
            }
        }
    }

private:
    vector<int> ans;
    vector<vector<int>> result;
};
```

不知道出了什么问题，下面这个测试样例过不了：
```
[1,2,3,4,5,6,7,8,9,10,1,1,1,1,1]
```

难道说，是后面的`1,1,1,1,1`这里的非递减性没有体现出来吗？

---
可以试试下面的测试程序：
```cpp
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 1, 1};
    vector<vector<int>> result = sol.findSubsequences(nums);
    for (const auto& seq : result) {
        cout << "[";
        for (size_t i = 0; i < seq.size(); ++i) {
            if (i) cout << ", ";
            cout << seq[i];
        }
        cout << "]\n";
    }
    return 0;
}
```

这输出结果如下：
```output
[1, 2]
[1, 1]
[1, 1, 1]
[1, 1, 1, 1]
[1, 1]
[1, 1, 1]
```

出现了重复的序列……

如何避免重复呢？我的去重逻辑没做好。

我的去重逻辑是这样的：
```cpp
            // 跳过重复元素，但是不能跳过第一个碰到的元素
            if (i > start_idx && nums[i] == nums[i - 1]) {
                continue;
            }
```

但是，这只在数组有序时有效。这一道题，数组不一定有序。

所以，我需要更新去重策略：
```cpp
void backtrack(const vector<int>& nums, int start_idx) {
    if (ans.size() > 1) {
        result.push_back(ans);
    }

    unordered_set<int> used;  // 本层去重
    for (int i = start_idx; i < nums.size(); ++i) {
        if (!ans.empty() && nums[i] < ans.back()) {
            continue;
        }
        if (used.count(nums[i])) {
            continue;
        }
        used.insert(nums[i]);

        ans.push_back(nums[i]);
        backtrack(nums, i + 1);
        ans.pop_back();
    }
}
```