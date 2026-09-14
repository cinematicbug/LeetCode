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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_size = inorder.size();
        unordered_map<int, int> mp;
        int post_root_ind = in_size - 1;
        int in_st = 0;
        int in_end = in_size - 1;

        for (int i = 0; i < in_size; i++) {
            mp[inorder[i]] = i;
        }

        return helper(mp, postorder, post_root_ind, in_st, in_end);
    }

    TreeNode* helper(unordered_map<int, int>& mp, vector<int>& postorder,
                     int& post_root_ind, int in_st, int in_end) {
        if (in_st > in_end) {
            return nullptr;
        }

        int root_val = postorder[post_root_ind--];
        int in_ord_ind = mp[root_val];

        TreeNode* root = new TreeNode(root_val);
        root->right =
            helper(mp, postorder, post_root_ind, in_ord_ind + 1, in_end);
        root->left =
            helper(mp, postorder, post_root_ind, in_st, in_ord_ind - 1);

        return root;
    }
};