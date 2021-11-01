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
       TreeNode* tmp1 = root;
       TreeNode* tmp2 = root;

        while (1) {
            while (tmp1) {
                s1.push(tmp1);
                tmp1 = tmp1 -> left;
            }
            while (tmp2) {
                s2.push(tmp2);
                tmp2 = tmp2 -> right;
            }
            if (s1.empty() || s2.empty()) break;
            tmp1 = s1.top(); 
            tmp2 = s2.top(); 
            if ((tmp1 -> val + tmp2 -> val) == k && tmp1 != tmp2) return true;
            else if ((tmp1 -> val + tmp2 -> val) < k) {
                s1.pop();
                tmp1 = tmp1 -> right;
                tmp2 = NULL;
            } else {
                s2.pop();
                tmp2 = tmp2 -> left;
                tmp1 = NULL;
            }
        }
        return false;
    }
};
// @lc code=end

