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
    TreeNode* pre = NULL;
    void check(TreeNode* root) {
        if (!root) return;
        check(root -> left);
        if (pre && root -> val - pre -> val < diff) diff = (root -> val) - (pre -> val);
        pre = root;
        check(root -> right);
    }
    int getMinimumDifference(TreeNode *root) {
        check(root);
        return diff;
    }
};
// @lc code=end

