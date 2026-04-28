#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> all_nums(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                all_nums[i * n + j] = grid[i][j];
            }
        }

        sort(all_nums.begin(), all_nums.end());

        int mid_index = (m * n) / 2;
        int mid_num = all_nums[mid_index];
        int op_cnt = 0;

        for (int i = 0; i < m * n; i++) {
            int distance = abs(mid_num - all_nums[i]);
            if (distance % x != 0) {
                return -1;
            }
            op_cnt += distance / x;

        }

        return op_cnt;
    }
};

/**
 * 给定一个 m x n 的矩阵，以及一个整数 x。
 * 每次可以将矩阵中的数字加上 x 或者减去 x，这样算是一次操作。
 * 
 * 问：至少需要多少次操作，使得矩阵中的数字全部相同？（没有要求要和哪一个数字相同）
 * 
 * 矩阵中的数字全部都是正整数。
 * 
 * 首先，什么时候可以，什么时候不可以？
 * 可以找矩阵里面两个数字的差。如果两个数字最终变成了同一个，那么它们的差一定是x的倍数。
 * 如果存在差不是x的倍数，那么就不可能实现。
 * 
 * 其次，怎么操作才能使得次数最少？
 * 先假设x是1好了，应该就是要找中间的数字吧，也就是到所有数字距离都最小的一个值。
 * 不一定是已经存在的数字，可能是不存在的数字。
 * 
 * 这不是小学升初中的经典问题吗？就是在数轴上给一堆点，找一个点到所有点的距离和最小。
 * 
 * 假设有四个（偶数个）数字：1, 2, 3, 5。取中间两个的任意一个都行。
 * 
 * 假设有五个（奇数个）数字：1, 3, 5, 7, 9。取中间的数字就行。
 */

#include <cstdio>

int main() {
    Solution sol;

    // 基本用例：全部通过 +x/-x 可以到达
    {
        vector<vector<int>> grid = {{2, 4}, {6, 8}};
        int res = sol.minOperations(grid, 2);
        printf("Test 1 (expect 4): %d\n", res);
        // 全部变到4或6: 2->4(1), 6->4(1), 8->4(2) = 4; 或者 2->6(2), 8->6(1), 4不变 = 3...
        // 中位数是5(不存在)，取4或6都行。4: |2-4|/2+|4-4|/2+|6-4|/2+|8-4|/2 = 1+0+1+2=4
    }

    // 不可能的情况：差值不是x的倍数
    {
        vector<vector<int>> grid = {{1, 2}, {3, 4}};
        int res = sol.minOperations(grid, 2);
        printf("Test 2 (expect -1): %d\n", res);
    }

    // 已经全部相同
    {
        vector<vector<int>> grid = {{5, 5}, {5, 5}};
        int res = sol.minOperations(grid, 1);
        printf("Test 3 (expect 0): %d\n", res);
    }

    // x=1 的情况
    {
        vector<vector<int>> grid = {{1, 2, 3}};
        int res = sol.minOperations(grid, 1);
        printf("Test 4 (expect 2): %d\n", res);
        // 中位数是2: |1-2|+|2-2|+|3-2| = 2
    }

    // 单元素
    {
        vector<vector<int>> grid = {{42}};
        int res = sol.minOperations(grid, 5);
        printf("Test 5 (expect 0): %d\n", res);
    }
}