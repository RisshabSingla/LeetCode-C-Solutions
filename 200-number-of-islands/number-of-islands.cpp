class Solution {
public:
    void dfs(vector<vector<char>>& grid, int& x, int& y, int& m, int& n) {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (q.size() != 0) {
            pair p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                grid[i - 1][j] = '~';
                q.push({i - 1, j});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                grid[i][j - 1] = '~';
                q.push({i, j - 1});
            }
            if (i + 1 < m && grid[i + 1][j] == '1') {
                grid[i + 1][j] = '~';
                q.push({i + 1, j});
            }

            if (j + 1 < n && grid[i][j + 1] == '1') {
                grid[i][j + 1] = '~';
                q.push({i, j + 1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '~';
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
};