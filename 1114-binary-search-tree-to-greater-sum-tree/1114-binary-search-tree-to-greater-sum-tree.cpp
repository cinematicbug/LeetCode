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
    int acc = 0;
    TreeNode* bstToGst(TreeNode* root) {
        sum(root);
        return root;
    }

    int sum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        sum(root->right);
        root->val += acc;
        acc = root->val;
        sum(root->left);

        return acc;
    }
};