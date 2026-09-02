/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> g_vec;
        g_vec.push_back({root->val});

        while (!q.empty()) {
            int n = q.size();
            vector<int> l_vec = {};

            for (int i = 0; i < n; i++) {
                TreeNode* x = q.front();
                q.pop();
                if (x->left != nullptr) {
                    l_vec.push_back(x->left->val);
                    q.push(x->left);
                }
                if (x->right != nullptr) {
                    l_vec.push_back(x->right->val);
                    q.push(x->right);
                }
            }

            if (!l_vec.empty()) {
                g_vec.push_back(l_vec);
            }
        }
        return g_vec;
    }
};