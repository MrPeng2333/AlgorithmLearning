/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    
    int widthOfBinaryTree(TreeNode* root) {
       if(!root) return 0;
       queue<pair<int, TreeNode*>> q;
       q.push({0, root});
       int res = 0;
       while (!q.empty()) {
           int size = q.size();
           int levelEnd;
           int levelStart = q.front().first;
           for (int i = 0; i < size; i++) {
               pair<int, TreeNode*> node = q.front();
               q.pop();
               levelEnd = node.first;
               if (node.second -> left) q.push({(node.first - levelStart) * 2, node.second -> left});
               if (node.second -> right) q.push({(node.first - levelStart) * 2 + 1, node.second -> right});
           }
            res = max(res, levelEnd - levelStart + 1);
       }
       return res;

    }
};
// @lc code=end

