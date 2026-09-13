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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        if (root == nullptr) {
            return sol;
        }
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        q.push({root, 0});

        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            TreeNode* node = x.first;
            int d = x.second;
            mp[d] = node->val;

            if (node->left != nullptr) {
                q.push({node->left, d + 1});
            }

            if (node->right != nullptr) {
                q.push({node->right, d + 1});
            }
        }

        for (auto x : mp) {
            sol.push_back(x.second);
        }

        return sol;
    }
};