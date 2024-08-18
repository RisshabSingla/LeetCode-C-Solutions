class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        int point2 = 0;
        int point3 = 0;
        int point5 = 0;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = min({dp[point2] * 2, dp[point3] * 3, dp[point5] * 5});
            if (dp[i] == dp[point2] * 2) {
                point2++;
            }
            if (dp[i] == dp[point3] * 3) {
                point3++;
            }
            if (dp[i] == dp[point5] * 5) {
                point5++;
            }
        }
        return dp[n - 1];
    }
};