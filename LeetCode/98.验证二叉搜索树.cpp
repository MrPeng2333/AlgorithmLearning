/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool l = isValidBST(root -> left);
        if (prev && prev -> val >= root -> val) return false;
        prev = root;
        bool r = isValidBST(root -> right);
        return l && r;
    }
};
// @lc code=end

