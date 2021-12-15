/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
    void longestZigZagHelper(TreeNode* root, bool isZigZag, bool isRight, int len = 0) {
        if (!root) return;
        if (isZigZag) res = max(res, ++len);
        else len = 1;
        longestZigZagHelper(root -> left, isRight, false, len);
        longestZigZagHelper(root -> right, !isRight, true, len);
    }
    int longestZigZag(TreeNode* root) {
        longestZigZagHelper(root -> left, true, false);
        longestZigZagHelper(root -> right, true, true);
        return res;
    }
};
// @lc code=end

