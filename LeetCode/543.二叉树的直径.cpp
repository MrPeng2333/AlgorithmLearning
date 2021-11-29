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
    int traverse(TreeNode* root, int &diameter) {
        if (!root) return 0;
        int lh = traverse(root -> left, diameter);
        int rh = traverse(root -> right, diameter);
        int newDiameter = lh + rh;
        diameter = max(diameter, newDiameter);
        return max(lh, rh) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        traverse(root, diameter);
        return diameter;
    }
};
// @lc code=end

