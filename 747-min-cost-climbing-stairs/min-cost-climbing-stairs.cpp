class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i<=size; i++){
            dp[i] = min(cost[i-1]+ dp[i-1],cost[i-2] + dp[i-2]);
        }
        return dp[size];

    }
};