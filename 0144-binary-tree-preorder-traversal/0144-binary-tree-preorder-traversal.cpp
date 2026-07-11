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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode* root, vector<int>& sol) {
        if (root == nullptr) {
            return;
        }

        sol.push_back(root->val);
        helper(root->left, sol);
        helper(root->right, sol);
    }
};