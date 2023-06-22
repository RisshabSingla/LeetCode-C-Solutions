class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int size = prices.size();
        for(int i = 1; i<size;i++){
            int p = prices[i] - prices[i-1];
            if(p>0){
                profit+=p;
            }
        }
        return profit;
    }
};