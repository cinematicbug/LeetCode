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
    bool flag = true;
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, flag);
        return root;
    }

    void helper(TreeNode* l, TreeNode* r, bool flag) {
        if (!l || !r) {
            return;
        }

        if (flag) {
            int temp = l->val;
            l->val = r->val;
            r->val = temp;
        }
        helper(l->left, r->right, !flag);
        helper(l->right, r->left, !flag);
    }
};