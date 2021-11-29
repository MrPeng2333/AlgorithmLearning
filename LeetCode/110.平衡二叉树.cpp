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
    int check(TreeNode* root, bool &isBalance) {
       if (!root) return 0;
       if (!isBalance) return 0;
       int lh = check(root -> left, isBalance);
       int rh = check(root -> right, isBalance);
       int diff = abs(lh -rh);
       if (diff > 1) isBalance = false;
       return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool isBalance = true;
        check(root, isBalance);
        return isBalance;
    }
};
// @lc code=end

