/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> genTrees(int start, int end) {
       vector<TreeNode*> res;
       if (start > end) {
           res.push_back(nullptr);
           return res;
       }
       if (start == end) {
           res.push_back(new TreeNode(start));
           return res;
       }
       vector<TreeNode*> left, right;
       for (int i = start; i <= end; i++) {
           left = genTrees(start, i - 1);
           right = genTrees(i + 1, end);
           for (TreeNode* lnode : left) {
               for (TreeNode* rnode : right) {
                   TreeNode* root = new TreeNode(i);
                   root -> left = lnode;
                   root -> right = rnode;
                   res.push_back(root);
               }
           }
       }
       return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return vector<TreeNode*>();
        return genTrees(1, n);
    }
};
// @lc code=end

