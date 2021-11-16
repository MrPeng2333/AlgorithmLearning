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
    
public:
    bool ans = true;
    int check(TreeNode* root) {
        if (!root) return 0;
        if (!ans) return 0;
        int lh = check(root -> left);
        int rh = check(root -> right);
        if (abs(lh - rh) > 1) ans = false;
        return max(lh, rh) + 1;

    }
    bool isBalanced(TreeNode* root) {
        check(root);
        return ans;
    }
};
// @lc code=end

