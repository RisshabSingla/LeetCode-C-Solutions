class Solution {
public:
    int getLengthOfOptimalCompression(string str, int k) {
        int n = str.length();
        vector<vector<int>> dp(102, vector<int>(102, 9999)); 
        dp[0][0] = 0; 

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int cnt = 0, del = 0;
                for (int l = i; l >= 1; l--) {
                    if (str[l - 1] == str[i - 1]) 
                        cnt++;
                    else 
                        del++;
                    if (j - del >= 0) {
                        dp[i][j] = min(dp[i][j],
                            dp[l - 1][j - del] + 1 + (cnt >= 100 ? 3 : cnt >= 10 ? 2 : cnt >= 2 ? 1 : 0));
                    }
                }
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        return dp[n][k];
    }
};