/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    int prevSum = 0;
    void inorderTraversal(TreeNode* root) {
       if (!root) return;
       inorderTraversal(root -> right);
       prevSum += root -> val;
       root -> val = prevSum;
       inorderTraversal(root -> left);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorderTraversal(root);
        return root;
    }
};
// @lc code=end

