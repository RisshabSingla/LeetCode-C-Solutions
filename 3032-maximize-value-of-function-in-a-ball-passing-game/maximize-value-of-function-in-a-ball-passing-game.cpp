class Solution {
public:
    long long findAns(vector<int>&arr, long long k, int index){
        if(k == -1){
            return 0LL;
        }
        return findAns(arr, k-1, arr[index]) + index;
    }


    long long findAns(int node, long long power, long long k, vector<vector<pair<int, long long>>>&dp){
        if(power == -1){
            return 0;
        }
        if( (k & (1LL<<power)) == 0){
            return findAns(node, power-1, k, dp);
        }
        return dp[power][node].second + findAns(dp[power][node].first, power-1, k, dp);
    }

    long long getMaxFunctionValue(vector<int>& arr, long long k) {
        int n = arr.size();
        if(n == 1){
            return 0;
        }

        // Approach 1: Using Recursion -> Stack Space Error
        // long long ans = 0;
        // for(int i = 0; i<n; i++){
        //     long long a = findAns(arr, k, i);
        //     ans = max(a, ans);
        // }
        // return ans;

        // Approach 2: Using DP -> TLE
        // vector<pair<int, long long>> dp(n);
        // for(int i = 0; i<n; i++){
        //     dp[i] = {arr[i], i};
        // }
        // for(int j = 0; j<k; j++){
        //     for(int i = 0; i<n; i++){
        //         dp[i].second+= dp[i].first;
        //         dp[i].first = arr[dp[i].first];
        //     }
        // }
        // long long ans = 0;
        // for(int i = 0; i<n; i++){
        //     ans = max(ans, dp[i].second);
        // }
        // return ans;

        // Approach 3: Using Binary Uplifting

        int m = 40;
        vector<vector<pair<int, long long>>> dp(m , vector<pair<int, long long>>(n));
        for(int i = 0; i<n; i++){
            dp[0][i] = {arr[i], arr[i]};
        }

        for(int i = 1; i<m; i++){
            for(int j = 0; j<n; j++){
                int first = dp[i-1][j].first;
                dp[i][j] = {dp[i-1][first].first, dp[i-1][j].second + dp[i-1][first].second};
            }
        }

        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long res = findAns(i, m-1, k, dp) + i;
            ans = max(ans, res);
        }
        return ans;
    }
};