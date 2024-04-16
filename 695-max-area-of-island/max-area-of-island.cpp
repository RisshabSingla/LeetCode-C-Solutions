class Solution {
public:
    int dir_x[4] = {-1, 0, 1, 0};
    int dir_y[4] = {0, 1, 0, -1};
    int findArea(vector<vector<int>>& arr, int x, int y, int n, int m) {
        int count = 0;
        arr[x][y] = INT_MAX;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            count++;
            for (int i = 0; i < 4; i++) {
                int new_x = front.first + dir_x[i];
                int new_y = front.second + dir_y[i];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && arr[new_x][new_y] == 1) {
                    q.push({new_x, new_y});
                    arr[new_x][new_y] = INT_MAX;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int count = findArea(grid, i, j, n, m);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};