/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    unordered_map<int, int> prefix;
    int pathSumHelper(TreeNode* root, int targetSum, int currSum = 0) {
        if (!root) return 0;
        int res = 0;
        currSum += root -> val;
        if (prefix.count(currSum - targetSum)) res = prefix[currSum - targetSum];
        prefix[currSum]++;
        res += pathSumHelper(root -> left, targetSum, currSum) + pathSumHelper(root -> right, targetSum, currSum);
        prefix[currSum]--;
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return pathSumHelper(root, targetSum);
    }
};
// @lc code=end

