/*
 * @lc app=leetcode.cn id=545 lang=cpp
 *
 * [545] 二叉树的边界
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> res;
        stack<TreeNode*> st;
        q.push(root);
        stack<int> rightBoundary;
        vector<int> bottom;
        TreeNode* tmp = root;
        while (1) {
            while (tmp -> left) {
                res.push_back(tmp -> val);
                tmp = tmp -> left;
            }
            res.push_back(tmp -> val);
            if (!(tmp -> right)) break;
            tmp = tmp -> right;

        }
        tmp = root;
        while (1) {
            while (tmp) {
                st.push(tmp);
                tmp = tmp -> left;
            }
            if (st.empty()) break;
            tmp = st.top();
            st.pop();
            if (tmp -> right) tmp = tmp -> right;
            else bottom.push_back(tmp -> val);
        }
        tmp = root;
        while(1) {
            while (tmp -> right) {
                rightBoundary.push(tmp -> val);
                tmp = tmp -> right;
            }
            rightBoundary.push(tmp -> val);
            if (!(tmp -> left)) break;
            tmp = tmp -> left;
        }
        int bottomSize = bottom.size();
        for (int i = 1; i < bottomSize; i++) {
            res.push_back(bottom[i]);
        }
        rightBoundary.pop();
        while (!rightBoundary.empty()) {
            res.push_back(rightBoundary.top());
            rightBoundary.pop();
        }
        return res;

    }
};
// @lc code=end

