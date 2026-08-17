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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int lev = 0;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            int n = q.size();
            lev++;
            for (int i = 0; i < n; i++) {
                TreeNode* x = q.front();
                q.pop();
                if (x->left != nullptr) {
                    q.push(x->left);
                }
                if (x->right != nullptr) {
                    q.push(x->right);
                }
                if (x->left == nullptr && x->right == nullptr) {
                    return lev;
                }
            }
        }

        return lev;
    }
};