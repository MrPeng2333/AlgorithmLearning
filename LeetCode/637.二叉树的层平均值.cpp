/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
       vector<double> ans;
       queue<TreeNode*> q;
       double nextSum = 0;
       int curNum = 1;
       ans.push_back(root -> val);
       q.push(root);
       while (!q.empty()) {
           while (curNum--) {
               TreeNode* front = q.front(); q.pop();
               if (front -> left) {
                   q.push(front -> left);
                   nextSum += front -> left -> val;
               }
               if (front -> right) {
                   q.push(front -> right);
                   nextSum += front -> right -> val;
               }
           }
           if (q.size() > 0) ans.push_back(nextSum / q.size());
           nextSum = 0;
           curNum = q.size();
       }
       return ans;
    }
};
// @lc code=end

