#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        // 逐位统计，从第0位（LSB）到第31位（MSB）
        for (int digit = 0; digit < 32; digit++) {
            int cnt = 0;
            for (int num: nums) {
                // 怎么取出digit对应的位数？利用移位和AND。
                cnt += (num >> digit) & 1;
            }
            
            if (cnt % 3 == 1) {
                // 利用OR操作来设置位数
                // 这里注意不要用加法，否则对负数就出问题了。
                res |= (1 << digit);
            }
        }
        return res;
    }
};

/**
 * 给定一个数组 nums，里面每个数字都出现了三次，除了某一个数。
 * 
 * 目标：找到这个数字，并返回。
 * 
 * 要求：线性时间复杂度 + 常数空间。
 * 
 * 怎么思考这道题目？能用dp吗？好像不用。这道题有什么背景吗？
 * 比如每个数字都出现两次的情况，怎么处理？
 * 好像是使用二进制里面的异或算法：两个相同的数字，异或之后就消失了。
 * 
 * 那么在这里，就是需要写一个三进制的异或？怎么写呢？还有什么没考虑到的地方？
 * 
 * 好的，现在思路已经明确：
 * 1. 将所有数字按照二进制格式来处理。
 * 2. 统计每个位置上“1”出现的次数。
 * 3. 最后mod3处理，得到的结果就是我们需要的数字的结果。
 */

int main() {
    Solution sol;
    vector<int> input = {2, 2, 3, 2};

    printf("%d\n", sol.singleNumber(input));    
}
