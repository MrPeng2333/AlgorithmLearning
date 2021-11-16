/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int min2val(TreeNode* root, int first) {
       if (!root) return -1;
       if (root -> val != first) return root -> val;
       int l = min2val(root -> left, first);
       int r = min2val(root -> right, first);
       if (l == -1) return r;
       if (r == -1) return l;
       return min(l, r);
    }
    int findSecondMinimumValue(TreeNode* root) { 
        return min2val(root, root -> val);
    }
};
// @lc code=end

