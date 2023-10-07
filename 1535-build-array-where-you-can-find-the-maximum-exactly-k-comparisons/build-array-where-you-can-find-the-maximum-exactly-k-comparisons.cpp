class Solution {
public:

    const int mod = 1000000007;
    int recursive(int n, int m, int k, int max_elem){
        if(n == 0){
            if(k == 0){
                return 1;
            }
            return 0;
        }
        if(k<0){
            return 0;
        }
        int possible = 0;
        for(int i = 1; i<=m; i++){
            int a;
            if(i>max_elem){
                a = recursive(n-1, m, k-1, i);
            }else{
                a = recursive(n-1, m, k, max_elem);
            }
            possible+= a;
        }
        return possible;
    }


    // int memo(int n, int m, int k, int max_elem, vector<vector<vector<int>>>&dp){
    //     if(n == 0){
    //         if(k == 0){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(k<0){
    //         return 0;
    //     }

    //     if(dp[k][n][max_elem] != -1){
    //         return dp[k][n][max_elem];
    //     }

    //     int possible = 0;
    //     for(int i = 1; i<=m; i++){
    //         int a = 0;
    //         if(i>max_elem){
    //             a = memo(n-1, m, k-1, i,dp);
    //         }else{
    //             a = memo(n-1, m, k, max_elem,dp);
    //         }
    //         (possible+=a)%= mod;
    //     }
    //     return dp[k][n][max_elem] = possible;
    // }


    int dp[52][52][102];
    int memo2(int n, int m, int k, int max_elem){
        if(n == 0){
            if(k == 0){
                return 1;
            }
            return 0;
        }
        if(k<0){
            return 0;
        }

        if(dp[k][n][max_elem] != -1){
            return dp[k][n][max_elem];
        }
        int possible = 0;
        for(int i = 1; i<=m; i++){
            int a = 0;
            if(i>max_elem){
                a = memo2(n-1, m, k-1, i);
            }else{
                a = memo2(n-1, m, k, max_elem);
            }
            (possible+=a)%= mod;
        }
        return dp[k][n][max_elem] = possible;
    }

    int numOfArrays(int n, int m, int k) {
        if(m == k == 1){
            return 1;
        }
        if(m<k){
            // more increments than numbers 
            return 0;
        }

        memset(dp, -1, sizeof(dp));
        return memo2(n,m, k, 0);

        // return recursive(n,m,k, -1);

        // vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(101, -1)));
        // return memo(n,m, k,0, dp);

        // return 0;
    }
};