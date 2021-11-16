/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        TreeNode* t1 = root1;
        TreeNode* t2 = root2;
        while(1) {
            while (t1) {
                s1.push(t1);
                t1 = t1 -> left;
            }
            while (t2) {
                s2.push(t2);
                t2 = t2 -> left;
            }
            if (s1.empty() || s2.empty()) break;
            t1 = s1.top();
            t2 = s2.top();
            if (t1 -> val <= t2 -> val) {
                res.push_back(t1 -> val);
                s1.pop();
                t1 = t1 -> right;
                t2 = NULL;
            } else {
                res.push_back(t2 -> val);
                s2.pop();
                t2 = t2 -> right;
                t1 = NULL;
            }
        }
        while (!s1.empty()) {
            t1 = s1.top();
            s1.pop();
            res.push_back(t1 -> val);
            t1 = t1 -> right;
            while (t1) {
                s1.push(t1);
                t1 = t1 -> left;
            }
        }
        while (!s2.empty()) {
            t2 = s2.top();
            s2.pop();
            res.push_back(t2 -> val);
            t2 = t2 -> right;
            while (t2) {
                s2.push(t2);
                t2 = t2 -> left;
            }
        }
        return res;
    }
};
// @lc code=end

