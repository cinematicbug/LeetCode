class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int row_siz = matrix.size();
        int col_siz = matrix[0].size();
        vector<vector<int>> g_vec;
        for (int j = 0; j < col_siz; j++) {
            vector<int> l_vec;
            for (int i = 0; i < row_siz; i++) {
                l_vec.push_back(matrix[i][j]);
            }
            g_vec.push_back(l_vec);
        }

        return g_vec;
    }
};