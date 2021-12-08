/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    int findMax(vector<int>& nums, int start, int end) {
        int maxIndex = start;
        for (int i = start; i <= end; i++) 
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        return maxIndex;
        
    }
    TreeNode* constructMBT(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        int index = findMax(nums, start, end);
        TreeNode* root = new TreeNode(nums[index]);
        root -> left = constructMBT(nums, start, index - 1);
        root -> right = constructMBT(nums, index + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMBT(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

