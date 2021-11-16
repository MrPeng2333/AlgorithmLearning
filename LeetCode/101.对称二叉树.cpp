/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool check(TreeNode* p, TreeNode* q) {
        if (!p) return q == NULL;
        if (!q) return p == NULL;
        if (p -> val != q -> val) return false;
        return check(p -> left, q -> right) && check(p -> right, q -> left);
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return check(root -> left, root -> right);
    }
};
// @lc code=end
