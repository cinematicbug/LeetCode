class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dfs_count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                dfs_count += dfs(i, j, rows, cols, grid);
            }
        }
        return dfs_count;
    }

    int dfs(int r, int c, int rows, int cols, vector <vector <char>> &grid)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
        {
            return 0;
        }
        grid[r][c] = '0';
        dfs(r + 1, c, rows, cols, grid);
        dfs(r - 1, c, rows, cols, grid);
        dfs(r, c - 1, rows, cols, grid);
        dfs(r, c + 1, rows, cols, grid);
        return 1;
    }
};