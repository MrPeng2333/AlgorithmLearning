/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void traverse(TreeNode* root, int &diff, TreeNode* &prev) {
        if (!root) return;
        traverse(root -> left, diff, prev);
        if (prev) {
            int newDiff = root -> val - prev -> val;
            diff = min(diff, newDiff);
        }
        prev = root;
        traverse(root -> right, diff, prev);
    }
    int getMinimumDifference(TreeNode *root) {
        TreeNode* prev = NULL;
        int diff = 1e5 + 10;
        traverse(root, diff, prev);
        return diff;
    }
};
// @lc code=end

