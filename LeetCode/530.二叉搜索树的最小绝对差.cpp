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
    int diff = INT_MAX;
    TreeNode* prev = nullptr;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root -> left);
        if (prev) diff = min(diff, abs(prev -> val - root -> val));
        prev = root;
        dfs(root -> right);

    }
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return diff;
    }
};
// @lc code=end

