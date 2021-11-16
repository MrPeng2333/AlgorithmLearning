/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            while (size--) {
                Node* node = q.front();
                q.pop();
                int childNum = (node -> children).size();
                level.push_back(node -> val);
                for (int i = 0; i < childNum; i++) 
                    if (node -> children[i])
                        q.push(node -> children[i]);
            }
            res.push_back(level);
        }
        return res;
    }
    
};
// @lc code=end

