/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* build(int poEnd, int inStart, int inEnd, vector<int> &inorder, vector<int> &postorder) {
        if (inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[poEnd]);
        int index;
        for (int i = inStart; i <= inEnd; i++)
            if (inorder[i] == root ->val) index = i;
        root -> left = build(poEnd - inEnd + index - 1, inStart, index - 1, inorder, postorder);
        root -> right = build(poEnd - 1, index + 1, inEnd, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
};
// @lc code=end

