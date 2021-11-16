/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool res = false;
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!q) return p == NULL;
        if (!p) return q == NULL;
        if (p -> val != q -> val) return false;
        return isSame(p -> left, q -> left) && isSame(p -> right, q -> right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (root -> val == subRoot -> val) res = isSame(root, subRoot);
        if (res) return res;
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};
// @lc code=end

