class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int dirX[] = {0, 0, 1, -1};
        int dirY[] = {1, -1, 0, 0};

        queue<pair<int, int>> q;

        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = INT_MAX;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            int s = grid[x][y];

            for (int i = 0; i < 4; i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    grid[newX][newY] > 1 + s) {
                    grid[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            pair<int, int> pos = pq.top().second;
            int safe = pq.top().first;
            pq.pop();

            if (pos.first == n - 1 && pos.second == n - 1) {
                return safe;
            }
            vis[pos.first][pos.second] = true;
            for (int i = 0; i < 4; i++) {
                int newX = pos.first + dirX[i];
                int newY = pos.second + dirY[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    !vis[newX][newY]) {
                    int s = min(safe, grid[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }
        return -1;
    }
};