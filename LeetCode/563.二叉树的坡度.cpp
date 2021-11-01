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
    int ans = 0;
    int nodeTilt(TreeNode* root) {
        if (root == nullptr) return 0;
        int ls = nodeTilt(root -> left);
        int rs = nodeTilt(root -> right);
        ans += abs(ls - rs);
        return root -> val + rs + ls;
    }
    int findTilt(TreeNode* root) {
        nodeTilt(root);
        return ans;
    }
};
// @lc code=end

