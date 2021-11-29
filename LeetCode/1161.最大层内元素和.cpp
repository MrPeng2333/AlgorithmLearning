/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
   
    int maxLevelSum(TreeNode* root) {
       int res = 16;
       int maxSum = INT_MIN;
       queue<TreeNode*> q;
       q.push(root);
       int level = 0;
       while (!q.empty())
       {
            int size = q.size();
            int levelSum = 0;
            level++;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node -> val;
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            if (levelSum > maxSum) {
                maxSum = levelSum;
                res = level;
            }

       }
       return res;
       
    }
};
// @lc code=end

