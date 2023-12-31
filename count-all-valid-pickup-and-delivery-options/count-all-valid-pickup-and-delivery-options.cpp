class Solution {
public:
    int countOrders(int n) {
        // Using Dynamic Programming
        // vector<int> dp(n+1, 0);
        // dp[0] = 1;
        // int mod = 1e9+7;
        // for(int i = 1; i<n ; i++){
        //     long long total_gaps = 2*i + 1;
        //     long long total_ways =  
        //     total_gaps*total_gaps - total_gaps*(total_gaps-1)/2;            
        //     long long a = dp[i-1] * total_ways;
        //     a = a%mod;
        //     dp[i] = a;
        // }
        // return dp[n-1];


        // Not storing the entire array

        int mod = 1e9+7;
        long long prev = 1;
        for(int i = 1; i<n ; i++){
            long long total_gaps = 2*i + 1;
            long long total_ways =  total_gaps*total_gaps -     total_gaps*(total_gaps-1)/2;            
            prev= (prev * total_ways)%mod;
        }
        return prev;


    }
};