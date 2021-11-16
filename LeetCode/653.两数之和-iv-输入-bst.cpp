/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> s1, s2;
        TreeNode* t1 = root;
        TreeNode* t2 = root;
        while (1) {
            while (t1) {
                s1.push(t1);
                t1 = t1 -> left;
            }
            while (t2) {
                s2.push(t2);
                t2 = t2 -> right;
            }
            if (s1.empty() || s2.empty()) break;
            t1 = s1.top();
            t2 = s2.top();
            int sum = t1 -> val + t2 -> val;
            if (sum == k) {
                if (t1 == t2) return false;
                return true;
            } else if (sum < k) {
                t1 = t1 -> right;
                s1.pop();
                t2 = NULL;
            } else {
                t2 = t2 -> left;
                s2.pop();
                t1 = NULL;
            }
        }
        return false;
    }
};
// @lc code=end

