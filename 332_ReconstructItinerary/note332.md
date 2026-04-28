https://leetcode.cn/problems/reconstruct-itinerary/

You are given a list of **airline tickets** where `tickets[i] = [fromi, toi]` represent the **departure** and the **arrival** airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has **the smallest lexical order** when read as a single string.

For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

-------
给我们的是一组机票，每张机票都有一个起点from和终点to。

我的任务：将所有的from和to练成一条线，使得所有的点都能被走到。

最后输出路线。

如果有多个路线，还需要输出字母序最小的那个路线，怎么做？

完蛋，怎么一点思路都没有，我不会真的变笨了吧？

起码这道题我不能用AI。


-------------
从JDK开始，先找到以JDK为起点的一张机票。
- 怎么找到JDK？
- 答案：遍历所有的内容。

我需要标记某个位置是否选过了，以及怎么才能选到下一个位置。

怎么标记一个机票是否已经被选过了？
- 答案：创建一个新的bool数组，标记每个ticket是否被取用过。

怎么遍历所有的情况？
- 答案：通过回溯法？

怎么回溯？
- 