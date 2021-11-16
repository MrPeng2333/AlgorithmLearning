/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    
    TreeNode* buildTree(vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[start]);
        int p, i;
        for (i = start + 1; i <= end; i++) {
            if (preorder[i] > preorder[start])
                break;
        }
        p = i;
        root -> left = buildTree(preorder, start + 1, p - 1);
        root -> right = buildTree(preorder, p, end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size() - 1);
    }
};
// @lc code=end

