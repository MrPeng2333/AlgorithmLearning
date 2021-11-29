/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* genTree(int start, int end, vector<int> &nums) {
        if (start > end) return nullptr;
        int m = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root -> left = genTree(start, m - 1, nums);
        root -> right = genTree(m + 1, end, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (!nums.size()) return nullptr;
        return genTree(0, nums.size() - 1, nums);
    }
};
// @lc code=end

