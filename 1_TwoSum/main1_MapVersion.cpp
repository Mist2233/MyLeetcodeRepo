#include<bits/stdc++.h>

using namespace std;

/*
回忆一下，这道两数之和是用哈希表快速实现的。

遍历nums，先确定第一个数，然后用target减去这个数，得到我们需要搜索的数nee_num。

关键之处：边搜索，边构建num2idx这个映射。
- 如果找到值，就把这一对数字都放入ans
- 如果没找到值，就把当前数字添加到num2idx中，以便于后面的数字搜索。


*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); i++) {
            int need_num = target - nums[i];
            if (num2idx.find(need_num) != num2idx.end()) {
                ans.push_back(i);
                ans.push_back(num2idx[need_num]);
                return ans;
            }
            num2idx[nums[i]] = i;
        }
        return ans;
    }
};