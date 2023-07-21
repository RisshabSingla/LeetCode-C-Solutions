class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,1);
        vector<int> count(size,1);
        int maximum = 1;
        

        for(int i = 0; i<size; i++){

            for(int j = 0; j<i;j++){
                if(nums[j] < nums[i] && 1+dp[j] > dp[i]){
                   dp[i] = dp[j] + 1;
                   count[i] = count[j];
                }else if(nums[j] < nums[i] && 1+dp[j] == dp[i]){
                    count[i] += count[j];
                }
            }
            maximum = max(maximum, dp[i]);
        }

        int number = 0;
        for(int i = 0; i<size; i++){
            if(dp[i] == maximum){
                number+=count[i];
            }
        }

        return number;
    }
};