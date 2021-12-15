/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* res = NULL;
    int maxLevel = 0;
    int lcaDeepestLeavesHelper(TreeNode* root, int level = 0) {
        if (!root) return 0;
        if (!(root -> left) && !(root -> right)) {
            if (level < maxLevel) return 0;
            maxLevel = level;
            res = root;
            return level;
        }
        int l = lcaDeepestLeavesHelper(root -> left, level + 1);
        int r = lcaDeepestLeavesHelper(root -> right, level + 1); 
        if (l == r && l == maxLevel) {
            res = root; 
            return l;
        }
        return l == maxLevel ? l : r == maxLevel ? r : 0;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root, int level = 0) {
        lcaDeepestLeavesHelper(root);
        return res;
    }
};
// @lc code=end

