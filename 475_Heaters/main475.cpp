#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // 相当于求所有house和所有heater之间距离最小值的最大值。

        sort(heaters.begin(), heaters.end());
        int max_min_dist = 0;
        for (size_t i = 0; i < houses.size(); i++) {
            long long min_dist;
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            
            if (it == heaters.begin()) {
                min_dist = *it - houses[i];
            }

            else if (it == heaters.end()) {
                min_dist = houses[i] - *(it - 1);
            }
            
            else {
                min_dist = min(*it - houses[i], houses[i] - *(it - 1));
            }

            if (min_dist > max_min_dist) {
                max_min_dist = min_dist;
            }
        }
        return max_min_dist;
    }
};