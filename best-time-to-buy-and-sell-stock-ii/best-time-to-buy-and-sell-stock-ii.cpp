class Solution {
public:
    int maxProfitPossibleMem(vector<int>& prices, int index, bool canBuy , int size, vector<int> &dp){
        if(index == size){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int profit;
        if(canBuy){
            int buyTodayProfit = maxProfitPossible(prices,index+1, false, size) - prices[index]; 
                // now need to sell, since bought today
            int buyFutProfit = maxProfitPossible(prices, index+1, true, size); 
                // will buy in the future;
            profit = max(buyTodayProfit, buyFutProfit);
        }else{
            int sellTodayProfit = maxProfitPossible(prices,index+1, true, size) + prices[index]; 
                // can buy tomorrow because sold today
            int sellFutProfit = maxProfitPossible(prices, index+1, false, size); 
                // will sell in the future;
            profit = max(sellTodayProfit, sellFutProfit);
        }
        dp[index] = profit;
        return dp[index];
    }


    int maxProfitPossible(vector<int>& prices, int index, bool canBuy , int size){
        if(index == size){
            return 0;
        }
        if(canBuy){
            int buyTodayProfit = maxProfitPossible(prices,index+1, false, size) - prices[index]; 
                // now need to sell, since bought today
            int buyFutProfit = maxProfitPossible(prices, index+1, true, size); 
                // will buy in the future;
            int profit = max(buyTodayProfit, buyFutProfit);
            return profit;
        }else{
            int sellTodayProfit = maxProfitPossible(prices,index+1, true, size) + prices[index]; 
                // can buy tomorrow because sold today
            int sellFutProfit = maxProfitPossible(prices, index+1, false, size); 
                // will sell in the future;
            int profit = max(sellTodayProfit, sellFutProfit);
            return profit;
        }
        return 0;
    }

    int maxProfitPossibleTabulation(vector<int>& prices){
        int size = prices.size();
        vector<vector<int>> dp(size+1, vector<int>(2, 0));
        dp[size][0] = dp[size][1] = 0;
        // end case

        for(int index = size-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    // can buy the stock
                    int buyTodayProfit = dp[index+1][0] - prices[index]; 
                    // now need to sell, since bought today
                    int buyFutProfit = dp[index+1][1];
                    // will buy in the future;
                    profit = max(buyTodayProfit, buyFutProfit);
                }else{
                    int sellTodayProfit = dp[index+1][1] + prices[index];
                    int sellFutProfit = dp[index+1][0];
                    profit = max(sellTodayProfit,sellFutProfit);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];

    }


    int maxProfitPossibleTabulationOpt(vector<int> &prices){
        int size = prices.size();
        vector<int> ahead(2,0);
        vector<int> current(2,0);
        ahead[0] = ahead[1] = 0;
        // end case

        for(int index = size-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    // can buy the stock
                    int buyTodayProfit = ahead[0] - prices[index]; 
                    // now need to sell, since bought today
                    int buyFutProfit = ahead[1];
                    // will buy in the future;
                    profit = max(buyTodayProfit, buyFutProfit);
                }else{
                    int sellTodayProfit = ahead[1] + prices[index];
                    int sellFutProfit = ahead[0];
                    profit = max(sellTodayProfit,sellFutProfit);
                }
                current[buy] = profit;
            }
            ahead = current;
        }
        return ahead[1];
    }

    int maxProfit(vector<int>& prices) {
        // Recursive Approach
        // int size = prices.size();
        // return maxProfitPossible(prices, 0, true, size);

        // Memoization Approach
        // int size = prices.size();
        // vector<int> dp(size,-1);
        // return maxProfitPossibleMem(prices, 0, true, size , dp);

        // Tabulation Appraoch
        // return maxProfitPossibleTabulation(prices);


        // Space Optimized Tabulation Approach
        return maxProfitPossibleTabulationOpt(prices);

        // Greedy Approach
        // int profit = 0;
        // int size = prices.size();
        // for(int i = 1; i<size;i++){
        //     int p = prices[i] - prices[i-1];
        //     if(p>0){
        //         profit+=p;
        //     }
        // }
        // return profit;
    }
};