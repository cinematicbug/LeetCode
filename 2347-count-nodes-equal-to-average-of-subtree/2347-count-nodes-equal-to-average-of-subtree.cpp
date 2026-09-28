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
    int count = 0;
    int averageOfSubtree(TreeNode* root) {

        average(root);
        return count;
    }

    pair<int, int> average(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        pair<int, int> left = average(root->left);
        pair<int, int> right = average(root->right);

        int node_sum = left.first + right.first + root->val;
        int node_cnt = left.second + right.second + 1;

        if (root->val == (node_sum / node_cnt)) {
            count++;
        }

        return {node_sum, node_cnt};
    }
};