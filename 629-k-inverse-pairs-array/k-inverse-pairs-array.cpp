class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];
    // int solve(int n, int k) {
    //     if (k == 0) {
    //         return 1;
    //     }
    //     if (n == 0) {
    //         return 0;
    //     }
    //     if(dp[n][k] != -1){
    //         return dp[n][k];
    //     }
    //     int count = 0;
    //     for (int i = 0; i <= min(n - 1, k); i++) {
    //         count += solve(n - 1, k - i);
    //         count %= mod;
    //     }
    //     return dp[n][k] = count;
    // }
    int kInversePairs(int n, int k) {
        // memset(dp, -1, sizeof(dp));
        // return solve(n,k);

        // memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod) % mod;
                }
            }
        }
        return dp[n][k];
    }
};