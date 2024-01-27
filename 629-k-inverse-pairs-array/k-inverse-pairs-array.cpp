class Solution {
public:
    int mod = 1e9 + 7;
    int dp[10001][1001];
    int solve(int n, int k) {
        if (k == 0) {
            return 1;
        }
        if (n == 0) {
            return 0;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int count = 0;
        for (int i = 0; i <= min(n - 1, k); i++) {
            count += solve(n - 1, k - i);
            count %= mod;
        }
        return dp[n][k] = count;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n,k);
    }
};