class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

    // Create a set to store stone positions for faster lookup
    unordered_set<int> stoneSet(stones.begin(), stones.end());

    // Create a 2D DP array to store whether it's possible to reach each stone
    vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
    dp[0][1] = true;  
    // Frog starts at the first stone and can jump 1 unit

    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            int diff = stones[i] - stones[j];
            if (diff <= j + 1) {
                // Check if the frog can reach stone j and jump to stone i
                dp[i][diff] = dp[j][diff - 1] || dp[j][diff] || dp[j][diff + 1];
                if (i == n - 1 && dp[i][diff]) {
                    return true;  // Frog can reach the last stone
                }
            }
        }
    }

    return false;
    }
};