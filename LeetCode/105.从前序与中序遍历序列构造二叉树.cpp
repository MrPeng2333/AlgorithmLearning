/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildT(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder) {
        if (inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index;
        for (int i = inStart; i <= inEnd; i++) 
            if (inorder[i] == root -> val) index = i;
        root -> left = buildT(preStart + 1, inStart, index - 1, preorder, inorder);
        root -> right = buildT(preStart + index - inStart + 1, index + 1, inEnd, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildT(0, 0, preorder.size() - 1, preorder, inorder);
    }
};
// @lc code=end

