/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* tmp = new TreeNode(val);
            tmp -> left = root;
            return tmp;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            level++;
            int size = q.size();
            if (level == depth - 1) break;
            while (size--) {
                TreeNode* front = q.front();
                q.pop();
                if (front -> left) q.push(front -> left);
                if (front -> right) q.push(front -> right);
            }
        }
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* c1 = new TreeNode(val);
            TreeNode* c2 = new TreeNode(val);
            TreeNode* node = q.front();
            q.pop();
            TreeNode* p1 = node -> left;
            TreeNode* p2 = node -> right;
            node -> left = c1;
            node -> right = c2;
            c1 -> left = p1;
            c2 -> right = p2;
        }
        return root;
    }
};
// @lc code=end

