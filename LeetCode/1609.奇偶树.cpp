/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isOdd = true;
        while(!q.empty()) {
            int size = q.size();
            TreeNode* prev = NULL;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                
                if (prev) {
                    if (isOdd && (!(node -> val %2) || node -> val <= prev -> val))
                        return false;
                    else if (!isOdd && ((node -> val % 2) || node -> val >= prev -> val))
                        return false;
                } else {
                    if (isOdd && !(node -> val % 2))
                        return false;
                    else if (!isOdd && node -> val %2)
                        return false;
                }
                prev = node;
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            isOdd = !isOdd;
        }
        return true;
    }
};
// @lc code=end

