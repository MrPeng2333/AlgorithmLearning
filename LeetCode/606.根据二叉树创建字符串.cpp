/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string res = "";
        res += to_string(root -> val);
        if (root -> right) {
            if (root -> left) {
                res += "(";
                res += tree2str(root -> left);
                res += ")(";
                res += tree2str(root -> right);
                res += ")";
            } else {
                res += "()(";
                res += tree2str(root -> right);
                res += ")";
            }
        } else {
            if (root -> left) {
                res += "(";
                res += tree2str(root ->left);
                res += ")";
            }
        }
        return res;    
    }
};
// @lc code=end

