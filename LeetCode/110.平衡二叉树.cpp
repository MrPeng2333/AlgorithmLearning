/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
private:
    int isBalancedByDeepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = isBalancedByDeepth(root -> left);
        int rh = isBalancedByDeepth(root -> right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedByDeepth(root) != -1;
    }
};
// @lc code=end

