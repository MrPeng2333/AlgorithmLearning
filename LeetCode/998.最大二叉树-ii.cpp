// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem998.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val > root -> val) {
            TreeNode* node = new TreeNode(val);
            node -> left = root;
            return node;
        }
        root -> right = insertIntoMaxTree(root -> right, val);
        return root;
    }
};
// @lc code=end

