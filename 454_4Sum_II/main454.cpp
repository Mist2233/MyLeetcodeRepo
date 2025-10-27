#include<vector>
#include<unordered_map>

using namespace std;

/* 分组哈希法：先计算两组的和，再计算另两组的和，然后将四数之和，变成两数之和 */
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sums12, sums34;
        size_t len = nums1.size();
        int ans = 0;

        for (size_t i = 0; i < len; i++) {
            for (size_t j = 0; j < len; j++) {
                sums12[nums1[i] + nums2[j]] ++;
                sums34[nums3[i] + nums4[j]] ++;
            }
        }

        for (auto it12 = sums12.begin(); it12 != sums12.end(); it12++) {
            int target = - it12->first;
            auto it34 = sums34.find(target);
            if (it34 != sums34.end()) {
                ans += it12->second * it34->second;
            }
        }
        return ans;
    }
};