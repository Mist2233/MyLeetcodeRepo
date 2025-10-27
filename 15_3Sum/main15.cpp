#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i >= 1 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = - nums[i];

            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int num_left = nums[left], num_right = nums[right];
                int sum = num_left + num_right;
                if (sum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == num_left) {
                        left++;
                    }
                    while (right > left && nums[right] == num_right) {
                        right--;
                    }
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};