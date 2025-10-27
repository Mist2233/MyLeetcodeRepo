#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (j >= i + 2 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 一开始这里没有使用long long类型，而是用了int类型，导致出错。
                // 而且，光是前面使用long long是不够的，后面也必须有long long 类型，才能保证计算出来的不会溢出。
                // 如果后面的计算数字全是int 类型，那么最后结果会自动转为int，还是会溢出。
                long long new_target = (long long)target - nums[i] - nums[j];

                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int num_left = nums[left], num_right = nums[right];
                    int sum = num_left + num_right;
                    if (sum == new_target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == num_left) {
                            left++;
                        }
                        while (right > left && nums[right] == num_right) {
                            right--;
                        }
                    }
                    else if (sum < new_target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }

            }
        }
        return ans;
    }
};