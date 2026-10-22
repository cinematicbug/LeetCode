class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }

                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        int time = 0;

        while (!q.empty()) {
            int l = q.size();
            for (int k = 0; k < l; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if ((i - 1) >= 0 && grid[i - 1][j] == 1) {
                    q.push({i - 1, j});
                    grid[i - 1][j] = 2;
                    fresh--;
                }

                if ((i + 1) < m && grid[i + 1][j] == 1) {
                    q.push({i + 1, j});
                    grid[i + 1][j] = 2;
                    fresh--;
                }

                if ((j - 1) >= 0 && grid[i][j - 1] == 1) {
                    q.push({i, j - 1});
                    grid[i][j - 1] = 2;
                    fresh--;
                }

                if ((j + 1) < n && grid[i][j + 1] == 1) {
                    q.push({i, j + 1});
                    grid[i][j + 1] = 2;
                    fresh--;
                }
            }

            time++;
        }

        if (fresh > 0) {
            return -1;
        }

        return time - 1;
    }
};