/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* first = lowestCommonAncestor(root->left, p, q);
        TreeNode* second = lowestCommonAncestor(root->right, p, q);

        if (first != nullptr && second != nullptr) {
            return root;
        }

        if (first != nullptr && second == nullptr) {
            return first;
        }

        return second;
    }
};