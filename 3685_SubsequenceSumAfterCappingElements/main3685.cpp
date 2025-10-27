#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        vector<bool> ans;
        // 将原数组列
        sort(nums.begin(), nums.end(), [](int a, int b) {return a > b;});

        // 建立一个经典的0-1背包dp表。 dp[idx][sum]表示用idx到结尾下标范围的元素，能否凑出sum这个值。
        // dp[idx][sum] = dp[idx + 1][sum] || dp[idx + 1][sum - nums[idx]]   （状态转移方程）
        // dp两个列表的范围？idx的范围是[0, n-1]，sum的范围是[1, k]
        // 怎么初始化一个矩阵？卧槽我现在居然还不会这个……
        int n = nums.size();
        // 正确的构造二维向量的方法vector<bool>(vec_len, vec_init);
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        // 下面这种构造方法是完全错误的，因为row只是原本dp中每一行的copy。我修改row，完全不会影响原本的dp
        // for (vector<bool> row: dp) {
        //     row = vector<bool>(k + 1);
        // }
        dp[n][0] = true;
        // 先初始化最后一行。
        // 当idx == n-1时，只有一个数字可以选择，因此只需要判断sum和这个数是否相等即可。

        // 怎么维护这个dp矩阵？从后向前，从idx = n的时候开始，向前转移。
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int sum = 0; sum <= k; sum++) {
                // 这里要当心数组越界的问题
                if (sum >= nums[idx]) {
                    dp[idx][sum] = dp[idx + 1][sum] || dp[idx + 1][sum - nums[idx]];
                }
                else {
                    dp[idx][sum] = dp[idx + 1][sum];
                }
            }
        }

        // 然后，是具体每一种情况下的分类，就是对每一个x的cap来选择。
        for (int x = 1; x <= n; x++) {
            // 找到第一个不大于x的元素。
            auto it = upper_bound(nums.begin(), nums.end(), x, [](int a, int b) {return a > b;});
            int t = distance(nums.begin(), it); // 现在有t个数都是作为x而存在，
            bool flag = false;
            for (int m = 0; m <= t; m++) {
                int target_sum = k - m * x;
                
                if (target_sum < 0) break; // 防止数组越界

                if (dp[t][target_sum]) {
                    flag = true;
                    break;
                }
            }
            ans.push_back(flag);
        }

        return ans;

    }
};