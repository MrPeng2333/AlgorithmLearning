/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> res;
    int max = 0, cur = 0;
    TreeNode* pre = NULL;
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root -> left);
        if (pre && pre -> val == root -> val) cur++;
        else {
            cur = 1;
            pre = root;
        }
        if (cur == max) {
            res.push_back(root -> val);
        } else if (cur > max) {
            res.clear();
            res.push_back(root -> val);
            max = cur;
        }
        traverse(root -> right);
    }
    vector<int> findMode(TreeNode *root) {
        traverse(root);
        return res;
    }
};
// @lc code=end

