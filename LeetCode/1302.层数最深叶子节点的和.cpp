/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int deepestLevel = 0;
    void deepestLeavesSum(TreeNode* root, int level) {
        if (!root) return;
        if (!(root -> left) && !(root -> right)) {
            if (level > deepestLevel) {
                res = root -> val;
                deepestLevel = level;
            } else if (level == deepestLevel)
                res += root -> val;
        }
        deepestLeavesSum(root -> left, level + 1);
        deepestLeavesSum(root -> right, level + 1);

    }
    int deepestLeavesSum(TreeNode* root) {
        deepestLeavesSum(root, 0);
        return res;
    }
};
// @lc code=end

