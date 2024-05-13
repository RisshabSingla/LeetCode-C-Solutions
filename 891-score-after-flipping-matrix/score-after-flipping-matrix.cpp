class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = (1 << (m - 1)) * n;
        for (int j = 1; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++){
                cur += grid[i][j] == grid[i][0];
            }
            ans += max(cur, n - cur) * (1 << (m - j - 1));
        }
        return ans;
    }
};