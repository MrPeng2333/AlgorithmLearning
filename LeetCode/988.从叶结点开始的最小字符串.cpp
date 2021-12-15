/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
   
    
    string smallestFromLeaf(TreeNode* root, string s = "") {
        if (!root) return "|";
        s = string(1, 'a' + root -> val) + s;
        return root -> left == root -> right ? s : min(smallestFromLeaf(root -> left, s), smallestFromLeaf(root -> right, s)); 
    }
};
// @lc code=end

