class Solution {
public:
    int maxProfitPossibleTabulationOpt(vector<int> &prices, int fee){
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
                    int buyTodayProfit = ahead[0] - prices[index] - fee; 
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
    int maxProfit(vector<int>& prices, int fee) {
        return maxProfitPossibleTabulationOpt(prices, fee);
    }
};