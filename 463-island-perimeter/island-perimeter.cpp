class Solution {
public:
    int countPerimeter(int& x, int& y, int& n, int& m,
                       vector<vector<int>>& grid) {
        int ans = 0;
        if (grid[x][y] == 1) {
            if (x == 0) {
                // left column
                ans++;
            }
            if (x == n - 1) {
                // right column
                ans++;
            }
            if (y == 0) {
                // top row
                ans++;
            }
            if (y == m - 1) {
                // bottom row
                ans++;
            }
            if (x - 1 >= 0 && grid[x - 1][y] == 0) {
                // left side water
                ans++;
            }
            if (x + 1 < n && grid[x + 1][y] == 0) {
                // right side water
                ans++;
            }

            if (y - 1 >= 0 && grid[x][y - 1] == 0) {
                // above water
                ans++;
            }
            if (y + 1 < m && grid[x][y + 1] == 0) {
                // below water
                ans++;
            }
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int a = 0;
        ans += countPerimeter(a, a, n, m, grid);
        visited[0][0] = true;
        int dir_x[] = {-1, 1, 0, 0};
        int dir_y[] = {0, 0, 1, -1};
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.first + dir_x[i];
                int y = p.second + dir_y[i];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (!visited[x][y]) {
                        ans += countPerimeter(x, y, n, m, grid);
                        visited[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
        return ans;
    }
};