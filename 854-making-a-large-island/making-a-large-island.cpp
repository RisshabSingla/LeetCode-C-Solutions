class Solution {
public:
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    int findArea(vector<vector<int>>& grid, int i, int j, int n, int m) {
        int area = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            area++;
            for (int k = 0; k < 4; k++) {
                int x = p.first + dirX[k];
                int y = p.second + dirY[k];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] &&
                    !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& parent, int i,
            int j, int n, int m, int parentIndex) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        if (grid[i][j] == 0 || parent[i][j] != -1) {
            return 0;
        }
        parent[i][j] = parentIndex;

        int a = dfs(grid, parent, i - 1, j, n, m, parentIndex);
        int b = dfs(grid, parent, i + 1, j, n, m, parentIndex);
        int c = dfs(grid, parent, i, j - 1, n, m, parentIndex);
        int d = dfs(grid, parent, i, j + 1, n, m, parentIndex);
        return a + b + c + d + 1;
    }

    int findArea2(vector<vector<int>>& parent,
                  unordered_map<int, int>& parentArea, int i, int j, int n,
                  int m) {
        unordered_set<int> parents;
        if (i - 1 >= 0) {
            parents.insert(parent[i - 1][j]);
        }

        if (i + 1 < n) {
            parents.insert(parent[i + 1][j]);
        }

        if (j + 1 < m) {
            parents.insert(parent[i][j + 1]);
        }

        if (j - 1 >= 0) {
            parents.insert(parent[i][j - 1]);
        }

        int area = 1;
        for (auto& i : parents) {
            area += parentArea[i];
        }

        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> parent(n, vector<int>(m, -1));
        unordered_map<int, int> parentArea;
        int parentIndex = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && parent[i][j] == -1) {
                    int area = dfs(grid, parent, i, j, n, m, parentIndex);
                    parentArea[parentIndex] = area;
                    parentIndex++;
                }
            }
        }

        if(parentIndex == 0){
            return 1;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        if (q.size() == 0) {
            return n * m;
        }
        int maxi = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int area = findArea2(parent, parentArea, x, y, n, m);
            maxi = max(area, maxi);
        }
        return maxi;
    }
};