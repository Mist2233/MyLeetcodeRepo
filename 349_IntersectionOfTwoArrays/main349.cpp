#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> num_counts;
        for (int num: nums1) {
            if (num_counts[num] == 0) {
                num_counts[num]++;
            }
        }

        for (int num: nums2) {
            if (num_counts[num] == 1) {
                num_counts[num]++;
            }
        }

        vector<int> ans;
        for (auto it = num_counts.begin(); it != num_counts.end(); it++) {
            int num = it->first, count = it->second;
            if (count == 2) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};