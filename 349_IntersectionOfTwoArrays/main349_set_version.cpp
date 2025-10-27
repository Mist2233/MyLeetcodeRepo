#include<vector>
#include<map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num_set, result_set;

        for (int num: nums1) {
            num_set.insert(num);
        }

        for (int num: nums2) {
            if (num_set.find(num) != num_set.end()) {
                result_set.insert(num);
            }
        }

        return vector<int>(result_set.begin(), result_set.end());
    }
};