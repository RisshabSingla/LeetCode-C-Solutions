class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(i == j){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int minTurns = INT_MAX;

        for(int k = i; k<j; k++){
            int a = solve(i,k,s,dp);
            int b = solve(k+1,j,s,dp);
            minTurns = min(minTurns, a+b);
        }

        if(s[i] == s[j]){
            minTurns--;
        }

        dp[i][j] = minTurns;
        return minTurns;
    }
    int strangePrinter(string s) { 
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0,n-1, s, dp);
    }
};