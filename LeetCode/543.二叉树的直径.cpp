/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int check(TreeNode* root) {
        if (!root) return 0;
        int lh = check(root -> left);
        int rh = check(root -> right);
        if (lh + rh > res) res = lh + rh;
        return max(lh, rh) + 1;  
    }
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return res;    
    }
};
// @lc code=end

