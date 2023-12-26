class Solution {
public:
    int dp[31][1001];
    int mod = 1e9+7;
    int memo(int n, int k , int target){
        if(n == 0 && target == 0){
            return 1;
        }
        if(n <= 0 || target <= 0){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int ways = 0;
        for(int i = 1; i<=k;i++){
            ways += memo(n-1, k, target-i);
            ways%= mod;
        }
        dp[n][target] = ways;
        return ways;
    }
    // int recursive(int n, int k , int target){
    //     if(n == 0 && target == 0){
    //         return 1;
    //     }
    //     if(n <= 0 || target <= 0){
    //         return 0;
    //     }
    //     int ways = 0;
    //     for(int i = 1; i<=k;i++){
    //         ways += recursive(n-1, k, target-i);
    //         ways%= mod;
    //     }
    //     return ways;
    // }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1, sizeof(dp));
        // return recursive(n, k, target);
        return memo(n,k,target);
    }
};