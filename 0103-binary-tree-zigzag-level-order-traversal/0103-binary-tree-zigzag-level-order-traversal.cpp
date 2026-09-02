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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> g_vec;
        q.push(root);
        int lev = 0;
        g_vec.push_back({root->val});

        while (!q.empty()) {
            vector<int> l_vec = {};
            lev++;
            int n = q.size();

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
                if (lev % 2 != 0) {
                    reverse(l_vec.begin(), l_vec.end());
                }
                g_vec.push_back(l_vec);
            }
        }
        return g_vec;
    }
};
;