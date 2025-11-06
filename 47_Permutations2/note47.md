[47.全排列2](https://leetcode.cn/problems/permutations-ii/)

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

相比于第46题，这一题多了一个“数字可以重复”的条件。

怎么解答？先回顾一下第46题的解答吧。

---
今天这道47题，我在实现时犯了一个错误：
1. 把 `ans` 这个数组又引入了。其实不需要 `ans` 这个数组，因为我每次 push 的对象都是整个重新排过序的 `nums`，不需要一个中间态来过渡。


---
第一次提交失败了，我的去重不到位。

我要理解“为什么重复”，以及“什么地方导致重复”，而不是一味地套用模板……套模板是无法解出题目的……

来看错误的解答：
```cpp
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    // 基础结构和第46题完全相同，需要增加的就是跳过的重复数字的部分。
    void backtrack(vector<int>& nums, int start_idx) {
        if (start_idx == nums.size() - 1) {
            result.push_back(nums);
        }

        for (int i = start_idx; i < nums.size(); i++) {
            if (i > start_idx && nums[i] == nums[i - 1]) continue;
            if (i > start_idx && nums[i] == nums[start_idx]) continue;
            swap(nums[start_idx], nums[i]);
            backtrack(nums, start_idx + 1);
            swap(nums[start_idx], nums[i]);
        }
    }

private:
    vector<vector<int>> result;
};
```


搞清楚一点：我们要去重的情况，到底是哪一些情况？
- 我们使用交换的做法，来遍历各种情况。
- 首先，每个数字会和自己交换，得到一种事实上没有交换的情况，并以此为基础，延伸出其他情况。
- 在没有重复数字的数组中，不会导致重复。
- 但是，在存在重复数字的数组中，当我们交换两个重复数字时，得到的情况，是与“每个数字会和自己交换”一样的，也就是多余的情况。
- 这就是我们需要去掉的情况！
- 怎么做呢？我们构造一个集合 `used`，存放本层（注意是本层）已经交换过的数字。下一次，再碰到重复数字时，就跳过它。这样，就不会出现多余的情况。

用心体会这种做法的正确性！

再来看正确的解答：
```cpp
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }

    // 基础结构和第46题完全相同，需要增加的就是跳过的重复数字的部分。
    void backtrack(vector<int>& nums, int start_idx) {
        if (start_idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> used;  // 记录当前层已经处理过的数
        for (int i = start_idx; i < nums.size(); ++i) {
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[start_idx], nums[i]);
            backtrack(nums, start_idx + 1);
            swap(nums[start_idx], nums[i]);
        }
    }

private:
    vector<vector<int>> result;
};
```
