class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        queue<pair<int, int>> q;
        // cout<<"Inserting i: "<<x<<" j: "<<y<<endl;
        q.push({x, y});
        while (q.size() != 0) {
            // cout<<"inside while"<<endl;
            pair p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            // inc[i][j] = true;
            if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                grid[i - 1][j] = '~';
                q.push({i - 1, j});
                // inc[i-1][j] = true;
                // cout<<"Inserting i: "<<i<<" j: "<<j<<endl;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                grid[i][j - 1] = '~';
                q.push({i, j - 1});
                // inc[i][j-1] = true;
                // cout<<"Inserting i: "<<i<<" j: "<<j<<endl;
            }
            if (i + 1 < m && grid[i + 1][j] == '1') {
                grid[i + 1][j] = '~';
                q.push({i + 1, j});
                // inc[i+1][j] = true;
                // cout<<"Inserting i: "<<i<<" j: "<<j<<endl;
            }

            if (j + 1 < n && grid[i][j + 1] == '1') {
                grid[i][j + 1] = '~';
                q.push({i, j + 1});
                // inc[i][j+1] = true;
                // cout<<"Inserting i: "<<i<<" j: "<<j<<endl;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> inc(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '~';
                    // cout<<"Calling DFS for i: "<<i<<" and j: "<<j<<endl;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
};