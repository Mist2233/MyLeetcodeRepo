// 用快慢指针法解决这个问题--判断链表是否有环的经典方法。

#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));

            if (slow == fast) {
                break;
            }
        }

        return (slow == 1);
    }

    int getNext(int n) {
        int next_num = 0;
        while (n > 0) {
            int digit = n % 10;
            next_num += digit * digit;
            n /= 10;
        }
        return next_num;
    }
};