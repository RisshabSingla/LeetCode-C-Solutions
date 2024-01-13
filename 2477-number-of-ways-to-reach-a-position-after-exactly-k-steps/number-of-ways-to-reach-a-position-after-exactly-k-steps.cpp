class Solution {
public:
    int mod = 1e9+7;
    int dp[4001][1001];
    int tabulation(int curr, int end , int k ){
        if(k == 0){
            if(curr == end){
                return 1;
            }
            return 0;
        }
        if(dp[curr+1000][k]!= -1){
            return dp[curr+1000][k];
        }
        int forward = tabulation(curr+1, end, k-1);
        int back = tabulation(curr-1, end, k-1);
        dp[curr+1000][k] = (forward%mod + back%mod)%mod;
        return dp[curr+1000][k];
    }
    // int memo(int curr, int end, int k){
    //     if(k == 0){
    //         if(curr == end){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp.count({curr, k})){
    //         return dp[{curr,k}];
    //     }
    //     int forward = memo(curr+1, end, k-1);
    //     int back = memo(curr-1, end, k-1);
    //     dp[{curr,k}] = (forward%mod + back%mod)%mod;
    //     return dp[{curr,k}];
    // }
    // int recursive(int curr, int end, int k){
    //     if(k == 0){
    //         if(curr == end){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     int forward = recursive(curr+1, end, k-1);
    //     int back = recursive(curr-1, end, k-1);
    //     return (forward%mod + back%mod)%mod;
    // }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1 ,sizeof(dp));
        return tabulation(startPos, endPos, k);
    }
};