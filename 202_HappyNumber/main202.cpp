#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int next_num = 0;
        unordered_set<int> exist_nums;

        while (exist_nums.find(n) == exist_nums.end()) {
            exist_nums.insert(n);
            while (n > 0) {
                int digit = n % 10;
                next_num += digit * digit;
                n /= 10;
            }

            if (next_num == 1) {
                return true;
            }

            n = next_num;
            next_num = 0;
        }
        return false;
    }
};