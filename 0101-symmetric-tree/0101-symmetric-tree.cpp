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
    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return helper(root->left, root->right);
    }

    bool helper(TreeNode* left_node, TreeNode* right_node) {
        if (!left_node && !right_node) {
            return true;
        }

        if ((!left_node && right_node) || (left_node && !right_node) ||
            (right_node->val) != left_node->val) {
            return false;
        }

        return helper(left_node->left, right_node->right) &&
               helper(right_node->left, left_node->right);
    }
};