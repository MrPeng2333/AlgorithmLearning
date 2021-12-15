/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
    
    int pseudoPalindromicPaths (TreeNode* root, int count = 0) {
        if (!root) return 0;
        count ^= 1 << (root -> val - 1);
        int res = pseudoPalindromicPaths(root -> left, count) + pseudoPalindromicPaths(root -> right, count);
        if (root -> left == root -> right && (count & (count - 1)) == 0) res++;
        return res;
    }
};
// @lc code=end

