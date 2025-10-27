#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        // 双指针实现位移
        int p = 0;
        for (int q = 0; q < len; q++) {
            if (nums[q] == val) continue;
            swap(nums[p], nums[q]);
            p++;
        }

        int k = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] == val) {
                k++;
            }
        }
        return len - k;
    }
};