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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n - 1, nums);
    }

    TreeNode* helper(int start, int end, vector<int>& arr) {
        int mid = start + (end - start) / 2;
        if (start > end) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(start, mid - 1, arr);
        root->right = helper(mid + 1, end, arr);
        return root;
    }
};