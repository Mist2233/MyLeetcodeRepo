网址：https://leetcode.cn/problems/restore-ip-addresses/description/

Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.


给一个纯数字组成的字符串，要判断它可能组成的IP地址。

这里，注意最大位数为12，所以超过12的都直接去掉。小于4位的也不要。

然后，考虑回溯的部分。

我们需要在什么位置打点？


其实，划分IP地址，本质就是将某一串数字分成几段，每一段都位于[0, 255]区间内。
- 向下传递，我们需要划分的段数。
- 以及剩下的字符串。（这里传一个start_idx即可）
- 当剩余0段时，终止。

写的时候觉得有点难，写完之后就觉得不难了。

在哪里卡住了呢？应该是检查终止条件，以及是否以0开头的这里。重点是去查看长度。


