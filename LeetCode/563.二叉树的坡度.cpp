/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int traverse(TreeNode* root) {
        if (!root) return 0;
        int ls = traverse(root ->left);
        int rs = traverse(root -> right);
        int diff = abs(ls - rs);
        res += diff;
        return root -> val + ls + rs;
    }
    int findTilt(TreeNode* root) {
        traverse(root);
        return res;
    }
};
// @lc code=end

