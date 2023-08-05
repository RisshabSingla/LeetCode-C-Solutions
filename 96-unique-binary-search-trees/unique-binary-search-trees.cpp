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


    int dynamic(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            int possible = 0;
            for(int j = 0; j<i; j++){
                possible += dp[j]*dp[i-j-1];
            }
            dp[i] = possible;
        }
        return dp[n];
    }

    int numTrees(int n) {
        // return recursive(n);

        // vector<int> dp(n+1, -1);
        // return memoization(n, dp);

        return dynamic(n);
    }
};