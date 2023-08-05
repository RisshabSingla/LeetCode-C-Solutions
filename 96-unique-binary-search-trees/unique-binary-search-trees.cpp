class Solution {
public:
    int memoization(int n, vector<int>&dp){
        if(n<=1){
            return 1;
        }

        if(dp[n]!= -1){
            return dp[n];
        }

        int possible = 0;
        for(int i = 0; i<n; i++){
            int left = memoization(i, dp);
            int right = memoization(n-i-1,dp);
            possible += left*right;
        }
        dp[n] = possible;
        return possible;
    }

    int recursive(int n){
        if(n <= 1){
            // tree with zero or one nodes
            return 1;
        }
        int possible = 0;
        for(int i = 0; i<n; i++){
            int left = recursive(i);
            int right = recursive(n-i-1);
            possible += left*right;
        }
        return possible;

    }
    int numTrees(int n) {
        // return recursive(n);

        vector<int> dp(n+1, -1);
        return memoization(n, dp);
    }
};