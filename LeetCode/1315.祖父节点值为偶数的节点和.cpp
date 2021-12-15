/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int sumChildren(TreeNode* root) {
        if (!root) return 0;
        return root -> left && root -> right ? root -> left -> val + root -> right -> val : root -> left ? root -> left -> val : root -> right ? root -> right -> val : 0; 
    }
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        if (!(root -> val % 2)) res = sumChildren(root -> left) + sumChildren(root -> right);
        res += sumEvenGrandparent(root -> left);
        res += sumEvenGrandparent(root -> right);
        return res;
    }
};
// @lc code=end

