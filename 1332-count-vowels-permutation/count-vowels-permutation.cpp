class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9+7;
        // vector<vector<long>> dp(n, vector<long>(5,0));
        // for(int i = 0; i<5; i++){
        //     dp[0][i] = 1;
        // }
        vector<long> prev(5,1);
        vector<long> next(5,1);
        /*
        a 0 -> e
        e 1 -> a / i
        i 2 -> a / e / o / u
        o 3 -> i / u
        u 4 -> a
        */
        for(int i = 1; i<n; i++){
            next[0] = (((prev[1])%mod + prev[2])%mod + prev[4])%mod;
            next[1] = (prev[0] + prev[2])%mod;
            next[2] = (prev[1] + prev[3])%mod;
            next[3] = (prev[2])%mod;
            next[4] = (prev[2] + prev[3])%mod;
            prev = next;
        }

        int ans = 0;
        for(int i = 0; i<5; i++){
            (ans+= next[i])%=mod;
        }
        return ans;
    }
};