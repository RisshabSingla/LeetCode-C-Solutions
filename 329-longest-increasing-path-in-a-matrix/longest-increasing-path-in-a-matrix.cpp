class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m, int number){
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }

        if(matrix[i][j] <= number){
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int a = dfs(matrix, dp, i-1, j, n, m, matrix[i][j]);
        int b = dfs(matrix, dp, i+1, j, n, m, matrix[i][j]);
        int c = dfs(matrix, dp, i, j-1, n, m, matrix[i][j]);
        int d = dfs(matrix, dp, i, j+1, n, m, matrix[i][j]);
        return dp[i][j] = max({a,b,c,d})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int length = dfs(matrix, dp, i, j, n,m, -1);
                maxi = max(maxi, length);
            }
        }
        return maxi;
    }
};