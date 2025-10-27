题目链接：https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
解答链接：https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0108.%E5%B0%86%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.md

ascending order升序数组

给定一个升序数组，将其转为height-balanced BST。

> A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

也就是说，不能瞎转，而是要保持树的平衡性。

可以利用递归，怎么设定契约？

可以每一次都让中位数作为root，将数组分成两半，然后递归处理剩下的数字。

那么契约可以这么写：
- `sortedArrayToBST` 函数接收`nums`和对应的下标范围`[low, high]`，并返回以`[low, high]`中的节点作为内容的子树的根节点。