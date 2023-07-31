class Solution {
public:
    // int help(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
    //     if(i<0 || j<0){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     if(s1[i] == s2[j]){
    //         return dp[i][j] = 2*s1[i] + help(i-1,j-1,s1,s2,dp);
    //     }

    //     return dp[i][j] = max( help(i-1,j,s1,s2,dp), help(i,j-1,s1,s2,dp));
    // }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        int totalAsciiSum = 0;
        for(auto &i : s1){
            totalAsciiSum +=i;
        }
        for(auto &i : s2){
            totalAsciiSum += i;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
            
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 2*s1[i-1] + dp[i-1][j-1];
                }else{
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return (totalAsciiSum - dp[n][m]);

    }
};