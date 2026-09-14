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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        int pre_root_ind = 0;

        int n = inorder.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        int in_start = 0;
        int in_end = n - 1;

        return helper(mp, pre_root_ind, preorder, in_start, in_end);
    }

    TreeNode* helper(unordered_map<int, int>& mp, int& pre_root_ind,
                     vector<int>& preorder, int in_start, int in_end) {

        if (in_start > in_end) {
            return nullptr;
        }
        int root_val = preorder[pre_root_ind++];
        int in_ind = mp[root_val];

        TreeNode* root = new TreeNode(root_val);

        root->left = helper(mp, pre_root_ind, preorder, in_start, in_ind - 1);
        root->right = helper(mp, pre_root_ind, preorder, in_ind + 1, in_end);

        return root;
    }
};