/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        stack<TreeNode*> st;
        while (1) {
            while (root) {
                st.push(root);
                root = root -> left;
            }
            if (st.empty()) break;
            root = st.top();
            k--;
            st.pop();
            if (!k) return root -> val;
            root = root -> right;
        }
        return -1;
    }
};
// @lc code=end
