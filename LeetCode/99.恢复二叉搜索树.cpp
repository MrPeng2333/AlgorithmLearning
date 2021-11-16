/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = NULL;
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root -> left);
        if (pre) {
            if (!first && pre -> val >= root -> val) first = pre;
            if (first && pre -> val >= root -> val) second = root;
        }
        pre = root;
        traverse(root -> right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        if (first && second) {
            int tmp = first -> val;
            first -> val = second -> val;
            second -> val = tmp;
        }
    }
    

};
// @lc code=end

