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
        ans.push_back(root -> val);
        queue<TreeNode*> q;
        q.push(root);
        int levelNum = 1;
        double nextLevelSum = 0;
        while (!q.empty()) {
            while (levelNum--) {
                TreeNode* front = q.front();
                q.pop();
                if (front -> left) {
                    q.push(front -> left);
                    nextLevelSum += (front -> left -> val);
                    
                }
                if (front -> right) {
                    q.push(front -> right);
                    nextLevelSum += (front -> right -> val);
                    
                }
            }
            if (q.size() > 0) ans.push_back(nextLevelSum / q.size());
            levelNum = q.size();
            nextLevelSum = 0;
        }
        return ans;
    }
};
// @lc code=end

