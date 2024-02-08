class Solution {
public:
    int dp[10002];
    int memo(int n, int number){
        if(n == 0){
            return 0;
        }
        if(n<0){
            return 1e5;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int min_count = 1e5;
        for(int i = number; i<=sqrt(n); i++){
            min_count = min(min_count, memo(n-i*i, i) + 1);
        }

        return dp[n] = min_count;
    }
    int recursion(int n, int number){
        if(n == 0){
            return 0;
        }
        if(n<0){
            return 1e5;
        }
        int min_count = 1e5;
        for(int i = number; i<=sqrt(n); i++){
            min_count = min(min_count, recursion(n-i*i, i) + 1);
        }
        return min_count;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        int min_count = INT_MAX;
        for(int i = 1; i<=sqrt(n); i++){
            min_count = min(min_count, memo(n-i*i, i) + 1);
        }
        return min_count;
    }
};