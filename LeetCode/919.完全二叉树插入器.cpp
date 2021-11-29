/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
class CBTInserter {
public:
    TreeNode* tree[12000];
    int num = 0;
    CBTInserter(TreeNode* root) {
        tree[++num] = root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node -> left) {
                tree[++num] = node -> left;
                q.push(node -> left);
            }
            if (node -> right) {
                tree[++num] = node -> right;
                q.push(node -> right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        tree[++num] = newNode;
        int parIndex = num / 2;
        if (num % 2) 
            tree[parIndex] -> right = newNode;
        else 
            tree[parIndex] -> left = newNode;
        return tree[parIndex] -> val;
    }
    
    TreeNode* get_root() {
        return tree[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

