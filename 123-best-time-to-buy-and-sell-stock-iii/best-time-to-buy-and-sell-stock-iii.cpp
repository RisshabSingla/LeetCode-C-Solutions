class Solution {
public:

    int recursive(vector<int>& prices, int index, bool canBuy, int transactions){
        if(index == prices.size() || transactions == 0){
            return 0;
        }
        if(canBuy){
            int a = -prices[index] + recursive(prices, index+1, false, transactions);
            int b = recursive(prices, index+1, true, transactions);
            return max(a,b);
        }else{
            int a = prices[index] + recursive(prices, index+1, true, transactions-1);
            int b = recursive(prices, index+1, false, transactions);
            return max(a,b);
        }
        return 0;
    }

    int memoization(vector<int>& prices, int index, int canBuy, int transactions, vector<vector<vector<int>>> &dp){
        if(index == prices.size() || transactions == 0){
            return 0;
        }

        if(dp[index][canBuy][transactions] != INT_MAX){
            return dp[index][canBuy][transactions];
        }

        if(canBuy){
            int a = -prices[index] + memoization(prices, index+1, 0, transactions,dp);
            int b = memoization(prices, index+1, 1, transactions,dp);
            dp[index][canBuy][transactions] = max(a,b);
            return dp[index][canBuy][transactions];
        }else{
            int a = prices[index] + memoization(prices, index+1, 1, transactions-1,dp);
            int b = memoization(prices, index+1, 0, transactions,dp);
            dp[index][canBuy][transactions] = max(a,b);
            return dp[index][canBuy][transactions];
        }

        return 0;
    }


    int tabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap<=2; cap++){
                    if(buy){
                        int a = -prices[index] + dp[index+1][0][cap];
                        int b = dp[index+1][1][cap];
                        dp[index][buy][cap] = max(a,b);
                        // return dp[index][canBuy][transactions];
                    }else{
                        int a = prices[index] + dp[index+1][1][cap-1];
                        int b = dp[index+1][0][cap];
                        dp[index][buy][cap] = max(a,b);
                    }
                }
            }
        }
        return dp[0][1][2];
    }




    int maxProfit(vector<int>& prices) {
        // return recursive(prices, 0, true, 2);


        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, INT_MAX)));
        // return memoization(prices, 0, 1, 2, dp);


        return tabulation(prices);

    }
};