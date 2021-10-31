/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
class Solution
{
private:
    bool isSame(TreeNode* p, TreeNode* q) {
      if (p == nullptr) return q == nullptr;
      if (q == nullptr) return p == nullptr;
      if (p -> val != q -> val) return false;
      return isSame(p -> left, q -> right) && isSame(p -> right, q -> left);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root -> left);
        q2.push(root -> right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode* f1 = q1.front(); q1.pop();
            TreeNode* f2 = q2.front(); q2.pop();
            if ((f1 == nullptr && f2 != nullptr) || (f1 != nullptr && f2 == nullptr))
                return false;
            if (f1 != nullptr && f2 != nullptr) {
                if (f1 -> val != f2 -> val)
                    return false;
                q1.push(f1 -> left);
                q2.push(f2 -> right);
                q1.push(f1 -> right);
                q2.push(f2 -> left);    
            }            
       }
       return true;

    }
};
// @lc code=end
