class Solution {
public:
    int minimumDeletions(string str) {
        int n = str.length();
        vector<int> dp(n + 1, 0);
        int bCount = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (str[i - 1] == 'a') {
                dp[i] = min(dp[i] + 1, bCount);
            } else {
                bCount++;
            }
        }
        return dp[n];
    }
};