class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        // vector<int> dp(size+1, INT_MAX);
        int prev1 = 0;
        int prev2 = 0;
        for(int i = 2; i<=size; i++){
            int t = min(cost[i-1]+ prev1,cost[i-2] + prev2);
            prev2 = prev1;
            prev1 = t;
        }
        return prev1;

    }
};