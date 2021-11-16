/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int levelMax = q.front() -> val;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                levelMax = max(levelMax, front -> val);
                if (front -> left) q.push(front -> left);
                if (front -> right) q.push(front -> right);
            }
            res.push_back(levelMax);
        }
        return res;
    }
};
// @lc code=end

