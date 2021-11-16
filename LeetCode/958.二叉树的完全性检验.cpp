/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        while (!q.empty()) {
            level++;
            int size = q.size();
            if (size != (1 << level)) return false;
            int flag = 0;
            for (int i = 1; i <= size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front -> left) q.push(front -> left);
                else if (!flag) flag = i * 2 - 1;
                if (front -> right) q.push(front -> right);
                else if (!flag) flag = i * 2;
            }
            if (flag) {
                if (q.size() >= flag) return false;
                break;
            }
        }
        while (!q.empty()) {
            if (q.front() -> left || q.front() -> right) return false;
            q.pop();
        }
        return true;
    }
};
// @lc code=end

