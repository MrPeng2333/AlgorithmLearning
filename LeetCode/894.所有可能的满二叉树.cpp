/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
    vector<vector<TreeNode*>> memo = vector<vector<TreeNode*>>(21);
    vector<TreeNode*> buildFBT(int n) {
        if (memo[n].size()) return memo[n];
        if (n == 1) {
            TreeNode* node = new TreeNode(0);
            memo[1].push_back(node);
            return memo[1];
        }
        for (int i = 1; i < n; i += 2) {
            
            vector<TreeNode*> lTrees = buildFBT(i);
            vector<TreeNode*> rTrees = buildFBT(n - 1 - i);
            for (TreeNode* lTree : lTrees) {
                for (TreeNode* rTree : rTrees) {
                    TreeNode* root = new TreeNode(0);
                    root -> left = lTree;
                    root -> right = rTree;
                    memo[n].push_back(root);
                }
            }
            
        }
        return memo[n];     
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return vector<TreeNode*>();
        return buildFBT(n);
    }
};
// @lc code=end

