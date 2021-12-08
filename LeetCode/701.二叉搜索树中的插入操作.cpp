/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    bool isInserted = false;
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (isInserted) return root;
        if (!root) return new TreeNode(val);
        if (val < root -> val) {
            if (root -> left) root -> left = insertIntoBST(root -> left, val);
            else {
                TreeNode* insertedNode = new TreeNode(val);
                root -> left = insertedNode;
                isInserted = true;
            }
        }
        else {
            if (root -> right) root -> right = insertIntoBST(root -> right, val);
            else {
                 TreeNode* insertedNode = new TreeNode(val);
                root -> right = insertedNode;
                isInserted = true;
            }
        }
        return root;
    }
};
// @lc code=end

