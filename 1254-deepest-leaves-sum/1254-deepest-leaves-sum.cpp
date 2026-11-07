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
    int deepestLeavesSum(TreeNode* root) {

        vector<int> sum;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            sum.clear();

            for (int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                sum.push_back(x->val);

                if (x->left) {
                    q.push(x->left);
                }

                if (x->right) {
                    q.push(x->right);
                }
            }
        }

        return accumulate(sum.begin(), sum.end(), 0);
    }
};