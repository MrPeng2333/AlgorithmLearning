/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
class Solution {
public:
    
    vector<int> pathInZigZagTree(int label, int level = 0) {
        while (1 << level <= label) level++;    // 求出label所在层，level从1开始，(1 << level) - 1 < label
        vector<int> res(level);
        for (; label >= 1; label /= 2, level--) {
            res[level - 1] = label;
            label = (1 << level) - label - 1 + (1 << (level - 1));
        }
        return res;
    }
};
// @lc code=end

