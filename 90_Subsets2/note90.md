https://leetcode.cn/problems/subsets-ii/description/

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

---
这一道题目，和第78题的区别就是，出现了重复的元素。

怎么处理重复的元素？其实我们也碰到过很多次了。可是，我还是回想不太起来。

我想起来了，和之前在“组合”问题中碰到的类似：
- 对于多个元素的部分，只在第一次碰到这个元素时，寻找重复的元素。

那么，就是在遍历时，加一个跳过的机制，即可。

