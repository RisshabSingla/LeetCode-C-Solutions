class Solution {
public:
    int mod = 1000000007;
    int dfs(vector<vector<int>>& grid , int x, int y, int m, int n ,vector<vector<long long>>& dp ){
        if(dp[x][y]!= -1){
            return dp[x][y];
        }
        
        int ans = 1;
        if(x-1 >=0 &&  grid[x-1][y] < grid[x][y]){
            ans += dfs(grid, x-1, y, m,n,dp);
            ans%= mod;
        }

        if(x+1 < m && grid[x+1][y] < grid[x][y]){
            ans +=dfs(grid, x+1, y,m,n, dp);
            ans%=mod;
        }

        if(y-1>=0 && grid[x][y-1] < grid[x][y]){
            ans += dfs(grid, x, y-1,m,n, dp);
            ans%=mod;
        }
        
        if(y+1 <n && grid[x][y+1] < grid[x][y]){
            ans += dfs(grid, x, y+1,m,n, dp);
            ans%=mod;
        }
        dp[x][y] = ans;
        return dp[x][y];
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<long long>> dp(m, vector<long long> (n,-1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans += dfs(grid, i,j,m,n,dp);
                ans%= mod;
            }
        }

        return ans;

    }
};