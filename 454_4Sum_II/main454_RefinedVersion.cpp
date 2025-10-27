#include<vector>
#include<unordered_map>

using namespace std;

/* 分组哈希法：先计算两组的和，再计算另两组的和，然后将四数之和，变成两数之和 */
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sums12;
        size_t len = nums1.size();
        int ans = 0;

        for (size_t i = 0; i < len; i++) {
            for (size_t j = 0; j < len; j++) {
                sums12[nums1[i] + nums2[j]] ++;
            }
        }

        for (size_t i = 0; i < len; i++) {
            for (size_t j = 0; j < len; j++) {
                int sum34 = nums3[i] + nums4[j];
                auto it = sums12.find(-sum34);
                if (it != sums12.end()) {
                    ans += it->second;
                }
            }
        }

        return ans;
    }
};